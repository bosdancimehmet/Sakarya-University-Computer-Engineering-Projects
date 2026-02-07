import tkinter as tk
from tkinter import scrolledtext, messagebox
import threading
import requests
import re
import webbrowser

class LangflowChatApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Langflow Chat")
        self.root.geometry("800x600")

        # Langflow API ayarları
        self.FLOW_ID = "39b6ada8-6cc2-4c3c-a933-b944f2b09f86"
        self.BASE_URL = f"http://localhost:7860/api/v1/run/{self.FLOW_ID}"
        self.last_message = None  # Son mesajı saklamak için

        # Arayüz oluşturma
        self.create_widgets()
        self.configure_tags()

    def create_widgets(self):
        # Chat history
        self.chat_history = scrolledtext.ScrolledText(
            self.root,
            wrap=tk.WORD,
            width=80,
            height=25,
            state='disabled',
            font=('Arial', 10),
            padx=10,
            pady=10
        )
        self.chat_history.grid(row=0, column=0, columnspan=2, padx=10, pady=10, sticky="nsew")

        # User input
        self.user_input = tk.Entry(self.root, width=70, font=('Arial', 10))
        self.user_input.grid(row=1, column=0, padx=10, pady=10, sticky="ew")
        self.user_input.bind("<Return>", lambda event: self.send_message())

        # Send button
        self.send_button = tk.Button(
            self.root,
            text="Gönder",
            command=self.send_message,
            font=('Arial', 10, 'bold'),
            bg="#4CAF50",
            fg="white"
        )
        self.send_button.grid(row=1, column=1, padx=10, pady=10, sticky="e")

        # Clear button
        self.clear_button = tk.Button(
            self.root,
            text="Temizle",
            command=self.clear_chat,
            font=('Arial', 10),
            bg="#f44336",
            fg="white"
        )
        self.clear_button.grid(row=2, column=0, columnspan=2, pady=5, sticky="ew")

        # Grid yapılandırması
        self.root.grid_rowconfigure(0, weight=1)
        self.root.grid_columnconfigure(0, weight=1)

    def configure_tags(self):
        self.chat_history.tag_config('user', foreground='#1E88E5', font=('Arial', 10, 'bold'))
        self.chat_history.tag_config('bot', foreground='#43A047', font=('Arial', 10))
        self.chat_history.tag_config('system', foreground='#E53935', font=('Arial', 9, 'italic'))
        self.chat_history.tag_config('link', foreground='#6A1B9A', underline=1)

    def send_message(self):
        user_message = self.user_input.get().strip()
        if not user_message:
            return

        self.display_message("Sen: " + user_message, "user")
        self.user_input.delete(0, tk.END)

        # Langflow'a isteği thread'de gönder
        threading.Thread(
            target=self.get_langflow_response,
            args=(user_message,),
            daemon=True
        ).start()

    def get_langflow_response(self, user_message):
        try:
            # Langflow API'ye istek gönder
            payload = {"input_value": user_message}
            headers = {"Content-Type": "application/json"}

            response = requests.post(
                self.BASE_URL,
                json=payload,
                headers=headers
            )

            if response.status_code == 200:
                result = response.json()
                self.process_langflow_response(result)
            else:
                error_msg = f"Hata: API isteği başarısız (Kod: {response.status_code})"
                if response.text:
                    error_msg += f"\nDetay: {response.text[:200]}..."
                self.display_message(error_msg, "system")

        except requests.exceptions.RequestException as e:
            self.display_message(f"Hata: API bağlantı hatası - {str(e)}\n\nLütfen Langflow sunucusunun çalıştığından emin olun.", "system")
        except Exception as e:
            self.display_message(f"Beklenmeyen Hata: {str(e)}", "system")

    def process_langflow_response(self, response_data):
        try:
            # Sadece ilk çıktıyı işle
            if 'outputs' in response_data and len(response_data['outputs']) > 0:
                first_output = response_data['outputs'][0]
                if 'outputs' in first_output and len(first_output['outputs']) > 0:
                    inner_output = first_output['outputs'][0]

                    # Tablo formatındaki çıktıyı bul
                    table_text = ""
                    if 'results' in inner_output:
                        message_data = inner_output['results'].get('message', {})
                        if isinstance(message_data, dict):
                            text = message_data.get('text', '') or message_data.get('data', {}).get('text', '')
                            if text and "Adım No" in text:
                                table_text = self.clean_table(text)

                    # Açıklamaları bul
                    explanation = ""
                    artifacts = inner_output.get('artifacts', {})
                    if isinstance(artifacts, dict) and 'message' in artifacts:
                        msg = artifacts['message']
                        if isinstance(msg, str) and len(msg) > 50:
                            explanation = self.clean_explanation(msg)

                    # Linkleri bul
                    links = ""
                    messages = inner_output.get('messages', [])
                    for msg in messages:
                        if isinstance(msg, dict) and 'message' in msg:
                            message_text = msg['message']
                            if isinstance(message_text, str) and "http" in message_text:
                                links = self.extract_links(message_text)
                                break  # Sadece ilk link grubunu al

                    # Mesajı oluştur
                    bot_message = ""
                    if table_text:
                        bot_message += table_text + "\n\n"
                    if explanation:
                        bot_message += explanation + "\n\n"
                    if links:
                        bot_message += links + "\n"

                    # Aynı mesajı tekrar gösterme
                    if bot_message.strip() != self.last_message:
                        self.display_message("Bot:\n" + bot_message.strip(), "bot")
                        self.last_message = bot_message.strip()
                    return

            self.display_message("Bot: (Yanıt işlenemedi)", "system")

        except Exception as e:
            self.display_message(f"Yanıt işlenirken hata: {str(e)}", "system")

    def clean_table(self, text):
        """Tablodaki fazla boşlukları temizler"""
        lines = [line.strip() for line in text.split('\n') if line.strip()]
        return '\n'.join(lines)

    def clean_explanation(self, text):
        """Açıklamaları temizler ve formatlar"""
        # Başlıkları vurgula
        text = re.sub(r'\*\*(.+?)\*\*', r'【\1】', text)
        # Fazla boşlukları kaldır
        text = re.sub(r'\n\s*\n', '\n\n', text.strip())
        return text

    def extract_links(self, text):
        """Metindeki ilk 3 linki çıkarır"""
        links = re.findall(r'(https?://[^\s]+)', text)[:3]  # Sadece ilk 3 link
        formatted = []
        for i, link in enumerate(links, 1):
            domain = re.sub(r'https?://(www\.)?', '', link).split('/')[0]
            formatted.append(f"{i}. {domain}: {link}")
        return "Kaynaklar:\n" + '\n'.join(formatted)

    def display_message(self, message, sender):
        self.chat_history.config(state='normal')

        # Mesajı ekle
        self.chat_history.insert(tk.END, message + "\n\n", sender)

        # Linkleri özel olarak işaretle
        if sender == "bot":
            self.highlight_links(message)

        self.chat_history.config(state='disabled')
        self.chat_history.see(tk.END)

    def highlight_links(self, text):
        """Metindeki linkleri vurgular"""
        for match in re.finditer(r'(https?://[^\s]+)', text):
            start = self.chat_history.search(match.group(), "1.0", stopindex=tk.END)
            if start:
                end = f"{start}+{len(match.group())}c"
                self.chat_history.tag_add("link", start, end)
                self.chat_history.tag_bind("link", "<Button-1>",
                                           lambda e, url=match.group(): webbrowser.open_new(url))

    def clear_chat(self):
        self.chat_history.config(state='normal')
        self.chat_history.delete(1.0, tk.END)
        self.chat_history.config(state='disabled')
        self.last_message = None  # Chat temizlendiğinde son mesajı sıfırla

if __name__ == "__main__":
    root = tk.Tk()
    app = LangflowChatApp(root)
    root.mainloop()
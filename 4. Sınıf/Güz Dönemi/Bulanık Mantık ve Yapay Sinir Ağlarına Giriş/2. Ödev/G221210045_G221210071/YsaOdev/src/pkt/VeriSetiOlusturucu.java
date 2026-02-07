package pkt;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Random;

public class VeriSetiOlusturucu {

    public static void main(String[] args) {
        // İngilizce format (nokta ile ondalık) için Locale ayarı yapıyoruz
        Locale.setDefault(Locale.US);
        
        int veriSayisi = 4000;
        String dosyaAdi = "dataset.txt";
        
        System.out.println("Veri seti oluşturuluyor... (Etiketli Format)");

        try {
            FileWriter fileWriter = new FileWriter(dosyaAdi);
            PrintWriter printWriter = new PrintWriter(fileWriter);
            Random random = new Random();

            for (int i = 0; i < veriSayisi; i++) {
                // Rastgele Girdiler
                double gelir = random.nextDouble() * 150;
                double gider = random.nextDouble() * 150;
                double nufus = random.nextDouble() * 200;

                try {
                    Bulanik model = new Bulanik(gelir, gider, nufus);
                    double sonucIssizlik = model.getModel().getVariable("issizlikOrani").getValue();

                    //Etiket belirlediğim kısım
                    //Amaç dosyada sözel ifadenin de görünmesi
                    String etiket = "belirsiz";
                    
                    if (sonucIssizlik <= 5.5) etiket = "cokaz";
                    else if (sonucIssizlik <= 8.0) etiket = "az";
                    else if (sonucIssizlik <= 11.0) etiket = "orta";
                    else if (sonucIssizlik <= 16.0) etiket = "yuksek";
                    else etiket = "cokyuksek";
                    
                    // Dosyaya Yazma: Girdiler, Çıktı(Sayı), Çıktı(Etiket)
                    // dataset örnek olarak bu şekilde oluşacak 100.5, 70.2, 80.1, 9.15, orta
                    printWriter.println(String.format("%.4f,%.4f,%.4f,%.4f,%s", 
                            gelir, gider, nufus, sonucIssizlik, etiket));
                    
                } catch (Exception e) {
                    System.out.println("Hata: " + e.getMessage());
                }
                
                if ((i+1) % 1000 == 0) System.out.println((i+1) + " veri üretildi.");
            }

            printWriter.close();
            System.out.println("TAMAMLANDI! dataset.txt güncellendi.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
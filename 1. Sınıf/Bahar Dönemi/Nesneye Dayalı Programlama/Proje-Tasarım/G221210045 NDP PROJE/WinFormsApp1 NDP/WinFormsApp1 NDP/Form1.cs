/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ                                    *
**		 BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                          *
**			 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                                 *
**			   NESNEYE DAYALI PROGLAMLAMA                                   *
**	                                                                        *
**				ÖDEV NUMARASI…………………………………:1 Proje-Tasarým                  *
**				ÖÐRENCÝ ADI………………………………………:Mehmet Bosdancý                  *
**				ÖÐRENCÝ NUMARASI…………………………:G221210045                       *
**				DERS GRUBU…………………………………………:2.Öðretim A Grubu                *
**              YOUTUBE LÝNKÝ…………………………………:https://youtu.be/j3gJ-nlVG68     *
****************************************************************************/
namespace WinFormsApp1_NDP
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.Items.Add("Çember");
            comboBox1.Items.Add("Dikdörtgen");
            comboBox1.Items.Add("Nokta");
            comboBox1.Items.Add("Küre");
            comboBox1.Items.Add("Dikdörtgenler Prizmasý");
            comboBox1.Items.Add("Silindir");
            comboBox1.Items.Add("X-Y yüzeyi");
            comboBox1.Items.Add("Y-Z yüzeyi");
            comboBox1.Items.Add("X-Z yüzeyi yüzeyi");

            comboBox2.Items.Add("Çember");
            comboBox2.Items.Add("Dikdörtgen");
            comboBox2.Items.Add("Nokta");
            comboBox2.Items.Add("Küre");
            comboBox2.Items.Add("Dikdörtgenler Prizmasý");
            comboBox2.Items.Add("Silindir");
        }

        int MerkezNoktaX1;
        int MerkezNoktaY1;
        int MerkezNoktaZ1;
        int Yaricap1;
        int uzunlukX1;
        int uzunlukY1;
        int uzunlukZ1;

        int MerkezNoktaX2;
        int MerkezNoktaY2;
        int MerkezNoktaZ2;
        int Yaricap2;
        int uzunlukX2;
        int uzunlukY2;
        int uzunlukZ2;

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != string.Empty)
            {
                MerkezNoktaX1 = int.Parse(textBox1.Text);
            }
            else
            {
                MerkezNoktaX1 = 0;
            }

            if (textBox2.Text != string.Empty)
            {
                MerkezNoktaY1 = int.Parse(textBox2.Text);
            }
            else
            {
                MerkezNoktaY1 = 0;
            }

            if (textBox3.Text != string.Empty)
            {
                MerkezNoktaZ1 = int.Parse(textBox3.Text);
            }
            else
            {
                MerkezNoktaZ1 = 0;
            }

            if (textBox4.Text != string.Empty)
            {
                Yaricap1 = int.Parse(textBox4.Text);
            }
            else
            {
                Yaricap1 = 0;
            }

            if (textBox5.Text != string.Empty)
            {
                uzunlukX1 = int.Parse(textBox5.Text);
            }
            else
            {
                uzunlukX1 = 0;
            }
            if (textBox6.Text != string.Empty)
            {
                uzunlukY1 = int.Parse(textBox6.Text);
            }
            else
            {
                uzunlukY1 = 0;
            }
            if (textBox7.Text != string.Empty)
            {
                uzunlukZ1 = int.Parse(textBox7.Text);
            }
            else
            {
                uzunlukZ1 = 0;
            }

            if (textBox8.Text != string.Empty)
            {
                MerkezNoktaX2 = int.Parse(textBox8.Text);
            }
            else
            {
                MerkezNoktaX2 = 0;
            }

            if (textBox9.Text != string.Empty)
            {
                MerkezNoktaY2 = int.Parse(textBox9.Text);
            }
            else
            {
                MerkezNoktaY2 = 0;
            }

            if (textBox10.Text != string.Empty)
            {
                MerkezNoktaZ2 = int.Parse(textBox10.Text);
            }
            else
            {
                MerkezNoktaZ2 = 0;
            }

            if (textBox11.Text != string.Empty)
            {
                Yaricap2 = int.Parse(textBox11.Text);
            }
            else
            {
                Yaricap2 = 0;
            }

            if (textBox12.Text != string.Empty)
            {
                uzunlukX2 = int.Parse(textBox12.Text);
            }
            else
            {
                uzunlukX2 = 0;
            }
            if (textBox13.Text != string.Empty)
            {
                uzunlukY2 = int.Parse(textBox13.Text);
            }
            else
            {
                uzunlukY2 = 0;
            }
            if (textBox14.Text != string.Empty)
            {
                uzunlukZ2 = int.Parse(textBox14.Text);
            }
            else
            {
                uzunlukZ2 = 0;
            }

            panel1.Refresh();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

            Point ortanokta = new Point(200, 200);
            Graphics g = panel1.CreateGraphics();

            Pen p3 = new Pen(Color.Black);
            g.DrawLine(p3, 200, 0, 200, 400);
            g.DrawLine(p3, 0, 200, 400, 200);

            float[] dashValues = { 2, 2, 2 };
            Pen blackPen = new Pen(Color.Black);
            blackPen.DashPattern = dashValues;
            e.Graphics.DrawLine(blackPen, new Point(0, 400), new Point(400, 0));

            Pen p1 = new Pen(Color.Blue);
            Pen p2 = new Pen(Color.Red);

            textBox1.Enabled = true;
            textBox2.Enabled = true;
            textBox3.Enabled = true;
            textBox4.Enabled = true;
            textBox5.Enabled = true;
            textBox6.Enabled = true;
            textBox7.Enabled = true;
            textBox8.Enabled = true;
            textBox9.Enabled = true;
            textBox10.Enabled = true;
            textBox11.Enabled = true;
            textBox12.Enabled = true;
            textBox13.Enabled = true;
            textBox14.Enabled = true;

            label21.Visible = false;


            Pen pen1 = new Pen(Color.Green);
            Pen pen2 = new Pen(Color.BlueViolet);

            //çember çember denetimi
            if (comboBox1.SelectedIndex == 0 && comboBox2.SelectedIndex == 0)
            {
                textBox3.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox10.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                //çemberi çizdirin
                e.Graphics.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1, ortanokta.Y - MerkezNoktaY1 - Yaricap1, 2 * Yaricap1, 2 * Yaricap1);

                e.Graphics.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2, ortanokta.Y - MerkezNoktaY2 - Yaricap2, 2 * Yaricap2, 2 * Yaricap2);

                int deltaX, deltaY;
                deltaX = Math.Abs(MerkezNoktaX1 - MerkezNoktaX2);
                deltaY = Math.Abs(MerkezNoktaY1 - MerkezNoktaY2);
                double merkezlerarasimesafe = Math.Sqrt(Math.Pow(deltaX, 2) + Math.Pow(deltaY, 2));
                if (Yaricap1 != 0 && Yaricap2 != 0)
                {
                    if (merkezlerarasimesafe < (Yaricap1 + Yaricap2))
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }
            }

            //dikdörtgen dikdörtgen çarpýþma denetimi
            if (comboBox1.SelectedIndex == 1 && comboBox2.SelectedIndex == 1)
            {
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox7.Enabled = false;
                textBox10.Enabled = false;
                textBox11.Enabled = false;
                textBox14.Enabled = false;

                Graphics Graph = e.Graphics;
                Rectangle A = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2, uzunlukX1, uzunlukY1);
                Graph.DrawRectangle(Pens.Green, A);
                Rectangle B = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2, uzunlukX2, uzunlukY2);
                Graph.DrawRectangle(Pens.BlueViolet, B);

                if (uzunlukX1 != 0 && uzunlukY1 != 0 && uzunlukX2 != 0 && uzunlukY2 != 0)
                {
                    if (Math.Abs(MerkezNoktaX1 - MerkezNoktaX2) < (uzunlukX1 + uzunlukX2) / 2 && Math.Abs(MerkezNoktaY1 - MerkezNoktaY2) < (uzunlukY1 + uzunlukY2) / 2)
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }
            }

            //çember nokta denetimi
            if(comboBox1.SelectedIndex == 0 && comboBox2.SelectedIndex == 2)
            {
                textBox3.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox10.Enabled = false;
                textBox11.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                textBox11.Text = "1";

                e.Graphics.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1, ortanokta.Y - MerkezNoktaY1 - Yaricap1, 2 * Yaricap1, 2 * Yaricap1);

                Pen pen = new Pen(Color.Blue,2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX2 - 1, ortanokta.Y - MerkezNoktaY2 - 1, 2,2);
                if(Yaricap1 != 0)
                {
                    double mesafe;
                    mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX1 - MerkezNoktaX2), 2) + Math.Pow((MerkezNoktaY1 - MerkezNoktaY2), 2));
                    if(mesafe <= Yaricap1)
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }

            }

            //nokta çember denetimi
            if(comboBox1.SelectedIndex == 2 && comboBox2.SelectedIndex == 0)
            {
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox10.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;
                

                textBox4.Text = "1";
                e.Graphics.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2, ortanokta.Y - MerkezNoktaY2 - Yaricap2, 2 * Yaricap2, 2 * Yaricap2);

                Pen pen = new Pen(Color.Blue, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - 1, ortanokta.Y - MerkezNoktaY1 - 1, 2, 2);

                if (Yaricap2 != 0)
                {
                    double mesafe;
                    mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX2 - MerkezNoktaX1), 2) + Math.Pow((MerkezNoktaY2 - MerkezNoktaY1), 2));
                    if (mesafe <= Yaricap2)
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }
            }

            //dikdörtgen nokta denetimi
            if(comboBox1.SelectedIndex == 1 && comboBox2.SelectedIndex == 2)
            {
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox7.Enabled = false;
                textBox10.Enabled = false;
                textBox11.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                textBox11.Text = "1";

                Pen pen = new Pen(Color.Blue, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX2 - 1, ortanokta.Y - MerkezNoktaY2 - 1, 2, 2);

                Graphics Graph = e.Graphics;
                Rectangle A = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2, uzunlukX1, uzunlukY1);
                Graph.DrawRectangle(Pens.Green, A);
                if(textBox5.Text != string.Empty && textBox6.Text != string.Empty)
                {
                    if(MerkezNoktaX2 >= MerkezNoktaX1 - (uzunlukX1 / 2) && MerkezNoktaX2 <= MerkezNoktaX1 + (uzunlukX1 / 2) && MerkezNoktaY2 >= MerkezNoktaY1 - (uzunlukY1/2) && MerkezNoktaY2 <= (MerkezNoktaY1 + (uzunlukY1 / 2)))
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }
            }

            //nokta dikdörtgen çarpýþma denetimi
            if(comboBox1.SelectedIndex == 2 && comboBox2.SelectedIndex == 1)
            {
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox10.Enabled = false;
                textBox11.Enabled = false;
                textBox14.Enabled = false;

                textBox4.Text = "1";

                Pen pen = new Pen(Color.Blue, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - 1, ortanokta.Y - MerkezNoktaY1 - 1, 2, 2);

                Graphics Graph = e.Graphics;
               
                Rectangle B = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2, uzunlukX2, uzunlukY2);
                Graph.DrawRectangle(Pens.BlueViolet, B);

                if (textBox12.Text != string.Empty && textBox13.Text != string.Empty)
                {
                    if (MerkezNoktaX1 >= MerkezNoktaX2 - (uzunlukX2 / 2) && MerkezNoktaX1 <= MerkezNoktaX2 + (uzunlukX2/ 2) && MerkezNoktaY1 >= MerkezNoktaY2 - (uzunlukY2 / 2) && MerkezNoktaY1 <= (MerkezNoktaY2 + (uzunlukY2 / 2)))
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }
            }

            //küre nokta çarpýþma denetimi
            if(comboBox1.SelectedIndex == 3 && comboBox2.SelectedIndex == 2)
            {
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox11.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                textBox11.Text = "1";

                Pen pen = new Pen(Color.Blue, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX2 - 1 - MerkezNoktaZ2/2, ortanokta.Y - MerkezNoktaY2 - 1 +MerkezNoktaZ2/2, 2, 2);

                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - Yaricap1 -MerkezNoktaZ1 /2, ortanokta.Y - MerkezNoktaY1 - Yaricap1/4 + MerkezNoktaZ1/2, 2 * Yaricap1 , Yaricap1/2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 /2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 + MerkezNoktaZ1/2 , 2*Yaricap1 , 2* Yaricap1);

                if(textBox4.Text != string.Empty)
                {
                    double mesafe;
                    mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX2 - MerkezNoktaX1),2) + Math.Pow((MerkezNoktaY2 - MerkezNoktaY1),2) + Math.Pow((MerkezNoktaZ2 - MerkezNoktaZ1),2));

                    if(mesafe <= Yaricap1)
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }
            }

            //nokta küre çarpýþma denetimi
            if(comboBox1.SelectedIndex == 2 && comboBox2.SelectedIndex == 3)
            {
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                textBox4.Text = "1";

                Pen pen = new Pen(Color.Blue, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - 1 -MerkezNoktaZ1/2 , ortanokta.Y - MerkezNoktaY1 - 1 +MerkezNoktaZ1/2, 2, 2);

                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 + MerkezNoktaZ2 / 2, 2 * Yaricap2, 2 * Yaricap2);

                if (textBox11.Text != string.Empty)
                {
                    double mesafe;
                    mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX1 - MerkezNoktaX2), 2) + Math.Pow((MerkezNoktaY1 - MerkezNoktaY2), 2) + Math.Pow((MerkezNoktaZ1 - MerkezNoktaZ2), 2));

                    if (mesafe <= Yaricap2)
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }
            }

            //küre küre çarpýþma denetimi
            if(comboBox1.SelectedIndex == 3 && comboBox2.SelectedIndex == 3)
            {
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                Pen pen = new Pen(Color.Green,2);
                Pen pencil = new Pen(Color.BlueViolet,2);

                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 + MerkezNoktaZ1 / 2, 2 * Yaricap1, 2 * Yaricap1);

                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 + MerkezNoktaZ2 / 2, 2 * Yaricap2, 2 * Yaricap2);

                if(textBox4.Text != string.Empty && textBox11.Text != string.Empty)
                {
                    double mesafe;
                    mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX2 - MerkezNoktaX1),2) + Math.Pow((MerkezNoktaY2 - MerkezNoktaY1),2) + Math.Pow((MerkezNoktaZ2 - MerkezNoktaZ1),2));

                    if(mesafe < (Yaricap1 + Yaricap2))
                    {
                        label21.Visible = true;
                    }
                    else if(mesafe == (Yaricap1 + Yaricap2))
                    {
                        label21.Text = "Çarpýþma Gerçekleþti(Teðet)";
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }

            }

            //çember dikdörtgen çarpýþma denetimi
            if(comboBox1.SelectedIndex == 0 && comboBox2.SelectedIndex == 1)
            {
                textBox3.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox10.Enabled = false;
                textBox11.Enabled = false;
                textBox14.Enabled = false;

                e.Graphics.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1, ortanokta.Y - MerkezNoktaY1 - Yaricap1, 2 * Yaricap1, 2 * Yaricap1);

                Graphics Graph = e.Graphics;
                Rectangle B = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2, uzunlukX2, uzunlukY2);
                Graph.DrawRectangle(Pens.BlueViolet, B);

                if(textBox4.Text != string.Empty && textBox12.Text != string.Empty && textBox13.Text != string.Empty)
                {
                    double mesafe;
                    mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX2 - MerkezNoktaX1),2) + Math.Pow((MerkezNoktaY2 - MerkezNoktaY1),2));
                    int deltaX, deltaY;
                    deltaX = Math.Abs(MerkezNoktaX2 - MerkezNoktaX1);
                    deltaY = Math.Abs(MerkezNoktaY2 - MerkezNoktaY1);

                    // merkez noktasý dikdörtgenin içinde mi
                    if(MerkezNoktaX1 >= MerkezNoktaX2 - (uzunlukX2/2) && MerkezNoktaX1 <= MerkezNoktaX2 + (uzunlukX2/2) && MerkezNoktaY1 >= MerkezNoktaY2 - (uzunlukY2/2) && MerkezNoktaY1 <= (MerkezNoktaY2 + (uzunlukY2/2)))
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        if(mesafe * mesafe > ( deltaX * deltaX + (uzunlukY2 /2 + Yaricap1) * (uzunlukY2 / 2 + Yaricap1)))
                        {
                            label21.Visible = false;
                        }
                        else if(mesafe * mesafe == (deltaX * deltaX + (uzunlukY2 / 2 + Yaricap1) * (uzunlukY2 / 2 + Yaricap1)))
                        {
                            if(MerkezNoktaX1 >= (MerkezNoktaX2 - uzunlukX2 /2) && MerkezNoktaX1 <= (MerkezNoktaX2 + uzunlukX2 /2))
                            {
                                label21.Text = "Çarpýþma Gerçekleþti(Teðet)";
                                label21.Visible = true;
                            }
                        }
                        else if(mesafe * mesafe > (deltaY * deltaY + (uzunlukX2 / 2 + Yaricap1) * (uzunlukX2 / 2 + Yaricap1)))
                        {
                            label21.Visible=false;
                        }
                        else if(mesafe * mesafe == (deltaY * deltaY + (uzunlukX2 / 2 + Yaricap1) * (uzunlukX2 / 2 + Yaricap1)))
                        {
                            if(MerkezNoktaY1 >= (MerkezNoktaY2 - uzunlukY2/2) && MerkezNoktaY1 <= (MerkezNoktaY2 + uzunlukY2/2))
                            {
                                label21.Text = "Çarpýþma Gerçekleþti(Teðet)";
                                label21.Visible = true;
                            }
                        }
                        else
                        {
                            label21.Visible = true;
                        }
                    }

                }
            }

            //dikdörtgen çember çarpýþma denetimi
            if(comboBox1.SelectedIndex == 1 && comboBox2.SelectedIndex == 0)
            {
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox7.Enabled = false;
                textBox10.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                Graphics Graph = e.Graphics;
                Rectangle A = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2, uzunlukX1, uzunlukY1);
                Graph.DrawRectangle(Pens.Green, A);

                e.Graphics.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2, ortanokta.Y - MerkezNoktaY2 - Yaricap2, 2 * Yaricap2, 2 * Yaricap2);

                if(textBox5.Text != string.Empty && textBox6.Text != string.Empty && textBox11.Text != string.Empty)
                {
                    double mesafe;
                    mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX2 - MerkezNoktaX1), 2) + Math.Pow((MerkezNoktaY2 - MerkezNoktaY1), 2));
                    int deltaX, deltaY;
                    deltaX = Math.Abs(MerkezNoktaX2 - MerkezNoktaX1);
                    deltaY = Math.Abs(MerkezNoktaY2 - MerkezNoktaY1);

                    // merkez noktasý dikdörtgenin içinde mi
                    if (MerkezNoktaX2 >= MerkezNoktaX1 - (uzunlukX1 / 2) && MerkezNoktaX2 <= MerkezNoktaX1 + (uzunlukX1 / 2) && MerkezNoktaY2 >= MerkezNoktaY1 - (uzunlukY1 / 2) && MerkezNoktaY2 <= (MerkezNoktaY1 + (uzunlukY1 / 2)))
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        if (mesafe * mesafe > (deltaX * deltaX + (uzunlukY1 / 2 + Yaricap2) * (uzunlukY1 / 2 + Yaricap2)))
                        {
                            label21.Visible = false;
                        }
                        else if (mesafe * mesafe == (deltaX * deltaX + (uzunlukY1 / 2 + Yaricap2) * (uzunlukY1/ 2 + Yaricap2)))
                        {
                            if (MerkezNoktaX2 >= (MerkezNoktaX1 - uzunlukX1 / 2) && MerkezNoktaX2 <= (MerkezNoktaX1 + uzunlukX1/ 2))
                            {
                                label21.Text = "Çarpýþma Gerçekleþti(Teðet)";
                                label21.Visible = true;
                            }
                        }
                        else if (mesafe * mesafe > (deltaY * deltaY + (uzunlukX1 / 2 + Yaricap2) * (uzunlukX1 / 2 + Yaricap2)))
                        {
                            label21.Visible = false;
                        }
                        else if (mesafe * mesafe == (deltaY * deltaY + (uzunlukX1 / 2 + Yaricap2) * (uzunlukX1 / 2 + Yaricap2)))
                        {
                            if (MerkezNoktaY2 >= (MerkezNoktaY1 - uzunlukY1 / 2) && MerkezNoktaY2 <= (MerkezNoktaY1 + uzunlukY1 / 2))
                            {
                                label21.Text = "Çarpýþma Gerçekleþti(Teðet)";
                                label21.Visible = true;
                            }
                        }
                        else
                        {
                            label21.Visible = true;
                        }
                    }
                }
            }

            //silindir silindir çarpýþma denetimi
            if(comboBox1.SelectedIndex == 5 && comboBox2.SelectedIndex == 5)
            {
                textBox5.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox14.Enabled = false;

                //üst elips
                g.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                //alt elips
                g.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen1, new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2 + Yaricap1 / 4)), new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2 + Yaricap1 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen1, new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2 + 2 * Yaricap1), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2 + Yaricap1 / 4)), new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2 + 2 * Yaricap1), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2 + Yaricap1 / 4)));
                //ikinci cisim için
                //üst elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //alt elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));

                if(textBox4.Text != string.Empty && textBox6.Text != string.Empty && textBox11.Text != string.Empty && textBox13.Text != string.Empty)
                {
                    double mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX1 - MerkezNoktaX2),2) + Math.Pow((MerkezNoktaY1 - MerkezNoktaY2),2) + Math.Pow((MerkezNoktaZ1 - MerkezNoktaZ2),2) );

                    if(mesafe < ( Yaricap1 + Yaricap2) && Math.Abs(MerkezNoktaY1 - MerkezNoktaY2) < ((uzunlukY1 + uzunlukY2)/2))
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label2.Visible = false;
                    }
                }
            }

            //nokta silindir çarpýþma denetimi
            if(comboBox1.SelectedIndex == 2 && comboBox2.SelectedIndex == 5)
            {
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox14.Enabled = false;

                textBox4.Text = "1";

                Pen pen = new Pen(Color.Green, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - 1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - 1 + MerkezNoktaZ1 / 2, 2, 2);

                //üst elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //alt elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));

                if (textBox11.Text != string.Empty && textBox13.Text != string.Empty)
                {
                    double mesafe;
                    mesafe = Math.Sqrt((MerkezNoktaX2 - MerkezNoktaX1) * (MerkezNoktaX2 - MerkezNoktaX1) + (MerkezNoktaY2 - MerkezNoktaY1) * (MerkezNoktaY2 - MerkezNoktaY1) + (MerkezNoktaZ2 - MerkezNoktaZ1) * (MerkezNoktaZ2 - MerkezNoktaZ1));
                    if (mesafe <= Yaricap2)
                    {
                        if (MerkezNoktaY1 >= (MerkezNoktaY2 - uzunlukY2 / 2) && MerkezNoktaY1 <= (MerkezNoktaY2 + uzunlukY2 / 2))
                        {
                            label21.Visible = true;
                        }
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }

            }

            //silindir nokta
            if (comboBox1.SelectedIndex == 5 && comboBox2.SelectedIndex == 2)
            {
                textBox5.Enabled = false;
                textBox7.Enabled = false;
                textBox11.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                textBox11.Text = "1";
                Pen pen = new Pen(Color.Green, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX2 - 1 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - 1 + MerkezNoktaZ2 / 2, 2, 2);

                //üst elips
                g.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                //alt elips
                g.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen1, new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2 + Yaricap1 / 4)), new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2 + Yaricap1 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen1, new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2 + 2 * Yaricap1), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2 + Yaricap1 / 4)), new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2 + 2 * Yaricap1), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2 + Yaricap1 / 4)));

                if (textBox4.Text != string.Empty && textBox6.Text != string.Empty)
                {
                    double mesafe;
                    mesafe = Math.Sqrt((MerkezNoktaX1 - MerkezNoktaX2) * (MerkezNoktaX1 - MerkezNoktaX2) + (MerkezNoktaY1 - MerkezNoktaY2) * (MerkezNoktaY1 - MerkezNoktaY2) + (MerkezNoktaZ1 - MerkezNoktaZ2) * (MerkezNoktaZ1 - MerkezNoktaZ2));
                    if (mesafe <= Yaricap1)
                    {
                        if (MerkezNoktaY2 >= (MerkezNoktaY1 - uzunlukY1 / 2) && MerkezNoktaY2 <= (MerkezNoktaY1 + uzunlukY1 / 2))
                        {
                            label21.Visible = true;
                        }
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }

            }

            //küre silindir
            if (comboBox1.SelectedIndex == 3 && comboBox2.SelectedIndex == 5)
            {
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox14.Enabled = false;

                Pen pen = new Pen(Color.Green, 2);

                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 + MerkezNoktaZ1 / 2, 2 * Yaricap1, 2 * Yaricap1);

                //üst elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //alt elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));

                if (textBox4.Text != string.Empty && textBox11.Text != string.Empty && textBox13.Text != string.Empty)
                {
                    double mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX2 - MerkezNoktaX1), 2) + Math.Pow((MerkezNoktaY2 - MerkezNoktaY1), 2) + Math.Pow((MerkezNoktaZ2 - MerkezNoktaZ1), 2));
                    if (mesafe < (Yaricap2 + Yaricap1) && Math.Abs(MerkezNoktaY2 - MerkezNoktaY1) < (uzunlukY2 + Yaricap1) / 2)
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }

            }

            //silindir küre çarpýþma denetimi
            if (comboBox1.SelectedIndex == 5 && comboBox2.SelectedIndex == 3)
            {
                textBox5.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                Pen pencil = new Pen(Color.BlueViolet, 2);

                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 + MerkezNoktaZ2 / 2, 2 * Yaricap2, 2 * Yaricap2);

                //üst elips
                g.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                //alt elips
                g.DrawEllipse(pen1, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen1, new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2 + Yaricap1 / 4)), new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2 + Yaricap1 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen1, new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2 + 2 * Yaricap1), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 - uzunlukY1 / 2 + Yaricap1 / 4)), new Point((ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2 + 2 * Yaricap1), (ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2 + uzunlukY1 / 2 + Yaricap1 / 4)));

                if (textBox4.Text != string.Empty && textBox6.Text != string.Empty && textBox11.Text != string.Empty)
                {
                    double mesafe = Math.Sqrt(Math.Pow((MerkezNoktaX1 - MerkezNoktaX2), 2) + Math.Pow((MerkezNoktaY1 - MerkezNoktaY2), 2) + Math.Pow((MerkezNoktaZ1 - MerkezNoktaZ2), 2));
                    if (mesafe < (Yaricap1 + Yaricap2) && Math.Abs(MerkezNoktaY1 - MerkezNoktaY2) < (uzunlukY1 + Yaricap2) / 2)
                    {
                        label21.Visible = true;
                    }
                    else
                    {
                        label21.Visible = false;
                    }
                }
            }

            //nokta dikdörtgenler prizmasý
            if (comboBox1.SelectedIndex == 2 && comboBox2.SelectedIndex == 4)
            {
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox11.Enabled = false;
                textBox4.Text = "1";

                Pen pen = new Pen(Color.Green, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - 1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - 1 + MerkezNoktaZ1 / 2, 2, 2);




                Rectangle prizma11 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, uzunlukX2, uzunlukY2);
                Rectangle prizma12 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, uzunlukX2, uzunlukY2);

                e.Graphics.DrawRectangle(p1, prizma11);
                e.Graphics.DrawRectangle(p1, prizma12);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);

                if (textBox12.Text != string.Empty && textBox13.Text != string.Empty && textBox14.Text != string.Empty)
                {
                    if (MerkezNoktaX1 >= (MerkezNoktaX2 - uzunlukX2 / 2) && MerkezNoktaX1 <= (MerkezNoktaX2 + uzunlukX2 / 2))
                    {
                        if (MerkezNoktaY1 >= (MerkezNoktaY2 - uzunlukZ2 / 2) && MerkezNoktaY1 <= (MerkezNoktaY2 + uzunlukZ2 / 2))
                        {
                            if (MerkezNoktaZ1 >= (MerkezNoktaZ2 - uzunlukY2 / 2) && MerkezNoktaZ1 <= (MerkezNoktaZ2 + uzunlukY2 / 2))
                            {
                                label21.Visible = true;

                            }
                        }
                    }
                }

            }

            //dikdörtgenler prizmasý ile nokta çarpýþma denenetimi
            if (comboBox1.SelectedIndex == 4 && comboBox2.SelectedIndex == 2)
            {
                textBox4.Enabled = false;
                textBox11.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                textBox11.Text = "1";

                Pen pen = new Pen(Color.Green, 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX2 - 1 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - 1 + MerkezNoktaZ2 / 2, 2, 2);


                Rectangle prizma11 = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, uzunlukX1, uzunlukY1);
                Rectangle prizma12 = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, uzunlukX1, uzunlukY1);

                e.Graphics.DrawRectangle(p1, prizma11);
                e.Graphics.DrawRectangle(p1, prizma12);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);

                if (textBox5.Text != string.Empty && textBox6.Text != string.Empty && textBox7.Text != string.Empty)
                {
                    if (MerkezNoktaX2 >= (MerkezNoktaX1 - uzunlukX1 / 2) && MerkezNoktaX2 <= (MerkezNoktaX1 + uzunlukX1 / 2))
                    {
                        if (MerkezNoktaY2 >= (MerkezNoktaY1 - uzunlukZ1 / 2) && MerkezNoktaY2 <= (MerkezNoktaY1 + uzunlukZ1 / 2))
                        {
                            if (MerkezNoktaZ2 >= (MerkezNoktaZ1 - uzunlukY1 / 2) && MerkezNoktaZ2 <= (MerkezNoktaZ1 + uzunlukY1 / 2))
                            {
                                label21.Visible = true;

                            }
                        }
                    }

                }
            }

            //dikdörtgenler prizmasý ile dikdörtgenler prizmasý çarpýþma denetimi
            if (comboBox1.SelectedIndex == 4 && comboBox2.SelectedIndex == 4)
            {
                textBox4.Enabled = false;
                textBox11.Enabled = false;

                //ilk prizma
                Rectangle prizma1 = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, uzunlukX1, uzunlukY1);
                Rectangle prizma2 = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, uzunlukX1, uzunlukY1);

                e.Graphics.DrawRectangle(p1, prizma1);
                e.Graphics.DrawRectangle(p1, prizma2);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);

                //ikinci prizma
                Rectangle prizma11 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, uzunlukX2, uzunlukY2);
                Rectangle prizma12 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, uzunlukX2, uzunlukY2);

                e.Graphics.DrawRectangle(p1, prizma11);
                e.Graphics.DrawRectangle(p1, prizma12);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);

                if (textBox5.Text != string.Empty && textBox6.Text != string.Empty && textBox7.Text != string.Empty && textBox12.Text != string.Empty && textBox13.Text != string.Empty && textBox14.Text != string.Empty)
                {
                    int deltaX, deltaY, deltaZ;
                    deltaX = Math.Abs(MerkezNoktaX1 - MerkezNoktaX2);
                    deltaY = Math.Abs(MerkezNoktaY1 - MerkezNoktaY2);
                    deltaZ = Math.Abs(MerkezNoktaZ1 - MerkezNoktaZ2);

                    if (deltaX > (uzunlukX1 + uzunlukX2) / 2)
                    {
                        if (deltaY > (uzunlukY1 + uzunlukY2) / 2)
                        {
                            if (deltaZ > (uzunlukZ1 + uzunlukZ2) / 2)
                            {
                                label21.Visible = false;
                            }
                        }
                    }

                    else
                    {
                        label21.Visible = true;
                    }


                }
            }

            //küre dikdörtgenler prizmasý çarpýþma denetimi
            if (comboBox1.SelectedIndex == 3 && comboBox2.SelectedIndex == 4)
            {
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox11.Enabled = false;

                //küre çizimi
                Pen pen = new Pen(Color.Green, 2);

                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 / 4 + MerkezNoktaZ1 / 2, 2 * Yaricap1, Yaricap1 / 2);
                g.DrawEllipse(pen, ortanokta.X + MerkezNoktaX1 - Yaricap1 - MerkezNoktaZ1 / 2, ortanokta.Y - MerkezNoktaY1 - Yaricap1 + MerkezNoktaZ1 / 2, 2 * Yaricap1, 2 * Yaricap1);

                //dikdörtgenler prizmasý çizimi
                Rectangle prizma11 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, uzunlukX2, uzunlukY2);
                Rectangle prizma12 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, uzunlukX2, uzunlukY2);

                e.Graphics.DrawRectangle(p1, prizma11);
                e.Graphics.DrawRectangle(p1, prizma12);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);

                if (textBox4.Text != string.Empty && textBox12.Text != string.Empty && textBox13.Text != string.Empty && textBox14.Text != string.Empty)
                {
                    int deltaX, deltaY, deltaZ;
                    deltaX = Math.Abs(MerkezNoktaX1 - MerkezNoktaX2);
                    deltaY = Math.Abs(MerkezNoktaY1 - MerkezNoktaY2);
                    deltaZ = Math.Abs(MerkezNoktaZ1 - MerkezNoktaZ2);

                    if (deltaX > (Yaricap1 + uzunlukX2 / 2))
                    {
                        if (deltaY > (Yaricap1 + uzunlukY2 / 2))
                        {
                            if (deltaZ > (Yaricap1 + uzunlukZ2 / 2))
                            {
                                label21.Visible = false;
                            }
                        }
                    }

                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //dikdörtgenler prizmasý küre çarpýþma denetimi
            if (comboBox1.SelectedIndex == 4 && comboBox2.SelectedIndex == 3)
            {
                textBox4.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                //prizma çizimi
                Rectangle prizma11 = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, uzunlukX1, uzunlukY1);
                Rectangle prizma12 = new Rectangle(ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, uzunlukX1, uzunlukY1);

                e.Graphics.DrawRectangle(p1, prizma11);
                e.Graphics.DrawRectangle(p1, prizma12);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 - uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 - uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 - uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.X + MerkezNoktaX1 + uzunlukX1 / 2 - MerkezNoktaZ1 / 2 + uzunlukZ1 / 4, ortanokta.Y - MerkezNoktaY1 + uzunlukY1 / 2 + MerkezNoktaZ1 / 2 - uzunlukZ1 / 4);

                //küre çizimi
                Pen pencil = new Pen(Color.BlueViolet, 2);

                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 + MerkezNoktaZ2 / 2, 2 * Yaricap2, 2 * Yaricap2);

                if (textBox5.Text != string.Empty && textBox6.Text != string.Empty && textBox7.Text != string.Empty && textBox11.Text != string.Empty)
                {
                    int deltaX, deltaY, deltaZ;
                    deltaX = Math.Abs(MerkezNoktaX2 - MerkezNoktaX1);
                    deltaY = Math.Abs(MerkezNoktaY2 - MerkezNoktaY1);
                    deltaZ = Math.Abs(MerkezNoktaZ2 - MerkezNoktaZ1);

                    if (deltaX > (Yaricap2 + uzunlukX1 / 2))
                    {
                        if (deltaY > (Yaricap2 + uzunlukY1 / 2))
                        {
                            if (deltaZ > (Yaricap2 + uzunlukZ1 / 2))
                            {
                                label21.Visible = false;
                            }
                        }
                    }

                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //X-Y yüzeyi ile küre çarpýþma denmetimi
            if (comboBox1.SelectedIndex == 6 && comboBox2.SelectedIndex == 3)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(100,100),
                    new Point(300,100),
                    new Point(300,300),
                    new Point(100,300)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //küre çizimi
                Pen pencil = new Pen(Color.BlueViolet, 2);

                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 + MerkezNoktaZ2 / 2, 2 * Yaricap2, 2 * Yaricap2);

                if (textBox11.Text != string.Empty)
                {
                    if (MerkezNoktaZ2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaZ2) != Math.Sign(MerkezNoktaZ2 + Yaricap2))
                        {
                            label21.Visible = true;

                        }
                        else
                        {
                            label21.Visible = false;

                        }
                    }
                    else if (MerkezNoktaZ2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaZ2) != Math.Sign(MerkezNoktaZ2 - Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //Y-Z yüzeyi ile küre çarpýþma denetimi
            if (comboBox1.SelectedIndex == 7 && comboBox2.SelectedIndex == 3)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(100,200),
                    new Point(300,0),
                    new Point(300,200),
                    new Point(100,400)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //küre çizimi
                Pen pencil = new Pen(Color.BlueViolet, 2);

                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 + MerkezNoktaZ2 / 2, 2 * Yaricap2, 2 * Yaricap2);

                if (textBox11.Text != string.Empty)
                {
                    if (MerkezNoktaX2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaX2) != Math.Sign(MerkezNoktaX2 + Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else if (MerkezNoktaX2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaX2) != Math.Sign(MerkezNoktaX2 - Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //X-Z yüzeyi ile küre çarpýþma denetimi
            if (comboBox1.SelectedIndex == 8 && comboBox2.SelectedIndex == 3)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox13.Enabled = false;
                textBox14.Enabled = false;

                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(200,100),
                    new Point(400,100),
                    new Point(200,300),
                    new Point(0,300)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //küre çizimi
                Pen pencil = new Pen(Color.BlueViolet, 2);

                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                g.DrawEllipse(pencil, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 + MerkezNoktaZ2 / 2, 2 * Yaricap2, 2 * Yaricap2);

                if (textBox11.Text != string.Empty)
                {
                    if (MerkezNoktaY2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaY2) != Math.Sign(MerkezNoktaY2 + Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else if (MerkezNoktaY2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaY2) != Math.Sign(MerkezNoktaY2 - Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //X-Y yüzeyi ile Dikdörtgenler prizmasý çarpýþma denetimi
            if (comboBox1.SelectedIndex == 6 && comboBox2.SelectedIndex == 4)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox11.Enabled = false;


                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(100,100),
                    new Point(300,100),
                    new Point(300,300),
                    new Point(100,300)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //dikdörtgenler prizmasý çizimi
                Rectangle prizma11 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, uzunlukX2, uzunlukY2);
                Rectangle prizma12 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, uzunlukX2, uzunlukY2);

                e.Graphics.DrawRectangle(p1, prizma11);
                e.Graphics.DrawRectangle(p1, prizma12);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);

                if (textBox12.Text != string.Empty && textBox13.Text != string.Empty && textBox14.Text != string.Empty)
                {
                    if (MerkezNoktaZ2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaZ2) != Math.Sign(MerkezNoktaZ2 + uzunlukZ2 / 2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else if (MerkezNoktaZ2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaZ2) != Math.Sign(MerkezNoktaZ2 - uzunlukZ2 / 2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //Y-Z yüzeyi ile dikdörtgenler prizmasý çarpýþma denetimi
            if (comboBox1.SelectedIndex == 7 && comboBox2.SelectedIndex == 4)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox11.Enabled = false;


                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(100,200),
                    new Point(300,0),
                    new Point(300,200),
                    new Point(100,400)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //dikdörtgenler prizmasý çizimi
                Rectangle prizma11 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, uzunlukX2, uzunlukY2);
                Rectangle prizma12 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, uzunlukX2, uzunlukY2);

                e.Graphics.DrawRectangle(p1, prizma11);
                e.Graphics.DrawRectangle(p1, prizma12);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);

                if (textBox12.Text != string.Empty && textBox13.Text != string.Empty && textBox14.Text != string.Empty)
                {
                    if (MerkezNoktaX2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaX2) != Math.Sign(MerkezNoktaX2 + uzunlukX2 / 2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else if (MerkezNoktaX2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaX2) != Math.Sign(MerkezNoktaX2 - uzunlukX2 / 2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //X-Z yüzeyi ile dikdörtgenler prizmasý çarpýþma denetimi
            if (comboBox1.SelectedIndex == 8 && comboBox2.SelectedIndex == 4)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox11.Enabled = false;


                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(200,100),
                    new Point(400,100),
                    new Point(200,300),
                    new Point(0,300)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //dikdörtgenler prizmasý çizimi
                Rectangle prizma11 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, uzunlukX2, uzunlukY2);
                Rectangle prizma12 = new Rectangle(ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, uzunlukX2, uzunlukY2);

                e.Graphics.DrawRectangle(p1, prizma11);
                e.Graphics.DrawRectangle(p1, prizma12);

                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 - uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 - uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);
                g.DrawLine(p1, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 - uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.X + MerkezNoktaX2 + uzunlukX2 / 2 - MerkezNoktaZ2 / 2 + uzunlukZ2 / 4, ortanokta.Y - MerkezNoktaY2 + uzunlukY2 / 2 + MerkezNoktaZ2 / 2 - uzunlukZ2 / 4);

                if (textBox12.Text != string.Empty && textBox13.Text != string.Empty && textBox14.Text != string.Empty)
                {
                    if (MerkezNoktaY2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaY2) != Math.Sign(MerkezNoktaY2 + uzunlukY2 / 2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else if (MerkezNoktaY2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaY2) != Math.Sign(MerkezNoktaY2 - uzunlukY2 / 2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //X-Y yüzeyi ile silindir çarpýþma denetimi
            if (comboBox1.SelectedIndex == 6 && comboBox2.SelectedIndex == 5)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox14.Enabled = false;

                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(100,100),
                    new Point(300,100),
                    new Point(300,300),
                    new Point(100,300)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //üst elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //alt elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));

                if (textBox11.Text != string.Empty && textBox13.Text != string.Empty)
                {
                    if (MerkezNoktaZ2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaZ2) != Math.Sign(MerkezNoktaZ2 + Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else if (MerkezNoktaZ2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaZ2) != Math.Sign(MerkezNoktaZ2 - Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //Y-Z yüzeyi ile silindir çarpýþma denetimi
            if (comboBox1.SelectedIndex == 7 && comboBox2.SelectedIndex == 5)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox14.Enabled = false;

                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(100,200),
                    new Point(300,0),
                    new Point(300,200),
                    new Point(100,400)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //üst elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //alt elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));

                if (textBox11.Text != string.Empty && textBox13.Text != string.Empty)
                {
                    if (MerkezNoktaX2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaX2) != Math.Sign(MerkezNoktaX2 + Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else if (MerkezNoktaX2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaX2) != Math.Sign(MerkezNoktaX2 - Yaricap2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

            //X-Z yüzeyi ile silindir çarpýþma denetimi
            if (comboBox1.SelectedIndex == 8 && comboBox2.SelectedIndex == 5)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox7.Enabled = false;
                textBox12.Enabled = false;
                textBox14.Enabled = false;

                Brush brush = new SolidBrush(Color.LightBlue);

                Point[] noktalar = new Point[]
                {
                    new Point(200,100),
                    new Point(400,100),
                    new Point(200,300),
                    new Point(0,300)
                };

                g.FillPolygon(brush, noktalar);
                g.DrawLine(p3, 200, 0, 200, 400);
                g.DrawLine(p3, 0, 200, 400, 200);
                float[] cizgidegeri = { 2, 2, 2 };
                p3.DashPattern = cizgidegeri;
                e.Graphics.DrawLine(p3, new Point(400, 0), new Point(0, 400));

                //üst elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //alt elips
                g.DrawEllipse(pen2, ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2, ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2, 2 * Yaricap2, Yaricap2 / 2);
                //sol tarafdaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));
                //sað taraftaki noktalarý birleþtir
                e.Graphics.DrawLine(pen2, new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 - uzunlukY2 / 2 + Yaricap2 / 4)), new Point((ortanokta.X + MerkezNoktaX2 - Yaricap2 - MerkezNoktaZ2 / 2 + 2 * Yaricap2), (ortanokta.Y - MerkezNoktaY2 - Yaricap2 / 4 + MerkezNoktaZ2 / 2 + uzunlukY2 / 2 + Yaricap2 / 4)));

                if (textBox11.Text != string.Empty && textBox13.Text != string.Empty)
                {
                    if (MerkezNoktaY2 < 0)
                    {
                        if (Math.Sign(MerkezNoktaY2) != Math.Sign(MerkezNoktaY2 + uzunlukY2 / 2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else if (MerkezNoktaY2 > 0)
                    {
                        if (Math.Sign(MerkezNoktaY2) != Math.Sign(MerkezNoktaY2 - uzunlukY2 / 2))
                        {
                            label21.Visible = true;
                        }
                        else
                        {
                            label21.Visible = false;
                        }
                    }
                    else
                    {
                        label21.Visible = true;
                    }
                }
            }

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            panel1.Refresh();

            MerkezNoktaX1 = 0;
            MerkezNoktaY1 = 0;
            MerkezNoktaZ1 = 0;
            Yaricap1 = 0;
            uzunlukX1 = 0;
            uzunlukY1 = 0;
            uzunlukZ1 = 0;

            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
            textBox7.Text = "";

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            panel1.Refresh();

            MerkezNoktaX2 = 0;
            MerkezNoktaY2 = 0;
            MerkezNoktaZ2 = 0;
            Yaricap2 = 0;
            uzunlukX2 = 0;
            uzunlukY2 = 0;
            uzunlukZ2 = 0;

            textBox8.Text = "";
            textBox9.Text = "";
            textBox10.Text = "";
            textBox11.Text = "";
            textBox12.Text = "";
            textBox13.Text = "";
            textBox14.Text = "";
        }
    }
}
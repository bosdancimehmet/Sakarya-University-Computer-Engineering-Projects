package pkt;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Locale;

import org.neuroph.core.NeuralNetwork;
import org.neuroph.core.data.DataSet;
import org.neuroph.core.data.DataSetRow;
import org.neuroph.core.events.LearningEvent;
import org.neuroph.core.events.LearningEventListener;
import org.neuroph.nnet.MultiLayerPerceptron;
import org.neuroph.nnet.learning.BackPropagation;
import org.neuroph.nnet.learning.MomentumBackpropagation;
import org.neuroph.util.TransferFunctionType;

public class YsaUygulamasi {

    private static final double MAX_GELIR = 150.0;
    private static final double MAX_GIDER = 150.0;
    private static final double MAX_NUFUS = 200.0;
    private static final double MAX_ISSIZLIK = 25.0; 

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("\n-----------------------------------------");
            System.out.println("1- Ağı Eğit ve Test Et (Momentumlu)");
            System.out.println("2- Ağı Eğit ve Test Et (Momentumsuz)");
            System.out.println("3- Ağı Eğit Epoch Göster");
            System.out.println("4- Ağı Eğit ve Tekli Test (Momentumlu)");
            System.out.println("5- K-Fold Test");
            System.out.println("0- Çıkış");
            System.out.print("Seçiminiz: ");
            
            int secim = scanner.nextInt();
            
            if (secim == 0) break;
            
            switch (secim) {
                case 1:
                    egitVeTestEtMomentumlu(false);
                    break;
                case 2:
                    egitVeTestEtMomentumsuz();
                    break;
                case 3:
                    egitVeTestEtMomentumlu(true); // true = Epoch göster
                    break;
                case 4:
                    egitVeTekliTest(scanner);
                    break;
                case 5:
                    egitVeKFoldTest(scanner);
                    break;
                default:
                    System.out.println("Geçersiz seçim!");
            }
        }
        scanner.close();
    }

    //1. SEÇENEK: MOMENTUMLU EĞİTİM
    private static void egitVeTestEtMomentumlu(boolean epochGoster) {
        System.out.println("Veri seti yükleniyor (Momentumlu)...");
        DataSet tumVeri = veriSetiniYukle("dataset.txt");
        tumVeri.shuffle();
        
        DataSet egitimSeti = new DataSet(3, 1);
        DataSet testSeti = new DataSet(3, 1);
        int toplamVeri = tumVeri.size();
        int egitimSayisi = (int) (toplamVeri * 0.75);
        
        for (int i = 0; i < toplamVeri; i++) {
            if (i < egitimSayisi) egitimSeti.add(tumVeri.getRowAt(i));
            else testSeti.add(tumVeri.getRowAt(i));
        }
        
        MultiLayerPerceptron sinirAgi = new MultiLayerPerceptron(TransferFunctionType.SIGMOID, 3, 12, 1);
        MomentumBackpropagation learningRule = (MomentumBackpropagation) sinirAgi.getLearningRule();
        learningRule.setLearningRate(0.2);
        learningRule.setMomentum(0.7);
        learningRule.setMaxError(0.0001);
        learningRule.setMaxIterations(5000);
        
        if (epochGoster) {
            learningRule.addListener(new LearningEventListener() {
                @Override
                public void handleLearningEvent(LearningEvent event) {
                    BackPropagation bp = (BackPropagation) event.getSource();
                    int epoch = bp.getCurrentIteration();
                    if (epoch % 100 == 0) { 
                        System.out.println("Epoch: " + epoch + " | Eğitim Hatası: " + bp.getTotalNetworkError());
                    }
                }
            });
        }

        System.out.println("Ağ eğitiliyor...");
        sinirAgi.learn(egitimSeti);
        System.out.println("Eğitim Tamamlandı!");
        System.out.println("Eğitim Hatası (MSE): " + mseHesapla(sinirAgi, egitimSeti));
        System.out.println("Test Hatası (MSE): " + mseHesapla(sinirAgi, testSeti));
    }

    //2. SEÇENEK: MOMENTUMSUZ EĞİTİM
    private static void egitVeTestEtMomentumsuz() {
        System.out.println("Veri seti yükleniyor (Momentumsuz)...");
        DataSet tumVeri = veriSetiniYukle("dataset.txt");
        tumVeri.shuffle();
        
        DataSet egitimSeti = new DataSet(3, 1);
        DataSet testSeti = new DataSet(3, 1);
        int toplamVeri = tumVeri.size();
        int egitimSayisi = (int) (toplamVeri * 0.75);
        for (int i = 0; i < toplamVeri; i++) {
            if (i < egitimSayisi) egitimSeti.add(tumVeri.getRowAt(i));
            else testSeti.add(tumVeri.getRowAt(i));
        }
        
        MultiLayerPerceptron sinirAgi = new MultiLayerPerceptron(TransferFunctionType.SIGMOID, 3, 12, 1);
        BackPropagation learningRule = new BackPropagation();
        sinirAgi.setLearningRule(learningRule);
        learningRule.setLearningRate(0.2);
        learningRule.setMaxError(0.0001);
        learningRule.setMaxIterations(5000);

        System.out.println("Ağ eğitiliyor (Momentumsuz)...");
        sinirAgi.learn(egitimSeti);
        System.out.println("Eğitim Tamamlandı!");
        System.out.println("Eğitim Hatası (MSE): " + mseHesapla(sinirAgi, egitimSeti));
        System.out.println("Test Hatası (MSE): " + mseHesapla(sinirAgi, testSeti));
    }

    //4. SEÇENEK: TEKLİ TEST
    private static void egitVeTekliTest(Scanner scanner) {
        System.out.println("Tüm veri seti ile ağ eğitiliyor (Lütfen bekleyiniz)...");
        DataSet tumVeri = veriSetiniYukle("dataset.txt");
        
        MultiLayerPerceptron sinirAgi = new MultiLayerPerceptron(TransferFunctionType.SIGMOID, 3, 12, 1);
        MomentumBackpropagation learningRule = (MomentumBackpropagation) sinirAgi.getLearningRule();
        learningRule.setLearningRate(0.2);
        learningRule.setMomentum(0.7);
        learningRule.setMaxError(0.0001);
        learningRule.setMaxIterations(5000);//max epoch 
        // --------------------------------
        
        sinirAgi.learn(tumVeri); 
        System.out.println("Eğitim bitti. Şimdi test zamanı!");
        
        System.out.print("Gelir Giriniz (0-150): ");
        double gelir = scanner.nextDouble();
        System.out.print("Gider Giriniz (0-150): ");
        double gider = scanner.nextDouble();
        System.out.print("Nüfus Giriniz (0-200): ");
        double nufus = scanner.nextDouble();
        
        double normGelir = gelir / MAX_GELIR;
        double normGider = gider / MAX_GIDER;
        double normNufus = nufus / MAX_NUFUS;
        
        sinirAgi.setInput(normGelir, normGider, normNufus);
        sinirAgi.calculate();
        double[] sonuc = sinirAgi.getOutput();
        double tahminIssizlik = sonuc[0] * MAX_ISSIZLIK;
        
        System.out.println("--------------------------------");
        System.out.println("Tahmin Edilen İşsizlik Oranı: %" + String.format("%.2f", tahminIssizlik));
        System.out.println("--------------------------------");
    }

    //5. SEÇENEK: K-FOLD CROSS VALIDATION
    private static void egitVeKFoldTest(Scanner scanner) {
        System.out.print("K Değerini Giriniz : ");
        int k = scanner.nextInt();
        
        System.out.println("Veri seti yükleniyor ve karıştırılıyor...");
        DataSet tumVeri = veriSetiniYukle("dataset.txt");
        tumVeri.shuffle();
        
        int toplamVeri = tumVeri.size(); // 4000
        int parcaBoyutu = toplamVeri / k; // 400 k=10 dersek
        
        double toplamEgitimHatasi = 0;
        double toplamTestHatasi = 0;
        
        System.out.println("\n" + k + "-Fold Cross Validation Başlıyor...");
        
        for (int i = 0; i < k; i++) {
            // Her döngüde yeni bir ağ oluştur (Sıfırdan başla)
            DataSet egitimSeti = new DataSet(3, 1);
            DataSet testSeti = new DataSet(3, 1);
            
            // Test aralığını belirle
            int testBaslangic = i * parcaBoyutu;
            int testBitis = testBaslangic + parcaBoyutu;
            
            // Veriyi parçala
            for (int j = 0; j < toplamVeri; j++) {
                DataSetRow satir = tumVeri.getRowAt(j);
                if (j >= testBaslangic && j < testBitis) {
                    testSeti.add(satir); // Bu parça test için
                } else {
                    egitimSeti.add(satir); // Kalanlar eğitim için
                }
            }
            
            // Ağı Eğit
            MultiLayerPerceptron sinirAgi = new MultiLayerPerceptron(TransferFunctionType.SIGMOID, 3, 12, 1);
            MomentumBackpropagation learningRule = (MomentumBackpropagation) sinirAgi.getLearningRule();
            learningRule.setLearningRate(0.2);
            learningRule.setMomentum(0.7);
            learningRule.setMaxError(0.0001);
            learningRule.setMaxIterations(2000); // K-Fold'da biraz daha az epoch yetebilir, hızlanması için
            
            sinirAgi.learn(egitimSeti);
            
            double egitimHatasi = mseHesapla(sinirAgi, egitimSeti);
            double testHatasi = mseHesapla(sinirAgi, testSeti);
            
            toplamEgitimHatasi += egitimHatasi;
            toplamTestHatasi += testHatasi;
            
            System.out.println("Fold " + (i+1) + " -> Eğitim MSE: " + String.format("%.5f", egitimHatasi) + 
                               " | Test MSE: " + String.format("%.5f", testHatasi));
        }
        
        System.out.println("\n---------------- SONUÇLAR ----------------");
        System.out.println("Ortalama Eğitim Hatası: " + (toplamEgitimHatasi / k));
        System.out.println("Ortalama Test Hatası: "   + (toplamTestHatasi / k));
        System.out.println("------------------------------------------");
    }

    private static DataSet veriSetiniYukle(String dosyaAdi) {
        DataSet dataSet = new DataSet(3, 1);
        try {
            File file = new File(dosyaAdi);
            Scanner dosyaOkuyucu = new Scanner(file);
            dosyaOkuyucu.useLocale(Locale.US); 
            
            while (dosyaOkuyucu.hasNextLine()) {
                String satir = dosyaOkuyucu.nextLine();
                if (satir.trim().isEmpty()) continue;
                
                String[] degerler = satir.split(",");
                
                // İlk 4 değer sayıdır (Gelir, Gider, Nüfus, İşsizlik)
                // 5. değer (degerler[4]) etikettir ("yuksek", "az" vb.), onu kullanmıyoruz.
                
                double gelir = Double.parseDouble(degerler[0]);
                double gider = Double.parseDouble(degerler[1]);
                double nufus = Double.parseDouble(degerler[2]);
                double issizlik = Double.parseDouble(degerler[3]);
                
                dataSet.add(new DataSetRow(
                    new double[]{gelir/MAX_GELIR, gider/MAX_GIDER, nufus/MAX_NUFUS}, 
                    new double[]{issizlik/MAX_ISSIZLIK}
                ));
            }
            dosyaOkuyucu.close();
        } catch (FileNotFoundException e) {
            System.out.println("Dosya yok!");
        } catch (Exception e) {
            System.out.println("Veri okuma hatası: " + e.getMessage());
            e.printStackTrace();
        }
        return dataSet;
    }
    
    private static double mseHesapla(NeuralNetwork sinirAgi, DataSet veriSeti) {
        double toplamHata = 0;
        for (DataSetRow satir : veriSeti) {
            sinirAgi.setInput(satir.getInput());
            sinirAgi.calculate();
            double tahmin = sinirAgi.getOutput()[0];
            double gercek = satir.getDesiredOutput()[0];
            toplamHata += Math.pow(gercek - tahmin, 2);
        }
        return toplamHata / veriSeti.size();
    }
}
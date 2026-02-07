package pkt;

import java.net.URISyntaxException;
import java.util.Scanner;
import net.sourceforge.jFuzzyLogic.plot.JFuzzyChart;
import net.sourceforge.jFuzzyLogic.rule.Variable; // Çıktıdaki sadece taralı alan için gerekli
import net.sourceforge.jFuzzyLogic.defuzzifier.DefuzzifierRightMostMax;//RM(right maksimum) metodu için gerekli
import net.sourceforge.jFuzzyLogic.rule.Rule;


public class Test {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		System.out.println("--- İşsizlik Oranı Bulanık Modeli ---");
		
		// 1. Girdi: Gelir (bin TL)
		System.out.print("Gelir (bin TL): ");
		double gelir = in.nextDouble();

		// 2. Girdi: Gider (bin TL)
		System.out.print("Gider (bin TL): ");
		double gider = in.nextDouble();

		// 3. Girdi: Nüfus Sayısı (Milyon Kişi)
		System.out.print("Nüfus Sayısı (milyon): ");
		double nufusSayisi = in.nextDouble();

		in.close();

		try {
			// Bulanik sınıfından nesne oluştur ve girdileri gönder
			Bulanik model = new Bulanik(gelir, gider, nufusSayisi);

			// Sonuçları ekrana yazdırıyoruz toString() metodunu çağırır
			System.out.println("\n" + model);

			//grafiklerin gösterilmesi
			JFuzzyChart.get().chart(model.getModel());


			
			//Sadece taralı(durulaştırılmış) alanın bulunması
			Variable ciktiDegiskeni = model.getModel().getVariable("issizlikOrani");
			JFuzzyChart.get().chart(ciktiDegiskeni, ciktiDegiskeni.getDefuzzifier(), true);
			
			
			// Durulama metodunu RM (Right Most Max) olarak değiştir
			ciktiDegiskeni.setDefuzzifier(new DefuzzifierRightMostMax(ciktiDegiskeni));
			// Modeli tekrar değerlendir (RM metoduyla)
			model.getModel().evaluate();
			double sonucRM = ciktiDegiskeni.getValue();
			System.out.println("RM (Right Maximum) Metodu ile Sonuç: %" + String.format("%.2f", sonucRM));
			
			
			//Çalışan Kuralların gösterilmesi
			System.out.println("\n--- Aktif Olan Kurallar ---");					
			for( Rule r : model.getModel().getFunctionBlock("IssizlikModeli").getFuzzyRuleBlock("kuralBlok").getRules() ) {
				// Sadece desteği 0'dan büyük olan kuralları göster
				if (r.getDegreeOfSupport() > 0) {
					System.out.println(r);
				}
			}
			System.out.println("---------------------------");

		} catch (URISyntaxException e) {
			System.out.println("Model.fcl dosyası bulunurken bir hata oluştu.");
			e.printStackTrace();
		} catch (Exception e) {
			System.out.println("Bulanık mantık modelinde bir hata oluştu.");
			e.printStackTrace();
		}
	}
}
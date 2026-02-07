package pkt;

import java.io.File;
import java.net.URISyntaxException;
import net.sourceforge.jFuzzyLogic.FIS;

public class Bulanik {
	private FIS fis;
	private double gelir;
	private double gider;
	private double nufusSayisi; 

	public Bulanik(double gelir, double gider, double nufusSayisi) throws URISyntaxException {
		this.gelir = gelir;
		this.gider = gider;
		this.nufusSayisi = nufusSayisi; 

		// Model.fcl dosyasını bulup ve yükler
		File modelDosyasi = new File(getClass().getResource("Model.fcl").toURI());
		fis = FIS.load(modelDosyasi.getPath(), true);

		// Girdi değişkenlerini FCL modelindeki isimlerle eşleştir
		fis.setVariable("gelir", this.gelir);
		fis.setVariable("gider", this.gider);
		fis.setVariable("nufusSayisi", this.nufusSayisi); 

		// Modeli Çalıştırılması/Değerlendirilmesi
		fis.evaluate();
	}

	// Sonucu ve girdileri string olarak döndürüyoruz
	@Override
	public String toString() {
		// Çıktı değişkeninin durulaştırılmış değeri
		double issizlikOrani = fis.getVariable("issizlikOrani").getValue();
		
		return "--- Girdi Değerleri ---\n" +
				"Gelir (bin TL): " + this.gelir + "\n" +
				"Gider (bin TL): " + this.gider + "\n" +
				"Nüfus Sayısı (milyon): " + this.nufusSayisi + "\n\n" +
				"--- Sonuç ---" + "\n" +
				"Hesaplanan İşsizlik Oranı(COG): %" + String.format("%.2f", issizlikOrani);
	}

	// Grafikleri çizdirmek için FIS modelini döndüren metodumuz
	public FIS getModel() {
		return fis;
	}
}
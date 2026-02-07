/**
*
* @author Mehmet Bosdancı mehmet.bosdanci@ogr.sakarya.edu.tr
* @since 04.04.2024
* <p>
*  program git deposundan istenilen class'ları getiriyor ve istenilen paradigmaları yapıyor
* </p>
*/
package Program;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.InputStreamReader; // InputStreamReader ve BufferedReader'ı import ediyoruz

public class Program {

	
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // Kullanıcıdan GitHub reposu URL'sini alma işlemi
            System.out.print("GitHub Repository URL'sini girin: ");
            String repositoryUrl = scanner.nextLine();

            // Klonlanacak dizini masaüstü olarak belirliyorum
            String desktopPath = System.getProperty("user.home") + File.separator + "Desktop";
            String cloneDirectory = desktopPath + File.separator + "Pdp_Odev1";

            // Eski klonlanmış dizin varsa siliyorum karışmaması için
            deleteDirectory(new File(cloneDirectory));

            // GitHub deposunu masaüstüne klonlama işlemi
            cloneGitHubRepository(repositoryUrl, cloneDirectory);

            // *.java uzantılı dosyaları al ve sadece sınıf içeren dosyaları işleme yeri
            List<File> classFiles = getJavaFilesWithClasses(new File(cloneDirectory));
            //System.out.println("Sınıf içeren dosyalar:");
            for (File classFile : classFiles) {
                // Burada analiz işlemlerini yap
                analyzeJavaFile(classFile);
            }
        } finally {
            scanner.close();
        }
    }

    private static void cloneGitHubRepository(String repositoryUrl, String cloneDirectory) {
        try {
            ProcessBuilder builder = new ProcessBuilder("git", "clone", repositoryUrl, cloneDirectory);
            Process process = builder.start();

            // İşlem sonuçlarını okuyorum
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                //System.out.println(line);
            }

            int exitCode = process.waitFor();
            if (exitCode == 0) {
                //System.out.println("Repository klonlandı.");
            } else {
                System.out.println("Repository klonlanamadı. Exit code: " + exitCode);
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }


    private static List<File> getJavaFilesWithClasses(File directory) {
        List<File> classFiles = new ArrayList<>();
        if (directory.isDirectory()) {
            File[] files = directory.listFiles();
            if (files != null) {
                for (File file : files) {
                    if (file.isDirectory()) {
                        classFiles.addAll(getJavaFilesWithClasses(file)); // Dizinse, alt dosyalara git
                    } else if (file.getName().endsWith(".java") && containsClass(file)) {
                        // *.java uzantılı ve sınıf içeren dosyaları işle
                        classFiles.add(file);
                    }
                }
            }
        }
        return classFiles;
    }

    private static boolean containsClass(File file) {
        // Dosyanın içeriğinde sınıfın olup olmadığını kontrol et
        try {
            Pattern pattern = Pattern.compile("\\bclass\\b");
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line;
            while ((line = reader.readLine()) != null) {
                Matcher matcher = pattern.matcher(line);
                if (matcher.find()) {
                    return true;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }

    private static void deleteDirectory(File directory) {
        if (directory.isDirectory()) {
            File[] files = directory.listFiles();
            if (files != null) {
                for (File file : files) {
                    deleteDirectory(file);
                }
            }
        }
        directory.delete();
    }

    private static int countLines(String text) {
        String[] lines = text.split("\r\n|\r|\n");
        return lines.length;
    }
    private static void analyzeJavaFile(File file) {
        try {
            int javadocLines = 0;
            int commentLines = 0;
            int codeLines = 0;
            int loc = 0;
            int functionCount = 0;
            int sayac=0;
            int javadocSayacBaslangıc=0;
            int javadocSayacSon=0;
            int yorumSatiriSayacBaslangic = 0;
            int yorumSatiriSayacSon = 0;
            int yorumSatiriylaBaslayanlar = 0;
            int bosSatir = 0;
            int kacAdetJavadocVar = 0;
            int kaccAdetCokluYorumVar = 0;
            int sadeceCokluYorum = 0;
            int onceBoslukSonraYorumSatiriylaBaslayanlar = 0;
            boolean javadocFlag = false;
            boolean yorumSatiriFlag = false;
            boolean inComment = false;

            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line;
            
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                sayac++;
                loc = sayac;
                // Javadoc bloğu başlangıcı
                if (line.startsWith("/**")) {
                    inComment = true;
                    javadocFlag = true;
                    kacAdetJavadocVar++;
                    javadocSayacBaslangıc = sayac;
                } 
                else if(line.startsWith("/*")) {
                	yorumSatiriFlag = true;
                	kaccAdetCokluYorumVar++;
                	yorumSatiriSayacBaslangic = sayac;
                }
                else if (line.startsWith("*/")) {
                    // Javadoc bloğu sonu
                	if(javadocFlag) {
                		inComment = false;
                		javadocFlag = false;
                        javadocSayacSon = sayac;
                        javadocLines += (javadocSayacSon - javadocSayacBaslangıc - 1);
                	}
                	//yorum satiri blok sonu
                    if(yorumSatiriFlag) {
                    	inComment = false;
                    	yorumSatiriFlag = false;
                    	yorumSatiriSayacSon = sayac;
                    	sadeceCokluYorum += (yorumSatiriSayacSon - yorumSatiriSayacBaslangic - 1);
                    	commentLines += (yorumSatiriSayacSon - yorumSatiriSayacBaslangic - 1);
                    }
                    
                } 
                
                else if (line.contains("//")) {
                    // Tek satırlık yorum
                    commentLines++;
                    if (line.startsWith("\\s*//")) {
                        // Tek satırlık yorum
                    	onceBoslukSonraYorumSatiriylaBaslayanlar++;
                    }
                    if (line.startsWith("//")) {
                        // Tek satırlık yorum
                        yorumSatiriylaBaslayanlar++;
                    }
                } 
                
                
                else if (line.isEmpty()) {
                    // Boş satır
                	bosSatir++;
                } 
                
                if (line.matches(".*\\b(public|void|int|char|String|boolean)\\b.*\\(.*")) {
                    functionCount++;
                }



                codeLines = loc - (javadocLines + 2*kacAdetJavadocVar) - bosSatir - (sadeceCokluYorum + 2*kaccAdetCokluYorumVar + yorumSatiriylaBaslayanlar + onceBoslukSonraYorumSatiriylaBaslayanlar);
            }
            reader.close();

            // Formülleri kullanarak yorum sapma yüzdesini hesaplama yeri
            double YG = ((javadocLines + commentLines) * 0.8) / functionCount;
            double YH = (codeLines / (double) functionCount) * 0.3;
            double yorumSapmaYuzdesi = ((double)(100 * YG) / YH) - 100;

            String str;
            double number = 0;
            int sapmaYuzdesi;
            sapmaYuzdesi = (int) yorumSapmaYuzdesi;
            String formalStr;
            double ikiBasamakSayi;
            double pozitifle;

            // Yuvarlama işlemi
            if (sapmaYuzdesi == yorumSapmaYuzdesi) {
                number = (int) yorumSapmaYuzdesi;
            } else {
                if (yorumSapmaYuzdesi < 0) {
                    pozitifle = yorumSapmaYuzdesi * -1;
                    str = Double.toString(pozitifle);
                    String decimalPart = str.substring(0, str.indexOf('.') + 3); // Virgülden önceki kısım + virgülden sonraki 2 basamak
                    String fractionalPart = str.substring(0, str.indexOf('.') + 4); // Virgülden sonraki 3. basamak
                    double binary = Double.parseDouble(decimalPart);
                    double tree = Double.parseDouble(fractionalPart);

                    int length2 = decimalPart.length();
                    // String ifadenin son karakterini int'e çevir
                    int lastDigit2 = Character.getNumericValue(decimalPart.charAt(length2 - 1));
                    int length3 = fractionalPart.length();
                    // String ifadenin son karakterini int'e çevir
                    int lastDigit3 = Character.getNumericValue(fractionalPart.charAt(length3 - 1));

                    if (lastDigit3 > 5) {
                        formalStr = Double.toString(binary + 0.01);
                        ikiBasamakSayi = Double.parseDouble(formalStr);
                        number = -1 * ikiBasamakSayi;
                    } else if (lastDigit3 == 5) {
                        formalStr = Double.toString(binary + 0.01);
                        ikiBasamakSayi = Double.parseDouble(formalStr);
                        number = -1 * ikiBasamakSayi;
                    } else {
                        number = -1 * binary;
                    }
                } else if (yorumSapmaYuzdesi > 0) {
                    str = Double.toString(yorumSapmaYuzdesi);
                    String decimalPart = str.substring(0, str.indexOf('.') + 3); // Virgülden önceki kısım + virgülden sonraki 2 basamak
                    String fractionalPart = str.substring(0, str.indexOf('.') + 4); // Virgülden sonraki 3. basamak
                    double binary = Double.parseDouble(decimalPart);
                    double tree = Double.parseDouble(fractionalPart);

                    int length2 = decimalPart.length();
                    // String ifadenin son karakterini int'e çevir
                    int lastDigit2 = Character.getNumericValue(decimalPart.charAt(length2 - 1));
                    int length3 = fractionalPart.length();
                    // String ifadenin son karakterini int'e çevir
                    int lastDigit3 = Character.getNumericValue(fractionalPart.charAt(length3 - 1));
                    if (lastDigit3 > 5) {
                        number = binary + 0.01;
                    } else if (lastDigit3 == 5) {
                        number = binary + 0.01;
                    } else {
                        number = binary;
                    }
                } else {
                    number = 0;
                }
            }

            // Çıktıyı yazdırıyorum
            System.out.println("Sınıf: " + file.getName());
            System.out.println("Javadoc Satır Sayısı: " + javadocLines);
            System.out.println("Yorum Satır Sayısı: " + (commentLines));
            System.out.println("Kod Satır Sayısı: " + codeLines);
            System.out.println("LOC: " + loc);
            System.out.println("Fonksiyon Sayısı: " + functionCount);
            System.out.printf("Yorum Sapma Yüzdesi: %%%.2f%n", number);
            System.out.println("-----------------------");
            //formatDecimal(yorumSapmaYuzdesi)
        } catch (IOException e) {
            e.printStackTrace();
        }
    }



}

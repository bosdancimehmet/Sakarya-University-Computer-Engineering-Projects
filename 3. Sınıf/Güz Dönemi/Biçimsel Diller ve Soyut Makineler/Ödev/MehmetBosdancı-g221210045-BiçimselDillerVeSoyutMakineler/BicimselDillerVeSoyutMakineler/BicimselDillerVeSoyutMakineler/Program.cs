using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        // Kullanıcıdan durum sayısını alma kısmı
        Console.Write("Durum sayısını girin: ");
        int numStates = int.Parse(Console.ReadLine());

        // Geçiş tablolarını oluşturma işlemi
        int[] gecis0 = new int[numStates];
        int[] gecis1 = new int[numStates];

        Console.WriteLine("\nGeçiş bilgilerini girin:");
        Console.WriteLine("Durum 1 başlangıç durumu olarak kabul edilecektir.");
        for (int i = 0; i < numStates; i++)
        {
            Console.Write($"Durum {i + 1}, 0 ile hangi duruma geçiyor? ");
            gecis0[i] = int.Parse(Console.ReadLine());

            Console.Write($"Durum {i + 1}, 1 ile hangi duruma geçiyor? ");
            gecis1[i] = int.Parse(Console.ReadLine());
        }

        // Kabul durumu sayısını alma işlemi
        Console.Write("\nKaç adet kabul durumu var? ");
        int kabulSayisi = int.Parse(Console.ReadLine());

        // Kabul durumlarını listeye ekliyorum
        List<int> kabulDurumlari = new List<int>();
        for (int i = 0; i < kabulSayisi; i++)
        {
            Console.Write($"Lütfen {i + 1}. kabul durumunu girin: ");
            kabulDurumlari.Add(int.Parse(Console.ReadLine()));
        }

        // Denklik gruplarını hesapla
        var gruplar = DenklikGruplariniHesapla(numStates, gecis0, gecis1, kabulDurumlari);

        // Alt kümeleri kaldırarak son durumları belirle
        gruplar = GruplardanAltKumeSil(gruplar);

        // Geçiş tablosunu oluştur
        var gecisTablosu = GecisTablosunuOlustur(gruplar, gecis0, gecis1);

        // Kabul durumlarını belirle
        var kabulGruplari = GruplardanKabulDurumlari(gruplar, kabulDurumlari);

        // Başlangıç durumunu belirle
        var baslangicDurumu = gruplar.First(g => g.Contains(1));

        // Sonuçları yazdırma kısmı
        Console.WriteLine("\nİndirgenmiş DFA Geçiş Tablosu:");
        foreach (var grup in gecisTablosu)
        {
            var durum = string.Join("", grup.Key.OrderBy(d => d));
            var gecis0Sonraki = string.Join("", grup.Value.Item1.OrderBy(d => d));
            var gecis1Sonraki = string.Join("", grup.Value.Item2.OrderBy(d => d));
            Console.WriteLine($"({durum}, 0) -> ({gecis0Sonraki})");
            Console.WriteLine($"({durum}, 1) -> ({gecis1Sonraki})");
        }

        Console.WriteLine("\nKabul Durumları:");
        foreach (var grup in kabulGruplari)
        {
            Console.WriteLine($"({string.Join("", grup.OrderBy(d => d))})");
        }

        Console.WriteLine($"\nBaşlangıç Durumu: ({string.Join("", baslangicDurumu.OrderBy(d => d))})");
    }

    static List<HashSet<int>> DenklikGruplariniHesapla(int numStates, int[] gecis0, int[] gecis1, List<int> kabulDurumlari)
    {
        // Başlangıçta kabul ve reddeden durumları ayır
        var kabul = new HashSet<int>(kabulDurumlari);
        var red = new HashSet<int>(Enumerable.Range(1, numStates).Except(kabul));

        // Grupları başlat
        var gruplar = new List<HashSet<int>> { kabul, red };

        bool degisim = true;
        while (degisim)
        {
            degisim = false;
            var yeniGruplar = new List<HashSet<int>>();

            foreach (var grup in gruplar)
            {
                var altGruplar = new Dictionary<(int, int), HashSet<int>>();
                foreach (var durum in grup)
                {
                    int gecis0Grubu = gruplar.FindIndex(g => g.Contains(gecis0[durum - 1]));
                    int gecis1Grubu = gruplar.FindIndex(g => g.Contains(gecis1[durum - 1]));
                    var anahtar = (gecis0Grubu, gecis1Grubu);

                    if (!altGruplar.ContainsKey(anahtar))
                        altGruplar[anahtar] = new HashSet<int>();

                    altGruplar[anahtar].Add(durum);
                }

                yeniGruplar.AddRange(altGruplar.Values);
                if (altGruplar.Count > 1) degisim = true;
            }

            gruplar = yeniGruplar;
        }

        return gruplar;
    }

    static List<HashSet<int>> GruplardanAltKumeSil(List<HashSet<int>> gruplar)
    {
        return gruplar
            .OrderByDescending(grup => grup.Count)
            .Where(grup => !gruplar.Any(diger => diger != grup && diger.IsSupersetOf(grup)))
            .ToList();
    }

    static Dictionary<HashSet<int>, (HashSet<int>, HashSet<int>)> GecisTablosunuOlustur(
        List<HashSet<int>> gruplar, int[] gecis0, int[] gecis1)
    {
        var tablo = new Dictionary<HashSet<int>, (HashSet<int>, HashSet<int>)>();

        foreach (var grup in gruplar)
        {
            var gecis0Sonraki = new HashSet<int>();
            var gecis1Sonraki = new HashSet<int>();

            foreach (var durum in grup)
            {
                gecis0Sonraki.UnionWith(gruplar.First(g => g.Contains(gecis0[durum - 1])));
                gecis1Sonraki.UnionWith(gruplar.First(g => g.Contains(gecis1[durum - 1])));
            }

            tablo[grup] = (gecis0Sonraki, gecis1Sonraki);
        }

        return tablo;
    }

    static List<HashSet<int>> GruplardanKabulDurumlari(List<HashSet<int>> gruplar, List<int> kabulDurumlari)
    {
        return gruplar.Where(grup => grup.Any(kabulDurumlari.Contains)).ToList();
    }
}

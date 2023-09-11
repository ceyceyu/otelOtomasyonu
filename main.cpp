#include <iostream> // stringleri kullabilmek içim
#include <fstream>
#include <string>
#include<time.h>
#include<list>
#include <random>
using namespace std;
class otel{
    int sayac;
    int toplam;
    int cevap;
    int odaNumarasi;
    int kalinacakGunSayisi;
    int ucret;
    string musteriAdi , musteriSoyadi;
    int musteriTC;
    int rezervasyonluTC;
    int guncellenmisUcret;


public:
    otel();
    void Isletme();
    void denizOdaRezervasyonu();
    void karaOdaRezervasyonu();
    void rezervasyonBilgileri();
    void odaBosaltma();
    void odaGuncelleme();
    int odaNumasiVarMi();
};
otel::otel(){
    toplam = 0;
    sayac = 0;
    Isletme();
}

void otel::Isletme()
{
    do
    {


        cout << "---PREMIUM ISLAND OTELE HOŞGELDİNİZ---" << endl; cout << endl;
        cout << "   1.Deniz Manzarali Oda Rezervasyonu Yapma " << endl;
        cout << "   2.Kara Manzarali Oda Rezervasyonu Yapma  " << endl;
        cout << "   3.Rezervasyon bilgileri " << endl;
        cout << "   4.Oda boşaltma " << endl;
        cout << "   5.Rezervasyon güncelleme " << endl;
        cout << "   6.Çıkış " << endl;
        cin >> cevap;

        system("cls");

        switch (cevap)
        {
        case 1: denizOdaRezervasyonu();
            break;
        case 2: karaOdaRezervasyonu();
            break;
        case 3: rezervasyonBilgileri();
            break;
        case 4: odaBosaltma();
            break;
        case 5:odaNumasiVarMi();
            break;
        case 6:
            exit(1);

        default: cout << "Yanlış seçim yaptınız ! " << endl;
            break;
        }
        cout << endl;

    } while (cevap != 6);
}
void otel::karaOdaRezervasyonu()
{
    //// rezervasyon yapma kısmı ////
    cout << endl;

    cout << "   Rezervasyon sahibinin : " << endl;
    cout << endl;
    cout << "   Adı: ";
    cin >> musteriAdi;

    cout << "   Soyadı: ";
    cin >> musteriSoyadi;

    cout << "   TC Kimlik Numarasi: ";
    cin >> musteriTC;


    cout << endl;
    cout << "   Kaç gün kalmak istiyorsunuz ? ";
    cin >> kalinacakGunSayisi;
    cout << endl;

    cout << " Oda Ucreti Gunluk 7.650tl "<< endl;
    ucret = kalinacakGunSayisi*7650;
    cout<< "  Odemeniz Gereken Ucret: " << ucret << endl;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        odaNumarasi = rand() % 16 + 1;
    }


    ofstream karaEkle("musteri_bilgileri.txt", ios::app);

    karaEkle << endl << odaNumarasi << "\t" << musteriAdi << "\t" << musteriSoyadi << "\t" << musteriTC << "\t" << toplam;

        karaEkle.close();
}

int otel::odaNumasiVarMi(){
        //cout<<"gelen random sayi:"<<rand<<endl;
        //int numaralar [10] ={};

        int rand=random(17,32);
        list<int> numaralar;

        ifstream oku("musteri_bilgileri.txt");

        while (!oku.eof())
        {
            oku >> odaNumarasi >> musteriAdi >> musteriSoyadi >> musteriTC >> toplam;
        //cout<<"oda numaralari:"<<odaNumarasi<<endl;
        numaralar.push_back(odaNumarasi);
        }
        oku.close();
        //std::copy(std::begin(numaralar), std::end(numaralar),std::ostream_iterator<int>(std::cout, " "));

        bool found = (std::find(numaralar.begin(), numaralar.end(), rand) != numaralar.end());
        return rand;
}

std::random_device rd;
std::mt19937 gen(rd());

int random(int low, int high)
{
        std::uniform_int_distribution<> dist(low, high);
        return dist(gen);
}

void otel::denizOdaRezervasyonu()
{
    //// rezervasyon yapma kısmı ////
    cout << endl;

    cout << "   Rezervasyon sahibinin : " << endl;
    cout << endl;
    cout << "   Adı: ";
    cin >> musteriAdi;

    cout << "   Soyadı: ";
    cin >> musteriSoyadi;

    cout << "   TC Kimlik Numarasi: ";
    cin >> musteriTC;


    cout << endl;
    cout << "   Kaç gün kalmak istiyorsunuz ? ";
    cin >> kalinacakGunSayisi;
    cout << endl;

    cout << "   Oda Ucreti Gunluk 11.250tl "<< endl;
    ucret = kalinacakGunSayisi*11250;
    cout<< "    Odemeniz Gereken Ucret: " << ucret << endl;

    odaNumarasi=odaNumasiVarMi();
    cout<<"odamız var mı ki"<<odaVarMi;

    ofstream denizEkle("musteri_bilgileri.txt", ios::app);

    denizEkle << endl << odaNumarasi << "\t" << musteriAdi << "\t" << musteriSoyadi << "\t" << musteriTC << "\t" << ucret;

    denizEkle.close();
}

void otel::rezervasyonBilgileri()
{
    int bulma = 0;

    cout << "Rezervasyon yapan kisinin TC Kimlik Numarasi neydi? : ";
    cin >> rezervasyonluTC;

    ifstream oku("musteri_bilgileri.txt");

    while (!oku.eof())
    {
        oku >> odaNumarasi >> musteriAdi >> musteriSoyadi >> musteriTC >> toplam;
        cout<<odaNumarasi;
        if (rezervasyonluTC == musteriTC)
        {
            bulma = 1;
            cout << endl << "--- Oda no: " << odaNumarasi ; cout << endl;
            cout << "--- Ad    : " << musteriAdi; cout << endl;
            cout << "--- Soyad : " << musteriSoyadi; cout << endl;
            cout << "---TC     : " << musteriTC; cout << endl;
            cout << "--- Ücret : " << toplam; cout << endl << endl;
        }

    }
    if (bulma == 0)
    {
        cout << "Böyle bir kişi adına rezervasyon yapılmamıştır !" << endl;
    }

    oku.close();
}
void otel::odaBosaltma()
{
    ifstream guncelle("musteri_bilgileri.txt");
    ofstream ekle("gecici.txt", ios::app);
    int k_odano, oda_kontrol = 0;
    cout << "Silmek istediğiniz oda numarasını giriniz=";
    cin >> k_odano;
    while (!guncelle.eof())
    {
        guncelle >> odaNumarasi >> musteriAdi >> musteriSoyadi >> musteriTC >> toplam;

        if (k_odano == odaNumarasi)
        {
            oda_kontrol = 1;
            cout << "Odanız silindi.";
        }

        else
        {
            ekle << endl << odaNumarasi << "\t" << musteriAdi << "\t" << musteriSoyadi << "\t" << musteriTC << toplam;
        }
    }
    if (oda_kontrol == 0)
    {
        cout << "Oda bulunamadı...";
    }

    guncelle.close();
    ekle.close();
    remove("musteri_bilgileri.txt");
    rename("gecici.txt", "musteri_bilgileri.txt");
}

void otel::odaGuncelleme(){
    ifstream guncelle("musteri_bilgileri.txt");
    ofstream ekle("gecici.txt", ios::app);
    int k_odano, oda_kontrol = 0;
    cout << "Güncellemek istediğiniz oda numarasını giriniz=";
    cin >> k_odano;
    while (!guncelle.eof())
    {
        guncelle >> odaNumarasi >> musteriAdi >> musteriSoyadi >> musteriTC >> toplam;

        if (k_odano == odaNumarasi)
        {
            oda_kontrol = 1;
            cout << "   Adı: ";
            cin >> musteriAdi;

            cout << "   Soyadı: ";
            cin >> musteriSoyadi;

            cout << endl;

            cout << "    TC Kimlik Numarasi : ";
            cin >> musteriTC;
            cout << endl;

            cout << "   Kaç gün kalmak istiyorsunuz ? ";     // Müşterinin otelde kalacağı gün sayısı
            cin >> kalinacakGunSayisi;
            cout << endl;
        }



            // Müşterinin ödeyeceği ücret hesaplama bölümü //

            int guncellemeSecim;
            cout << "1.Deniz Manzarali Odada Konakla" << endl;
            cout << "2.Kara Manzarali Odada Konakla" << endl;

            switch (guncellemeSecim) {
            case 1:
            guncellenmisUcret=kalinacakGunSayisi*11250;
            cout << "Odemeniz Gereken Ucret: " << guncellenmisUcret <<endl;
            break;
            case 2:
            guncellenmisUcret=kalinacakGunSayisi*7650;
            cout << "Odemeniz Gereken Ucret: " << guncellenmisUcret << endl;
            break;




            ekle << endl << odaNumarasi << "\t" << musteriAdi << "\t" << musteriSoyadi << "\t" << musteriTC << toplam;
            } }




    if (oda_kontrol == 0)
    {
        cout << "Oda bulunamadı...";
    }

    guncelle.close();
    ekle.close();
    remove("musteri_bilgileri.txt");
    rename("gecici.txt", "musteri_bilgileri.txt");


}

    int main()
    {
    setlocale(LC_ALL, "Turkish");
    otel a;
    system("pause");
        return 0;
    }

#include <iostream>
using namespace std;

const float prowizja_bolt = 0.25;
const float paliwo1 = 6;
const float paliwo2 = 6.25;
const float paliwo3 = 6.5;
const float spalanie1 = 6;
const float spalanie2 = 7;
const float spalanie3 = 7.5;
float ubezpieczenie = 0;
const float wbitka = 200;
const float kurs = 7; //odległość (km)
float ilosc_godzin1 = 40;
float ilosc_godzin2 = 60;
float ilosc_godzin3 = 80;
float ilosc_kursow1 = 2;
float ilosc_kursow2 = 2.5;
float ilosc_kursow3 = 3;
float kwota_za_kurs1 = 20;
float kwota_za_kurs2 = 30;
float kwota_za_kurs3 = 40;

float zysk_brutto(float,float,float);
float koszty_stale_miesiecznie(float);
float zysk_netto(float, float, float, float,float,float,float);
int main()
{
	float koszty_stale;
	cout << "---Program do wyliczania kosztow jazdy na uberze----" << endl;
	cout << "Podaj kwote ubezpieczenia na taxi:" << endl;
	cin >> ubezpieczenie;
	
	float zysk_netto40= 0;
	float zysk_netto60 = 0;
	float zysk_netto80 = 0;
	koszty_stale = koszty_stale_miesiecznie(ubezpieczenie);

	cout << "Najlepsza opcja: " << endl;
	cout << "Cena paliwa: " << paliwo1 << endl;
	cout << "Spalanie " << spalanie1 << endl;
	cout << "Ilosc kursow na godzine: " << ilosc_kursow3 << endl;
	cout << "Odleglosc jednego kursu: " << kurs << endl;
	cout << "Kwota_za_kurs: " << kwota_za_kurs3 << endl;
	cout << "Koszty stale miesieczne: " << koszty_stale << endl;
	zysk_netto80 = zysk_netto(ilosc_godzin3, ilosc_kursow3, kwota_za_kurs3, koszty_stale, paliwo1, spalanie1, kurs);
	zysk_netto60 = zysk_netto(ilosc_godzin2, ilosc_kursow3, kwota_za_kurs3, koszty_stale, paliwo1, spalanie1, kurs);
	zysk_netto40 = zysk_netto(ilosc_godzin1, ilosc_kursow3, kwota_za_kurs3, koszty_stale, paliwo1, spalanie1, kurs);
	cout << "Zysk na godziny miesiecznie: 40: " << zysk_netto40 << "zl 60: "<< zysk_netto60 << "zl 80: "<< zysk_netto80 <<"zl" << endl;

	cout << '\n';

	cout << "Cos pomiedzy: " << endl;
	cout << "Cena paliwa: " << paliwo2 << endl;
	cout << "Spalanie " << spalanie2 << endl;
	cout << "Ilosc kursow na godzine: " << ilosc_kursow2 << endl;
	cout << "Odleglosc jednego kursu: " << kurs << endl;
	cout << "Kwota_za_kurs: " << kwota_za_kurs2 << endl;
	cout << "Koszty stale miesieczne: " << koszty_stale << endl;
	zysk_netto80 = zysk_netto(ilosc_godzin3, ilosc_kursow2, kwota_za_kurs2, koszty_stale, paliwo2, spalanie2, kurs);
	zysk_netto60 = zysk_netto(ilosc_godzin2, ilosc_kursow2, kwota_za_kurs2, koszty_stale, paliwo2, spalanie2, kurs);
	zysk_netto40 = zysk_netto(ilosc_godzin1, ilosc_kursow2, kwota_za_kurs2, koszty_stale, paliwo2, spalanie2, kurs);
	cout << "Zysk na godziny miesiecznie: 40: " << zysk_netto40 << "zl 60: " << zysk_netto60 << "zl 80: " << zysk_netto80<< "zl" << endl;

	cout << '\n';

	zysk_netto80 = zysk_netto(ilosc_godzin3, ilosc_kursow1, kwota_za_kurs1, koszty_stale, paliwo3, spalanie3, kurs);
	zysk_netto60 = zysk_netto(ilosc_godzin2, ilosc_kursow1, kwota_za_kurs1, koszty_stale, paliwo3, spalanie3, kurs);
	zysk_netto40 = zysk_netto(ilosc_godzin1, ilosc_kursow1, kwota_za_kurs1, koszty_stale, paliwo3, spalanie3, kurs);
	cout << "Najgorsza opcja: " << endl;
	cout << "Cena paliwa: " << paliwo3 << endl;
	cout << "Spalanie " << spalanie3 << endl;
	cout << "Ilosc kursow na godzine: " << ilosc_kursow1 << endl;
	cout << "Odleglosc jednego kursu: " << kurs << endl;
	cout << "Kwota_za_kurs: " << kwota_za_kurs1 << endl;
	cout << "Koszty stale miesieczne: " << koszty_stale << endl;
	cout << "Zysk na godziny miesiecznie: 40: " << zysk_netto40 << "zl 60: " << zysk_netto60 << "zl 80: " << zysk_netto80 << "zl" << endl;

}
float zysk_brutto(float godziny,float ilosc_kursow,float kwota) {
	float wynik = 0;
	wynik = godziny * ilosc_kursow * kwota;
	return wynik;
}
float koszty_stale_miesiecznie(float ubezpieczenie) {
	float koszty = 0;
	koszty = wbitka + ubezpieczenie / 12;
	return koszty;
}
float zysk_netto(float ilosc_godzin, float ilosc_kursow, float kwota_za_kurs, float koszty_stale, float paliwo, float spalanie, float kurs) {
	float wynik_zysk_brutto = 0;
	float wynik_zysk_netto = 0;
	float spalanie_na_kilometr = 0;
	float koszt_na_kilometr = 0;
	float prowizja = 0;
	float odleglosc = 0;
	odleglosc = ilosc_godzin * ilosc_kursow * kurs;
	wynik_zysk_brutto = zysk_brutto(ilosc_godzin, ilosc_kursow, kwota_za_kurs);
	prowizja = wynik_zysk_brutto * prowizja_bolt;
	spalanie_na_kilometr = spalanie / 100;
	koszt_na_kilometr = spalanie_na_kilometr * paliwo;
	wynik_zysk_netto = wynik_zysk_brutto - odleglosc * koszt_na_kilometr - koszty_stale - prowizja;
	return wynik_zysk_netto;

}
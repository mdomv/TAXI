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
float ilosc_godzin3 = 600;
float ilosc_kursow1 = 2;
float ilosc_kursow2 = 2.5;
float ilosc_kursow3 = 3;
float kwota_za_kurs1 = 20;
float kwota_za_kurs2 = 30;
float kwota_za_kurs3 = 21;

float zysk_brutto(float,float,float);
float koszty_stale_miesiecznie(float);
float zysk_netto(float, float, float, float,float,float,float);
void pokaz_wariant(const char* opis, float paliwo, float spalanie, float ilosc_kursow, float kwota_za_kurs, float koszty_stale, float ilosc_godzin1, float ilosc_godzin2, float ilosc_godzin3, float kurs);
int minimum_godzin(float,float,float,float,float,float);
float koszt_na_kilometr(float, float);
float koszty_paliwa(float, float,float,float,float);
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
	float corolla_paliwo = 2.8;
	float corolla_spalanie = 5;
	
	
	pokaz_wariant("Xsara: ", paliwo1, spalanie1, ilosc_kursow3, kwota_za_kurs3, koszty_stale, ilosc_godzin1, ilosc_godzin2, ilosc_godzin3, kurs);
	//pokaz_wariant("Cos pomiedzy:", paliwo2, spalanie2, ilosc_kursow2, kwota_za_kurs2, koszty_stale, ilosc_godzin1, ilosc_godzin2, ilosc_godzin3, kurs);
	//pokaz_wariant("Najgorsza opcja:", paliwo3, spalanie3, ilosc_kursow1, kwota_za_kurs1, koszty_stale, ilosc_godzin1, ilosc_godzin2, ilosc_godzin3, kurs);
	pokaz_wariant("Corolla: ",corolla_paliwo,corolla_spalanie,ilosc_kursow3,kwota_za_kurs3,koszty_stale,ilosc_godzin1,ilosc_godzin2, ilosc_godzin3,kurs);
	//cout << "Dupa" << endl;
	return 0;
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
	float koszt = 0;
	float prowizja = 0;
	float odleglosc = 0;
	odleglosc = ilosc_godzin * ilosc_kursow * kurs;
	wynik_zysk_brutto = zysk_brutto(ilosc_godzin, ilosc_kursow, kwota_za_kurs);
	prowizja = wynik_zysk_brutto * prowizja_bolt;
	koszt = koszt_na_kilometr(paliwo, spalanie);
	wynik_zysk_netto = wynik_zysk_brutto - odleglosc * koszt - koszty_stale - prowizja;
	return wynik_zysk_netto;

}
float koszt_na_kilometr(float paliwo, float spalanie) {
	float spalanie_na_kilometr = 0;
	spalanie_na_kilometr = spalanie / 100;
	float koszt = 0;
	koszt = spalanie_na_kilometr * paliwo;
	return koszt;
}
void pokaz_wariant(const char* opis, float paliwo, float spalanie, float ilosc_kursow, float kwota_za_kurs, float koszty_stale, float ilosc_godzin1, float ilosc_godzin2, float ilosc_godzin3, float kurs) {
	float koszt1 = 0;
	float koszt2 = 0;
	float koszt3 = 0;
	koszt1 = koszty_paliwa(paliwo, spalanie, ilosc_kursow, kurs, ilosc_godzin1);
	koszt2 = koszty_paliwa(paliwo, spalanie, ilosc_kursow, kurs, ilosc_godzin2);
	koszt3 = koszty_paliwa(paliwo, spalanie, ilosc_kursow, kurs, ilosc_godzin3);
	
	cout << opis << endl;
	cout << "Cena paliwa: " << paliwo << endl;
	cout << "Spalanie: " << spalanie << endl;
	cout << "Ilosc kursow na godzine: " << ilosc_kursow << endl;
	cout << "Odleglosc jednego kursu: " << kurs << endl;
	cout << "Kwota za kurs: " << kwota_za_kurs << endl;
	cout << "Koszty stale miesieczne: " << koszty_stale << endl;
	cout << "Zysk na godziny miesiecznie: 40: " << zysk_netto(ilosc_godzin1, ilosc_kursow, kwota_za_kurs, koszty_stale, paliwo, spalanie, kurs)
		<< "zl 60: " << zysk_netto(ilosc_godzin2, ilosc_kursow, kwota_za_kurs, koszty_stale, paliwo, spalanie, kurs)
		<< "zl 600: " << zysk_netto(ilosc_godzin3, ilosc_kursow, kwota_za_kurs, koszty_stale, paliwo, spalanie, kurs) << "zl" << endl;
	cout << "Koszty paliwa: 40: " << koszt1 << "zl 60: " << koszt2
		 << "zl 600: " << koszt3  << "zl" << endl;
	
	int godziny = 0;
	godziny = minimum_godzin(ilosc_kursow, kwota_za_kurs, koszty_stale, paliwo, spalanie, kurs);
	cout << "Minimalna ilosc godzin dla " << opis << godziny << endl << endl;
}
int minimum_godzin(float ilosc_kursow, float kwota_za_kurs, float koszty_stale, float paliwo, float spalanie, float kurs) {
	float zysk_na_godzine = 0;
	zysk_na_godzine = ilosc_kursow * kwota_za_kurs - koszt_na_kilometr(paliwo, spalanie) * kurs * ilosc_kursow;
	if (zysk_na_godzine <= 0) {
		cout << "Zysk na godzinę jest mniejszy lub równy zero! Nie można obliczyć minimalnej liczby godzin." << endl;
		return -1;
	}
	int godziny = 0;
	int zysk = 0;
	while (zysk < koszty_stale) {
		zysk += zysk_na_godzine;
		godziny++;
	}
	return godziny;
}
float koszty_paliwa(float paliwo, float spalanie, float ilosc_kursow, float kurs,float ilosc_godzin) {
	float koszt = koszt_na_kilometr(paliwo, spalanie)*ilosc_kursow*kurs*ilosc_godzin;
	return koszt;
}
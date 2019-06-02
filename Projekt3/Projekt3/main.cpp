#include <iostream>
#include "Gra.hpp"

int main()
{
	/*-----------------------------  Wyswietlanie menu  ----------------------------*/
	int rozmiar = 0;
	int ileDlaWygranej = 0;
	std::cout << "	x o x o x o x o x o x o x o x o x o x o x o x o x o x o x o x\n";
	std::cout << "	o                                                           o\n";
	std::cout << "	x                    KOLKO I KRZYZYK                        x\n";
	std::cout << "	o        Gra ze sztuczna inteligencja wykorzystujaca	    o\n";	
	std::cout << "	x        algorytm min - max z cieciami alpha - beta         x\n";
	std::cout << "	o                                                           o\n"; 
	std::cout << "	x           Twoj symbol to: 'x'. Rozpoczynasz gre.          x\n";
	std::cout << "	o   Wpisuj odpowiednie wspolrzedne pola, aby wstawic znak   o\n";
	std::cout << "	x                                                           x\n";
	std::cout << "	o x o x o x o x o x o x o x o x o x o x o x o x o x o x o x o\n";
	
	std::cout << "\n                         Podaj wielkosc planszy: ";
	std::cin >> rozmiar;
	while (rozmiar <= 2) //wielkosc musi byc wieksza od 2
	{
		std::cout << "             Bledna wielkosc planszy, podaj poprawna wielkosc: ";
		std::cin >> rozmiar;
	}
	
	std::cout << "\n                Podaj ilosc znakow do odniesienia zwyciestwa: ";
	std::cin >> ileDlaWygranej;
	while (ileDlaWygranej <= 2) // ilosc znakow dla wygranej musi byc wieksza niz 2
	{
		std::cout << "                Nieodpowiednia ilosc, podaj poprawna wartosc: ";
		std::cin >> ileDlaWygranej;
	}

	system("cls");

	/*----------------------------- Zapis glownej gry  ----------------------------*/

	Gra plansza(rozmiar, ileDlaWygranej);
	plansza.WyswietlPlansze();
	Pole pole;
	int czyjRuch = 0; // oznaczenia: 0 - gracz, 1 - komputer

	while ((!plansza.CzyWygrana('x') ) && (!plansza.CzyWygrana('o')) && (!plansza.CzyRemis()))
	{
		if (czyjRuch == 0)
		{
			do {
				std::cout << "\n   Wprowadz poprawne wspolrzedne\n   wiersz: ";
				std::cin >> pole.NrWiersz;
				std::cout << "   kolumna: ";
				std::cin >> pole.NrKolumna;
			} while (plansza.WstawWartosc(pole.NrWiersz, pole.NrKolumna, 'x') == 0);
			system("cls");
			plansza.WyswietlPlansze();
			czyjRuch = 1;
		}

		else
		{
			do {
				pole = plansza.RuchKomputera();
			} while (plansza.WstawWartosc(pole.NrWiersz, pole.NrKolumna, 'o') == 0);
	
			system("cls");
			plansza.WyswietlPlansze();
			czyjRuch = 0;
		}
	}

	if (plansza.CzyWygrana('x'))
		std::cout << " WYGRALES!\n";
	if (plansza.CzyWygrana('o'))
		std::cout << " PRZEGRALES - WYGRANA KOMPUTERA!\n";
	if (plansza.CzyRemis())
		std::cout << " REMIS! \n";
	
	system("pause");
	return 1;
}
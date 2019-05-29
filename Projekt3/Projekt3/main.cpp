#include <iostream>
#include "Gra.hpp"

int main()
{
	int rozmiar = 0;
	int ileDlaWygranej = 0;
	std::cout << "podaj wielkosc ";
	std::cin >> rozmiar;
	std::cout << "podaj ilosc aby wygrac ";
	std::cin >> ileDlaWygranej;

	Gra plansza(rozmiar, ileDlaWygranej);
	plansza.WyswietlPlansze();
	Pole pole;
	int czyjRuch = 0; // 0 - gracz, 1 - komputer

	while ((!plansza.CzyWygrana('x') ) && (!plansza.CzyWygrana('o')) && (!plansza.CzyRemis()))
	{
		if (czyjRuch == 0)
		{
			do {
				std::cout << "Wprowadz poprawne wspolrzedne: ";
				std::cin >> pole.NrWiersz >> pole.NrKolumna;
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
			/*do {
				std::cout << "Wprowadz poprawne wspolrzedne: ";
				std::cin >> pole.NrWiersz >> pole.NrKolumna;
			} while (plansza.WstawWartosc(pole.NrWiersz, pole.NrKolumna, 'o') == 0);*/			
			system("cls");
			plansza.WyswietlPlansze();
			czyjRuch = 0;
		}
	}



	system("pause");
	return 1;
}
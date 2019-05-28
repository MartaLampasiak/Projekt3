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
	while (plansza.CzyWygrana('x') == 0)
	{
		int x;
		int y;
		std::cin >> x >> y;
		std::cout <<  plansza.WstawWartosc(x, y, 'x');
		system("cls");
		plansza.WyswietlPlansze();
	}



	system("pause");
	return 1;
}
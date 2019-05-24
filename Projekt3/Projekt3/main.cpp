#include <iostream>
#include "Plansza.hpp"

int main()
{
	int rozmiar = 0;
	std::cin >> rozmiar;

	Plansza plansza(rozmiar);
	//plansza.WyswietlPlansze();
	plansza.ZamienWartosc(1, 0, 'x');
	std::cout << "\n";
	plansza.WyswietlPlansze();
	plansza.ResetujPlansze();
	plansza.WyswietlPlansze();

	system("pause");
	return 1;
}
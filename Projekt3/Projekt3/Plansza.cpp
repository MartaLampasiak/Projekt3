#include "Plansza.hpp"

void Plansza::WyswietlPlansze()
{
	int licznik = 0;
	std::cout << "  ";
	for (int j = 0; j < rozmiar; ++j)
	{
		std::cout << " " << j + 1 << " ";
		if (j < rozmiar - 1)
			std::cout << " ";
	}
	std::cout << "\n\n  ";

	for (int j = 0; j < rozmiar; ++j)
	{
		std::cout << "---";
		if (j < rozmiar - 1)
			std::cout << "+";

	}
	std::cout << "\n";

	for (int i = 0; i < rozmiar*rozmiar; ++i)
	{
		if (i == licznik * rozmiar)
			std::cout << licznik + 1 << " ";

		std::cout << " " << plansza[i] << " ";
		if ((i%rozmiar != (rozmiar - 1)))
			std::cout << "|";
		else
		{
			std::cout << "\n  ";
			for (int j = 0; j < rozmiar; ++j)
			{
				std::cout << "---";
				if (j < rozmiar - 1)
					std::cout << "+";

			}
			std::cout << "\n";
			licznik++;
		}
	}
}

void Plansza::ZamienWartosc(int wiersz, int kolumna, char symbol)
{
	int index = rozmiar * wiersz + kolumna;
	plansza[index] = symbol;
}

void Plansza::ResetujPlansze()
{
	for (int i = 0; i < rozmiar*rozmiar; ++i)
	{
		plansza[i] = ' ';
	}
}
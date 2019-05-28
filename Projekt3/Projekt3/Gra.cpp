#include "Gra.hpp"


void Gra::WyswietlPlansze()
{
	std::cout << "   ";
	for (int i = 0; i < rozmiar; ++i)
		std::cout << " " << i + 1 << "  ";
	std::cout << "\n\n";
	for (int i = 0; i < rozmiar; ++i)
	{
		std::cout << i + 1 << "  ";
		for (int j = 0; j < rozmiar; ++j)
		{
			std::cout << " " << plansza[i][j] << " ";
			if (j%rozmiar != (rozmiar - 1))
				std::cout << "|";
		}
		std::cout << "\n   ";


		if (i < rozmiar - 1)
		{
			for (int j = 0; j < rozmiar; ++j)
			{
				std::cout << "---";
				if ((j < rozmiar - 1))
					std::cout << "+";
			}
			std::cout << "\n";
		}
	}
}

void Gra::ResetujPlansze()
{
	for (int i = 0; i < rozmiar; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
			plansza[i][j] = ' ';
	}
}

bool Gra::WstawWartosc(int wiersz, int kolumna, char symbol)
{
	if (wiersz > rozmiar || kolumna > rozmiar || (plansza[wiersz - 1][kolumna - 1] != ' '))
		return 0;
	else
		plansza[wiersz - 1][kolumna - 1] = symbol;
		return 1;
}

bool Gra::CzyRemis()
{
	for (int i = 0; i < rozmiar*rozmiar; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
		{
			if (plansza[i][j] == ' ')
				return 0;
		}
		return 1;
	}
}

bool Gra::CzyWygranaWiersz(char znak)
{
	int licznikZnakow = 0;

	//sprawdz, czy wygrana w wierszu
	for (int i = 0; i < rozmiar; ++i)
	{
		licznikZnakow = 0;
		for (int j = 0; j < rozmiar; ++j)
		{
			if (plansza[i][j] == znak)
				licznikZnakow++;
			else
				licznikZnakow = 0;
			if (licznikZnakow == ileDlaWygranej)
				return 1;
		}
	}
	return 0;
}

bool Gra::CzyWygranaKolumna(char znak)
{
	int licznikZnakow = 0;
	//sprawdz, czy wygrana w kolumnie
	for (int i = 0; i < rozmiar; ++i)
	{
		licznikZnakow = 0;
		for (int j = 0; j < rozmiar; ++j)
		{
			if (plansza[j][i] == znak)
				licznikZnakow++;
			else
				licznikZnakow = 0;
			if (licznikZnakow == ileDlaWygranej)
				return 1;
		}
	}
	return 0;
}

bool Gra::CzyWygranaPrzekatne(char znak)
{
	int licznikZnakow = 0;
	for (int j = 0; j < rozmiar; ++j)
	{
		licznikZnakow = 0;
		for (int i = j; i < rozmiar; ++i)
		{
			if (plansza[i][i - j] == znak)
				licznikZnakow++;
			else
				licznikZnakow = 0;
			if (licznikZnakow == ileDlaWygranej)
				return 1;
		}
	}

	for (int j = 1; j < rozmiar; ++j)
	{
		licznikZnakow = 0;
		for (int i = j; i < rozmiar; ++i)
		{
			if (plansza[i - j][i] == znak)
				licznikZnakow++;
			else
				licznikZnakow = 0;
			if (licznikZnakow == ileDlaWygranej)
				return 1;
		}
	}

	for (int j = 0; j < rozmiar; ++j)
	{
		licznikZnakow = 0;
		for (int i = j; i < rozmiar; ++i)
		{
			if (plansza[i][rozmiar - 1 + j - i] == znak)
				licznikZnakow++;
			else
				licznikZnakow = 0;
			if (licznikZnakow == ileDlaWygranej)
				return 1;
		}
	}

	for (int j = 1; j < rozmiar; ++j)
	{
		licznikZnakow = 0;
		for (int i = j; i < rozmiar - j; ++i)
		{
			if (plansza[i][rozmiar - 1 - i - j] == znak)
				licznikZnakow++;
			else
				licznikZnakow = 0;
			if (licznikZnakow == ileDlaWygranej)
				return 1;
		}
	}
	return 0;
}

bool Gra::CzyWygrana(char znak)
{
	if (CzyWygranaWiersz(znak) == 1 ||
		CzyWygranaKolumna(znak) == 1 ||
		CzyWygranaPrzekatne(znak) == 1)
	{
		return 1;
	}
	else
		return 0;
}

Pole Gra::AlphaBeta(int glebokoscRekurencji, int alpha, int beta, Gra plansza, bool gracz)
{
	Pole pole;
	pole.NrWiersz;

	if (glebokoscRekurencji == 0)
	{
		return;
	}
}
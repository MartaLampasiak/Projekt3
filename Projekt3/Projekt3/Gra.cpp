#include "Gra.hpp"

constexpr auto oo = 2147483647;
/* zmienna globalna do wpisywania glebokosci rekurencji algorytmu AlphaBeta */
#define Glebokosc 8

void Gra::WyswietlPlansze()
{
	std::cout << "   ";
	for (int i = 0; i < rozmiar; ++i)
		std::cout << " " << i  << "  ";
	std::cout << "\n\n";
	for (int i = 0; i < rozmiar; ++i)
	{
		std::cout << i  << "  ";
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

/* Metoda wstawia symbol gracza 'x' lub 'o'
   wtedy, gdy podane sa poprawne wspolrzedne
   lub kiedy pole jest puste				 */
bool Gra::WstawWartosc(int wiersz, int kolumna, char symbol)
{
	if (wiersz >= rozmiar || kolumna >= rozmiar || wiersz < 0 || kolumna < 0
		|| (plansza[wiersz][kolumna] == 'x') || (plansza[wiersz][kolumna] == 'o'))
		return 0;
	else
		plansza[wiersz][kolumna] = symbol;
	return 1;
}

bool Gra::CzyRemis()
{
	for (int i = 0; i < rozmiar; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
		{
			if (plansza[i][j] == ' ')
				return 0;
		}
	}
	return 1;
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

/* Algorytm min-max z cieciami alpha-beta - metoda dla sztucznej inteligencji */
/* Argument 'Maksymalny' przyjmuje wartosc 0 dla czlowieka, 1 dla komputera   */
int Gra::AlphaBeta(int glebokoscRekurencji, int alpha, int beta, char **plansza, bool Maxymalny)
{
	int oszacowanie = 0;

	if (glebokoscRekurencji == Glebokosc)
		return 0;
	if (CzyWygrana('o'))
		return 10;
	if (CzyWygrana('x'))
		return -10;
	if (CzyRemis())
		return 0;

	if (Maxymalny)
	{
		oszacowanie = -oo;
		for (int i = 0; i < rozmiar; ++i)
		{
			for (int j = 0; j < rozmiar; ++j)
			{
				if (plansza[i][j] == ' ')
				{
					plansza[i][j] = 'o';
					oszacowanie = std::max(oszacowanie, AlphaBeta(glebokoscRekurencji + 1, alpha, beta, plansza, 0));
					plansza[i][j] = ' ';
					alpha = std::max(alpha, oszacowanie); //wybiera wieksza wartosc alphy

					if (beta <= alpha) //czy sprawdzac dalej
						break; //odciecie galezi
				}
			}
		}
		return oszacowanie;
	}

	else
	{
		oszacowanie = oo;
		for (int i = 0; i < rozmiar; ++i)
		{
			for (int j = 0; j < rozmiar; ++j)
			{
				if (plansza[i][j] == ' ')
				{
					plansza[i][j] = 'x';
					oszacowanie = std::min(oszacowanie, AlphaBeta(glebokoscRekurencji + 1, alpha, beta, plansza, 1));
					plansza[i][j] = ' ';
					beta = std::min(beta, oszacowanie);

					if (beta <= alpha) //czy sprawdzac dalej
						break; //odciecie galezi
				}
			}
		}
		return oszacowanie;
	}
}

/* metoda dla sztucznej inteligencji */
Pole Gra::RuchKomputera()
{
	Pole pole;
	int oszacowanie = -oo;
	int wynik = 0;

	for (int i = 0; i < rozmiar; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
		{
			if (plansza[i][j] == ' ')
			{
				plansza[i][j] = 'o';
				wynik = AlphaBeta(0, -oo, oo, plansza, 0);
				plansza[i][j] = ' ';

				if (wynik > oszacowanie)
				{
					oszacowanie = wynik;
					pole.NrWiersz = i;
					pole.NrKolumna = j;
				}
			}
		}
	}
	return pole;
}







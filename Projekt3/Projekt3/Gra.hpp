#pragma once
#include<iostream>
#include <algorithm>

//wpolrzedne polozenia znaku na planszy (pola)
struct Pole
{
	int NrWiersz = 0;
	int NrKolumna = 0;
};

class Gra
{

private:

	int rozmiar;
	int ileDlaWygranej;
	char **plansza;

public:

	// Konstruktor - tworzy plansze - tablice dwuwymiarowa
	Gra(int rozmiar, int ileDlaWygranej) 
	{
		this->ileDlaWygranej = ileDlaWygranej;
		this->rozmiar = rozmiar;
		plansza = new char*[rozmiar];
		for (int i = 0; i < rozmiar; ++i)
		{
			plansza[i] = new char[rozmiar];
			for (int j = 0; j < rozmiar; ++j)
				plansza[i][j] = ' ';
		}
	}

	~Gra()
	{
		this->rozmiar = rozmiar;
		for (int i = 0; i < rozmiar; ++i)
			delete[] plansza[i];
		delete[] plansza;
		plansza = NULL;
	}

	void WyswietlPlansze();
	void ResetujPlansze();
	bool WstawWartosc(int wiersz, int kolumna, char symbol);
	bool CzyRemis();
	bool CzyWygranaWiersz(char znak);
	bool CzyWygranaKolumna(char znak);
	bool CzyWygranaPrzekatne(char znak);
	int AlphaBeta(int glebokosc, int alpha, int beta, char **plansza, bool gracz);
	bool CzyWygrana(char znak);
	Pole RuchKomputera();
	

};


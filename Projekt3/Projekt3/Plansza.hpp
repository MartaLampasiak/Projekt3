#pragma once
#include<iostream>

class Plansza
{
	//friend class Gra;
private:

	int rozmiar;
	char *plansza;

public:
	
	Plansza(int rozmiar)
	{
		this->rozmiar = rozmiar;
		plansza = new char[rozmiar*rozmiar];
		for (int i = 0; i < rozmiar*rozmiar; ++i)
			plansza[i] = ' ';	
	}

	~Plansza()
	{
		delete[] plansza;
		plansza = NULL;
	}

	void WyswietlPlansze();
	void ResetujPlansze();
	void ZamienWartosc(int wiersz, int kolumna, char symbol);
};


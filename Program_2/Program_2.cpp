// Pepaś Dominik - 11:00

#include "pch.h"
#include "Head.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	int n = 0;
	int m = 0;
	int wybor = 0;

	//menu
	cout << "Podaj ktora metode chcesz wybrac" << endl << endl;
	cout << "1.Liniowa metoda kongruencyjna" << endl;
	cout << "2.Addytywna metoda kongruencyjna" << endl << endl;

	cin >> wybor;

	cin_n_m(n,m);

	int *liczby_pseudolosowe = stworzTablice_x1(n);

	liczby_pseudolosowe = LCG(n, m);

	switch (wybor)
	{
		case 1:
			zapis_do_pliku(liczby_pseudolosowe,n);
			break;

		case 2:
			AMK(n, m, liczby_pseudolosowe);
			break;

		default:
			cout << "Zly wybor" << endl;
			break;
	}

	return 0;
}



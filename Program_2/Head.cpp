#include "pch.h"
#include "Head.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;


int *stworzTablice_x1(int n)
{
	int *T = new int[n];
	return T;
}

void cin_n_m(int &n, int &m)
{
	int x_max;

	do
	{
		cout << "Podaj n: " << endl;
		cin >> n;
		if (n < 0)
			cout << "n musi byc wieksze lub rowne zero" << endl;

	} while (n < 0);


	do
	{
		cout << "Podaj x max: " << endl;
		cin >> x_max;
		if (x_max < 0)
			cout << "x max musi byc wieksze lub rowne zero" << endl;

	} while (x_max < 0);


	m = x_max + 1;

}

int *LCG(int &n, int &m)
{
	vector<int>czynniki_pierwsze;
	int temp;
	temp = m;
	int k = 2;

	//szukanie czynników pierwszych m	
	while (temp > 1)
	{
		if (k == m)
			break;

		while (temp%k == 0)
		{
			czynniki_pierwsze.push_back(k);
			temp /= k;
		}
		++k;

	}


	//szukanie spoœród czynników pierwszych liczb pierwszych

	vector<int>liczby_pierwsze;

	for (int i = 0; i < czynniki_pierwsze.size(); i++)
	{
		if (czynniki_pierwsze[i] >= 8)
		{
			if (czynniki_pierwsze[i] % 2 != 0 && czynniki_pierwsze[i] % 3 != 0 && czynniki_pierwsze[i] % 5 != 0 && czynniki_pierwsze[i] % 7 != 0)
				liczby_pierwsze.push_back(czynniki_pierwsze[i]);
		}

		if (czynniki_pierwsze[i] < 8)
		{
			if (czynniki_pierwsze[i] % 2 == 0 || czynniki_pierwsze[i] % 3 == 0 || czynniki_pierwsze[i] % 5 == 0 || czynniki_pierwsze[i] % 7 == 0)
				liczby_pierwsze.push_back(czynniki_pierwsze[i]);
		}

	}


	int x_o;

	do
	{
		cout << "Podaj x 0: " << endl;
		cin >> x_o;
		if (x_o < 0 || x_o >= m )
			cout << "x 0 musi byc wieksze lub rowne zero i mniejsze od "<<m<< endl;

	} while (x_o < 0 || x_o >= m);


	//szukanie c nwd(c,m)=1

	int c = 0;

	for (int i = 1; i < m + 1; i++)
	{
		int help;
		int help2;
		help = m;
		c = m - i;
		help2 = c;

		do
		{
			if (help > help2) 
			{
				help = help - help2;
			}
			else
			{
				help2 = help2 - help;
			}
		} while (help != help2);

			if (help == 1)
				break;
	}
	
	//szukanie a nwd(a,m)=1

	vector<int> tab_a;

	for (int i = 1; i < m + 1; i++)
	{
		int a = 0;
		int help;
		int help2;
		help = m;
		a = m - i;
		help2 = a;
		
		if (a > 1)
		{
			do
			{
				
				if (help > help2)
				{
					help = help - help2;
				}
				else
				{
					help2 = help2 - help;
				}
			} while (help != help2);

			if (help == 1)
				tab_a.push_back(a);
		}
	}


	//wyznaczanie lambdy dla poszczególnych a
	vector<int> tab_lambda;

	for (int i = 0; i < tab_a.size(); i++)
	{
		int a = 0;
		a = tab_a[i];
		int lambda = 1;
		int licznik = 0;

		for(;;)
		{
			licznik++;
			if (licznik == m)
			{
				lambda = m - 1;
				break;

			}

			if (a < 2)
				break;

			long x = pow(a, lambda);

			if (x%m == 1)
				break;

			lambda++;
		}

		tab_lambda.push_back(lambda);
		
		
	}
	

	int a = 0;
	int lambda = 0;


	//wyznaczenie mo¿liwych a które zostan¹ u¿yte do wzoru poprzez znalezienie najwiêkszej lambdy
	vector<int>mozliwe_a;

	for (int i = 0; i < tab_a.size(); i++)
	{

		if (tab_lambda[i] > lambda)
		{
			lambda = tab_lambda[i];
		}

	}

	for (int i = 0; i < tab_a.size(); i++)
	{
		if (tab_lambda[i] == lambda)
		{
			mozliwe_a.push_back(tab_a[i]);
		}

	}


	//sprawdzanie trzech warunków 

	for (int i = 0; i < mozliwe_a.size(); i++)
	{
		int b;
		b = mozliwe_a[i] - 1;
		int licznik = 0;

		if (liczby_pierwsze.size() > 0)
		{
			for (int j = 0; j < liczby_pierwsze.size(); j++)
			{

				if (b%liczby_pierwsze[j] == 0)
					licznik++;
				else
					break;
			}
		}
		
		

		if ((liczby_pierwsze.size() == licznik) && ( b % 4 == 0 && m % 4 == 0) )
			a = mozliwe_a[i];

	} 

	if (a == 0)
	{
		for (int i = 0; i < mozliwe_a.size(); i++)
		{
				if (mozliwe_a[i] > a)
					a = mozliwe_a[i];

		}

	}

	//wyznaczenie i zapisanie w tablicy liczb pseudolosowych

	int *wyniki = stworzTablice_x1(n+1);
	wyniki[0] = x_o;

	for (int i = 1; i < n+1; i++)
	{
		wyniki[i] = (a*wyniki[i - 1] + c) % m;
	}


	
	return wyniki;
}

int AMK(int &n, int &m, int *liczby_pseudolosowe)
{

	//zapisanie par liczb w tablicy dwuwymiarowej

	int pary_liczb[90][2] = { {1,2},{1,3},{1,4},{2,5},{1,6},{1,7},{3,7},{4,9},{3,10},{2,11},
							{1,15},{4,15},{7,15},{3,17},{5,17},{6,17},{7,18},{3,20},{2,21},{1,22},
							{5,23},{9,23},{3,25},{7,25},{3,28},{9,28},{13,28},{2,29},{3,31},{6,31},
							{7,31},{13,31},{13,33},{2,35},{11,36},{4,39},{8,39},{14,39},{3,41},{20,41},
							{5,47},{14,47},{20,47},{21,47},{9,49},{12,49},{15,49},{22,49},{3,52},{19,52},
							{21,52},{24,55},{7,57},{22,57},{19,58},{1,60},{11,60},{1,63},{5,63},{31,63},
							{18,65},{32,65},{9,68},{33,68},{6,71},{9,71},{18,71},{20,71},{35,71},{25,73},
							{28,73},{31,73},{9,79},{19,79},{4,81},{16,81},{35,81},{13,84},{13,87},{38,89},
							{2,93},{21,94},{11,95},{17,95},{6,97},{12,97},{33,97},{34,97},{11,98},{27,98} };

	int k = 0;
	int j = 0;

	int suma_max = 0;

	//szukanie odpowiedniej pary liczb
	for (int i = 0; i < n; i++)
	{
		int temp1 = 0;
		int temp2 = 0;
		int suma = 0;
		temp1 = pary_liczb[i][1];
		temp2 = pary_liczb[i][0];
		suma = temp1 + temp2;

		if (suma > suma_max)
		{
			suma_max = suma;
			k = temp1;
			j = temp2;

		}
	
	}

	//wyznaczenie liczb pseudolosowych za pomoc¹ metody addytywnej

	int *Y = stworzTablice_x1(n + 1);

	Y[0] = 0;

	for (int i = 0; i < n; i++)
	{
		Y[n - i] = liczby_pseudolosowe[i + 1];
	}

	for (int i = 0; i < n; i++)
	{
		Y[k] = (Y[j] + Y[k]) % m;

		k = k - 1;
		j = j - 1;

		if (k == 0)
			k = n;

		if (j == 0)
			j = n;
	}


	zapis_do_pliku(Y, n);

	return 0;
}

int zapis_do_pliku(int *liczby_pseudolosowe, int n)
{
	fstream file;
	file.open("liczby pseudolosowe.txt", ios::out);
	if (file.good() != true)
	{
		cout << "Blad pliku" << endl;

	}


	for (int i = 1; i <n+1 ; i++)
	{
		file << liczby_pseudolosowe[i];
		file << endl;
	}


	file.close();

	return 0;
}

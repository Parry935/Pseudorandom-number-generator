#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>

using namespace std;

/*funkcja zapisuj�ca liczby pseudolosowe do pliku tekstowego*/
int zapis_do_pliku(int *liczby_pseudolosowe, int n);

/*funkjca zwracaj�ca wska�nik do tablicy zawieraj�cej liczby pseudolosowe za pomoc� metody LCG*/
int *LCG(int &n, int &m);

/*funkcja kt�ra za pomoc� funkcji LCG tworzy liczby pseudolosowe*/
int AMK(int &n, int &m, int *liczby_pseudolosowe);

/*funkcja tworz�ca jednowymiarow� tablic� dynamiczn� - zwraca wska�nik do jej pierwszego elementu*/
int *stworzTablice_x1(int n);

/*funkcja w kt�rej podajemy dane wejsciowe - n i m*/
void cin_n_m(int &n, int &m);



#endif 

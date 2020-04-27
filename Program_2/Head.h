#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>

using namespace std;

/*funkcja zapisuj¹ca liczby pseudolosowe do pliku tekstowego*/
int zapis_do_pliku(int *liczby_pseudolosowe, int n);

/*funkjca zwracaj¹ca wskaŸnik do tablicy zawieraj¹cej liczby pseudolosowe za pomoc¹ metody LCG*/
int *LCG(int &n, int &m);

/*funkcja która za pomoc¹ funkcji LCG tworzy liczby pseudolosowe*/
int AMK(int &n, int &m, int *liczby_pseudolosowe);

/*funkcja tworz¹ca jednowymiarow¹ tablicê dynamiczn¹ - zwraca wskaŸnik do jej pierwszego elementu*/
int *stworzTablice_x1(int n);

/*funkcja w której podajemy dane wejsciowe - n i m*/
void cin_n_m(int &n, int &m);



#endif 

//program generuje graf nieskierowany
//Zwracanie grafu nie zostało jeszcze opracowane
#include "generator.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float los(float min, float max)//losowanie liczb rzeczywistych
{
	float przedzial=max-min;
	float x=RAND_MAX/przedzial;
	return min+(rand()/x);
}

void grafgen(int x, float k, float l)
{
	int pol[x], i, j, w, c=0, z=0, y=0;
	float tab[x][x];//tablica sąsiedztwa	
	srand(time(NULL));
	for(i=0; i<x; i++)//uzupełnianie tablicy sąsiedztwa liczbami "-1"
		for(j=0; j<x; j++)
			tab[i][j]=-1;
	for(i=0; i<x; i++)
	{//losowanie liczby przejść dla każdego węzła
		pol[i]=rand() % (x-1);
		/*do testów
		printf("\n%d\n", pol[i]);*/
	}

	for(i=0; i<x; i++)
	{

		for(j=0; j<x; j++)//zliczanie wykorzystanych przejść dla aktualnego węzła
			if(tab[i][j]!=-1)
				c++;
		
		while(pol[i]>c)//dopóki możliwe są przejścia dla aktualnego węzła
		{
			w=rand() % x;//losowanie węzła, do którego nastapić ma kolejne przejście
			if(pol[w]>0)// przejście do węzła "w" nastąpi jeżeli węzeł "w" ma możliwość dodania kolejnego połączenia
			{	
				while(tab[w][i]!=-1 && i!=w)//dopóki nie znajdzie liczby "-1" oraz nie będzie to liczba na diagonali
					w=rand() % (x-1);// losowany będzie  kolejny węzeł
				
				if(w!=i)//dodatkowe sprawdzenie, czy kolejny węzeł nie jest na diagonali
				{
					tab[w][i]=los(k, l);//wylosowanie wartości rzeczywistej z określonego przedziału
					tab[i][w]=tab[w][i];//wpisanie wylosowanej wartości do analogicznej komórki po drugiej stronie diagonali (graf nieskierowany)
					pol[i]--;//oznaczenie utworzenia połączenia poprzez zmniejszenie liczby możliwych przejść z danego węzłą
				}
			}
			y++;
			if(y>x)//zabezpieczenie dla małych grafów(<10), żeby program się przerywał w skrajnych przypadkach
				break;
		}
		y=0;
		c=0;
	}
	/*do testów*/
	for(i=0; i<x; i++)//wypisanie tablicy sąsiedztwa
	{
		printf("\n");
		for(j=0; j<x; j++)
			printf("%f ", tab[j][i]);
	}
	printf("\n");
	
	for(i=0; i<x; i++){
		for(j=0; j<x; j++)
			if(tab[j][i]==-1)
				z++;}
	printf("\nLiczba '-1' w grafie: %d\n", z);
	printf("\nŚrednia liczba przejść dla wierzchołka: %d\n", ((x*x)-z)/(x));/**/
}
/*do testów
int main()
{
	float a,b,c,i;
	scanf("%f %f %f", &a, &b, &c);
	printf("\n%f, %f, %f\n", a, b, c);
	grafgen(a, b, c);
	return 0;
}*/


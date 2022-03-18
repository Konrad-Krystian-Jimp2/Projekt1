//na razie generator generuje tylko graf. Zwracanie grafu przez funkcję zostanie dopracowane.
#include "generator.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float los(double min, double max)//losowanie liczb rzeczywistych
{
	float przedzial=max-min;
	float x=RAND_MAX/przedzial;
	return min+(rand()/x);
}

int grafgen(int w, int k, int l)
{
	float tab[w][w];//macierz sąsiedztwa
	int pol[w], i, j, x, c=0;
	
	srand(time(NULL));

	for(i=0; i<w; i++){
		for(j=0; j<w; j++){
			tab[i][j]=-1;}}
	
	for(i=0; i<w; i++)
		pol[i]=rand() % w;

	for(i=0; i<w; i++)
	{
		for(j=0; j<w; j++)
			if(tab[j][i]!=-1)
				c++;
		while(pol[i]>=c)
		{
			x=rand() % w;
			if(pol[x]>=-1)
			{	
				while(tab[x][i]!=-1 && i==x)
					x=rand() % w;
				
				if(x!=i)
				{
					tab[x][i]=los(k, l);
					tab[i][x]=tab[x][i];
					pol[i]--;
				}
			}
		}
		c=0;
	}
	/*do testów
	for(i=0; i<w; i++)
	{
		printf("\n");
		for(j=0; j<w; j++)
			printf("%f   ", tab[j][i]);
	}printf("\n");*/
	return 0;
}
/*do testów
int main()
{
	int a,b,c,i;
	scanf("%d %d %d", &a, &b, &c);
	printf("\n%d, %d, %d\n", a, b, c);
	grafgen(a, b, c);
	return 0;
}*/


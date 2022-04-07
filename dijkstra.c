#include "czytacz.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void dijkstra(char* plik, int pocz, int kon, int w, int k, graph_t ptr)
{
   	FILE* out= fopen(plik, "a");
	int i, j, dot=w*k, c, min, nast, ind=dot*dot;
	int ojciec=malloc(sizeof ojciec*(dot));
	int odw=malloc(sizeof odw*(dot));
	double **waga=malloc(sizeof **waga*(dot*dot));
	double **odleglosc=malloc(sizeof **odleglosc*(dot*dot));
	double **graf=malloc(sizeof **graf*(dot*dot));
	//ojciec przechowuje poprzednika każdego wierzchołka
	//c - liczba znalezionych połączeń

    	for(i=dot-1; i>=0; i--)
    		for(j=dot-1; j>=0; j--)
    		{
    			graf[i][j]=*ptr->graph;
    			ind--;
    		}

	for(i=0; i<dot; i++)//tworzenie macierzy wag
		for(j=0; j<dot; j++)
		{
			if(graf[i][j]==-1)
				waga[i][j]=INFINITY;
			else
				waga[i][j]=graf[i][j];
		}
	
	for(i=0; i<dot; i++)
	{
		odleglosc[i]=waga[pocz][i];
		ojciec[i]=pocz;
		odw[i]=0;
	}
	
	odleglosc[pocz]=0;
	odw[pocz]=1;
	c=1;
	
	while(c<dot-1)
	{
		min=NIESK;
		for(i=0; i<dot; i++)
			if(odleglosc[i]<min && !odw[i])
			{
				min=odleglosc[i];
				nast=i;
			}

		for(i=0; i<dot; i++)
			if(!odw[i])
				if(min+waga[nast][i]<odleglosc[i])
				{
					odleglosc[i]=min+waga[nast][i];
					ojciec[i]=nast;
				}
		c++;
	}
	double wartosc=0;
	for(i=0;i<dot;i++)
        if(i!=pocz)
        {
            wartosc+=odleglosc[i];
            j=i;
            while(j!=pocz)
            {
                j=ojciec[j];
                fprintf(out, "%d->", j);
            }
        }
    fprintf(out, "Wartość ścieżki %d -> %d: %f", pocz, kon, wartosc);
    
    free(odw);
    free(ojciec);
    free(odleglosc);
    free(graf);
    free(waga);
}

int main(int argc, char **argv)
{
	int pocz, kon, w, k;
	char napis="jedziemyxxxxxxxxxxxxxx";
	typedef struct e
	{
		double *graph;
		int w;
		int k;
	} graph_t

	return 0;
}

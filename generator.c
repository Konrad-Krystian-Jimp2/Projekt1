#include "generator.h"
#include "czytacz.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double los(double min, double max)//losowanie liczb rzeczywistych
{
	double przedzial=max-min;
	double x=RAND_MAX/przedzial;
	return min+(rand()/x);
}

double *grafgen(int w, int k, double p, double pk)
{
	int i, j, x, c=0, dot=w*k;
	int poli[dot];//tablica połączeń
	double tab[dot][dot];//macierz sąsiedztwa
	double *macierz;
	
	srand(time(NULL));
	
	for(i=0; i<dot; i++)
	{//uzupełnianie tablic "-1"
		for(j=0; j<dot; j++)
			tab[i][j]=-1;
		poli[i]=-1;
	}

	for(i=0; i<dot; i++)
	{//losowanie ilości połączeń.
	//PRZY STAŁYCH LICZBACH NIE MA PROBLEMÓW, ALE PRZY LOSOWANIU LICZB CZASAMI PĘTLA SIĘ NIE KOŃCZY PRZY OSTATNIM WIERSZU ANI GO NIE WYPISUJE
		if(i==0 || i==dot-k || i==k-1 || i==dot-1)
			poli[i]=2;//rand() % 3;
		if(i>0 && i<k-1)
			poli[i]=3;//rand() % 4;
		if(i>dot-k && i<dot-1)
		     poli[i]=3;//rand() % 4;
		if((i+1)%k==0)
		{
			if(poli[i]==-1)
				poli[i]=3;//rand() % 4;
			if(poli[i+1]==-1)
				poli[i+1]=3;//rand() % 4;
		}

		if(poli[i]==-1)
			poli[i]=4;//rand() % 5;;
	}
		
	for(j=0; j<dot-1; j++)
	{
		if(j<k && j!=0)
			if(tab[j-1][j]!=-1)
				c++;
		if(j%k==0 && j>=k)
			if(tab[j-k][j]!=-1)
				c++;
		if(j%k!=0 && j>=k)
		{
			if(tab[j-1][j]!=-1)
				c++;
			if(tab[j-k][j]!=-1)
				c++;
		}
		while(poli[j]-c>0)
		{
			if((j+1)%k!=0 && j<dot-k)
			{
				x=rand() % 2;
				if(x==0 && tab[j+1][j]==-1)
				{
					tab[j+1][j]=los(p, pk);
					tab[j][j+1]=tab[j+1][j];
					c++;
				}
				if(x==1 && tab[j+k][j]==-1)
				{
					tab[j+k][j]=los(p, pk);
					tab[j][j+k]=tab[j+k][j];
					c++;
				}
			}
			if((j+1)%k==0)
			{
				tab[j+k][j]=los(p, pk);
				tab[j][j+k]=tab[j+k][j];
				c++;
			}
			if(j>(dot-k-1) && j<dot-1)
				{
					tab[j+1][j]=los(p, pk);
					tab[j][j+1]=tab[j+1][j];
					c++;
				}	
		}
		c=0;
	}
	int ind=0;
	for(i=0; i<dot; i++)
		for(j=0; j<dot; j++)
		{
			macierz[ind]=tab[i][j];
			ind++;
		}

	return macierz;
}

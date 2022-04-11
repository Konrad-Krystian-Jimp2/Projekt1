#include <stdio.h>
#include "generator.h"
#include "czytacz.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	graph_t ptr3;
	int w=rand()%21;
	int k=rand()%21;
	int po=rand()%51;
	int pk=51+rand()%150;
	int dot=w*k, j, i;
	ptr3->rows=w;
	ptr3->columns=k;
	
	double *macierz=malloc((dot*dot)*sizeof(double));
	
	for(i=0; i<dot*dot; i++)
		macierz[i]=-1;

	ptr3->graph=grafgen(macierz, w, k, po, pk);
	printf("Wiersze: %d 	Kolumny: %d	Przedział wag: (%d, %d)\n", w, k, po, pk);
	WriteToFile("wyniki_testow_gen", ptr3);
	
	printf("\nWygenerowany graf w postaci macierzy sadiedztwa znajduje sie w pliku: wyniki_testow_gen\n");
	freeSpace(ptr3);
	free(macierz);
	return 0;

}

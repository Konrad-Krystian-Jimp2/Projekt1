#include <stdio.h>
#include <stdlib.h>
#include "generator.h"
#include "czytacz.h"

int main(int argc, char **argv)
{
	if(argc!=6 && argc!=2)
	{
		printf("Proszę podać nazwę pliku, liczbę wierszy, kolumn oraz liczby określające przedział losowania lub nazwę pliku, z którego dane te mają być odczytane");
		return(EXIT_FAILURE);
	}
	char *plik;
	int a, b;
	double c, d;
	FILE *in=fopen(argv[1], "r");
	FILE *out=fopen("log", "a");
	
	if(argc==1)
	{
		if(in==NULL)
		{
			fprintf(out, "\n[generator.c]: Nie udało się przeczytać pliku: %s\n", argv[1]);
			return(EXIT_FAILURE);
        	}
        	fscanf(in, "%d, %d, %le %le", &a, &b, &c, &d);
	}
	if(argc==6)
	{
	    plik=argv[1];
	    a=atoi(argv[2]);
	    b=atoi(argv[3]);
	    c=atof(argv[4]);
	    d=atof(argv[5]);
	}
	graph_t ptr = Make_Graph_Struct();
    MakeSpace_Graph(ptr, b, a);
    ptr->graph=grafgen(a, b, c, d);
    WriteToFile(argv[1], ptr);

	printf("\nWyniki testów znajdują się w pliku 'log'\n");
	return 0;
}

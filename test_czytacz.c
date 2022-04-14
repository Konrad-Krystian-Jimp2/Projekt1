#include <stdio.h>
#include <stdlib.h>
#include "czytacz.h"
#define MAX_SIZE 1024
int main(int argc, char** argv){

	

    if(argc != 2){
      fprintf(stderr,"\n\t Podaj plik z grafem i odczytaj wyniki w pliku  \tlog\n"
		"np: ./test_czytacz <source_file>\n\n" );
    exit(1);
    }
	
    FILE *out = fopen("log", "a");
    FILE *in = fopen(argv[1], "r");

    char BUF[MAX_SIZE];
    graph_t ptr = Make_Graph_Struct();

    ReadFromFile(argv[1], ptr);
    WriteToFile("log",ptr);


    fprintf(out,"\n\nWyniki powyzej, odczytywany plik [%s] ponizej :\n",argv[1]);
    fprintf(out,"Info: test czytacza.c, czyli test odczytywania pliku, zapisywaniu pliku, tworzenia struktury i alokacji pamięci. \n\n");
     while(fgets(BUF, MAX_SIZE, in) != NULL)
	    fprintf(out,"%s",BUF);


    printf("\n\n\t Wyniki testow znajduja sie w pliku \t 'log'\n\n\n");

return 0;	
}

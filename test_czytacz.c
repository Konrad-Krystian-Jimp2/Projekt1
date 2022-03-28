#include <stdio.h>
#include <stdlib.h>
#include "czytacz.h"

int main(int argc, char** argv){

	if(argc != 3){
	 fprintf(stderr,"Trzeba 2 pliki do testu\n");
	 exit(1);
 	}
	 graph_t ptr = malloc(sizeof*ptr);
	
	ptr->p = 2;
	ptr->q = 3;

	ptr->x = malloc(ptr->q*ptr->q*ptr->p*ptr->p*sizeof(ptr->x));
	
	FILE *in = fopen(argv[1], "r");
	double d;
	 
	 for(int i =0; i<36;i++)
		fscanf(in, "%lf", &ptr->x[i]);
	
	 for(int i =0; i<36;i++){
		if(i%6==0)
		printf("\n");
		printf("%0.16f", ptr->x[i]);
	 } 
printf("\n");
	
	 WriteToFile(argv[2],ptr);
printf("\n\n\t Wyniki testowania zapisywania zostaly zapisane do pliku \t %s\n\n",argv[2]);
 free(ptr->x);
 fclose(in); 
return 0;
}

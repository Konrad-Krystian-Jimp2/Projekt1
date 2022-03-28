#include <stdlib.h>
#include <stdio.h>
#include "czytacz.h"

void WriteToFile(char* file_name, graph_t ptr){

	int n = ptr->q*ptr->p;
	FILE* out = fopen(file_name, "w");

	fprintf(out,"%d %d", ptr->p, ptr->q);

	for(int j =0; j<n; j++){
		fprintf(out,"\n\t ");
		for(int i=0; i<n; i++)
			if(ptr->x[i+j*n] != -1)
			fprintf(out,"%d :%0.16f  ",i, ptr->x[i+j*n]); 		
	}
	fclose(out);
}		


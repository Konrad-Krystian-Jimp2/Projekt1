#include <stdio.h>
#include "queue.h"

int main(){

	ptr_t q = initQue();
	
	Enqueue(q, 0 );
	Enqueue(q, 17 );
	Enqueue(q, 4 );
	Enqueue(q, 2 );
	Enqueue(q, 99 );
	Enqueue(q, 1 );
	
	FILE* out = fopen("log", "a");
	fprintf(out,"\n\n\n @@@@@  Test queue:  @@@@ \n\n Inicjuje: \n"
		    " ptr_t q = initQue(); \n\n"
		    " Dodaje:\n"
		    " Enqueue(q, 0 );\n "
		    " Enqueue(q, 17 );\n "
	            " Enqueue(q, 4 );\n "
		    " Enqueue(q, 2 );\n "
		    " Enqueue(q, 99 );\n "
		    " Enqueue(q, 1 );\n\n "
		    "  	i wyjmuje wszystko dopóki !IsEmpty jest prawda, wyniki ponizej:\n\n");
	while(!IsEmpty(q))
	fprintf(out,"%d\n",Dequeue(q));	

fclose(out);	
freeQue(q);
}

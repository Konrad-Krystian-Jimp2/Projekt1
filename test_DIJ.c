#include <stdio.h>
#include <stdlib.h>
#include "czytacz.h"

				// NIE AKTUALNY, PONIEWAŻ DZIALA PRAWIDLOWO JUZ Z MAIN


int* dij( graph_t g);

int main( int argc, char** argv ){

	if(argc == 1){
	  printf("\n\tPodaj plik do czytania, od i do - DIJKSTRA: np.:  ./test_DIJ dane/mygraph 0 5\n\n");
	  return 1;
	}


     graph_t ptr2 = Make_Graph_Struct();
     ReadFromFile( argv[1] , ptr2 );

     int* path = dij( ptr2 );
	
     int from= atoi(argv[2]);
     int to= atoi(argv[3]);
     int temp;
     int n = ptr2->rows * ptr2->columns;
     int counter =0;
	     

	dij_t pd = malloc(sizeof *pd);
	




     for(int i =0; i<n; i++){
     	temp= path[to];
	  if( temp == -1 ){
		  fprintf(stderr,"Drogi nie ma i nie bedzie :( \n");
		  return 1;
          }
         fprintf(stderr,"%d -> %d\n", to, path[to]);
	 to = temp;
	 counter++;
	  if( to == from )
		  break;
	  if( counter == n-1 ){
		  fprintf(stderr,"Drogi nie ma i nie bedzie :( \n");
		  return 1;
  	  }
	}

	fprintf(stdout, "Koszt drogi: [%d --> %d] wynosi   %g\n", from, to,  );     

return 0;
}

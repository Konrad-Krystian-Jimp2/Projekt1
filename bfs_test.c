#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "czytacz.h"
#include "bfs.h"
//#define DEBUG
int main(int argc, char** argv){ 
	
     if(argc != 3){
       printf("Test BFS: podaj graf do odczytu oraz nr. wierzcholka do ktroego chcesz wyznaczyc : \n"
	      " sciezke, poczatek sciezki jest w zerowych wierzcholku\n"
	      " ./test_BFS   <file_name>    <toWhichVertex_int> \n\n"
	      "\t np: ./test_BFS  dane/graph2x3  5 \n\n");
     return 1;
     }

    FILE* out = fopen("log", "a");

     int f = atoi(argv[2]);
     graph_t ptr2 = Make_Graph_Struct();
     ReadFromFile( argv[1], ptr2 );
     int n = ptr2->rows * ptr2->columns; 
     int* path = BFS( ptr2 );
     fprintf(out, "\n\n\n@@@@@   TEST   BFS   @@@@@");

#ifdef DEBUG
	printf("\n\n Droga \n\n");
    for(int i=n-1; i>0; i--){
	    printf("poprzednikiem %d jest %d\n", i, path[i]);
    }
#endif  
	if( f > n-1 || f < 0){
	  fprintf(out, "\t\t\n\nNie ma takiego [%d] wierzcholka w tym grafie [%s] :( \n",f,argv[1]);
	  exit(1);
  	}	  


fprintf(out,"\n\n\nSzukam sciezki od 0 do %d droga:",f);
	fprintf(out,"\n koszt drogi path[n+wybrany] dla wybranego wierzchołka rowna sie: %d\n\n\n", path[n+f]);

	int temp;
	int counter=0;
	
	while(1){
	 temp= path[f];
	  if( temp == -1 ){
		  fprintf(out,"Drogi nie ma i nie bedzie :( \n");
		  return 1;
          }
         fprintf(out,"%d -> %d\n", f, path[f]);
	 f = temp;
	 counter++;
	  if( f == 0 )
		  break;
	  if( counter == n-1 ){
		  fprintf(out,"Drogi nie ma i nie bedzie :( \n");
		  return 1;
  	  }
	}	
	fprintf(out,"\n Koszt drogi to: %d\n", counter);
	fprintf(out,"\n Poprawność znalezionej sciezki można sprawdzić z dołączonymi w pliku obrazami [dane/obrazy]\n");


fclose(out);
free( path );
freeSpace( ptr2 );
return 0;
}

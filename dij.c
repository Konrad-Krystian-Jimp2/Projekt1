#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "czytacz.h"
#include "pqmin.h"
#include "dij.h"
#define BASE_SIZE 124

dij_t dij( graph_t g, int StartPoint, int DestPoint ){
    
    dij_t pd = malloc(sizeof *pd);
    pq_t q = init_pq(BASE_SIZE); 	
    int n = g->rows*g->columns;
    int visited[n]; //boolean imitation -> 0/1
    pd->path = malloc( n*sizeof * pd->path );
    pd->dist = malloc( n*sizeof * pd->dist );

    for(int i =0; i<n; i++){  //inicjacja
	    visited[i] = 0;
	    pd->path[i] = -1;
	    pd->dist[i] = INT_MAX;
    }


    visited[StartPoint] = 1;
    pd->dist[StartPoint] = 0;
    add_to_pq(q, StartPoint, pd->dist[StartPoint]);

    while (not_empty_pq(q)){  
        v_t node = pop_from_pq(q);
        for (int j = 0; j < n; j++){
            if(g->graph[j+(node->vert)*n] >= 0){
		if( ( pd->dist[j] > pd->dist[node->vert] + g->graph[j+(node->vert)*n] ) && ( visited[j] == 0 ) ){
		    pd->dist[j] = pd->dist[node->vert] + g->graph[j+(node->vert)*n];
		    add_to_pq(q, j, pd->dist[j]);		    	 	
		    pd->path[j] = node->vert;
		}	
            }
	}
     visited[node->vert] = 1;
      if(node->vert == DestPoint)
       return pd;
    }
    free_pq(q);
return pd;
}


void ShowPath( dij_t pd, int from, int to, int n ){
    
    FILE* out = fopen("wyniki", "w");
     if( out == NULL ){
	fprintf(stderr, "Nie udalo sie otworzyc pliku: wyniki\n");
    	exit(1);
     }
    
    if(n > 100)
      printf("\nCalkiem sporo tego! Rozwiazanie znajdziesz w pliku: \t'wyniki'\n\n"); 
    
    int counter =0;
    int temp;
    for(int i =0; i<n; i++){
      temp= pd->path[to];
	if( temp == -1 ){
    	  fprintf(n>100 ? out : stdout,"Drogi nie ma i nie bedzie :( \n");
          return;
        }
          fprintf(n>100 ? out : stdout,"%d -> %d\n", pd->path[to], to);
	  to = temp;
	    counter++;
     if( to == from )
       return;
     if( counter == n-1 ){
       fprintf(stderr,"Drogi nie ma i nie bedzie :( \n");
       return;
     }
    }


}

void freeDIJ( dij_t pd ){
	free(pd->path);
	free(pd->dist);
        free(pd);
}

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "czytacz.h"
//#define DEBUG

int* BFS( graph_t g){

    ptr_t q = initQue(); 	
    int n = g->rows*g->columns;
    int visited[n]; //boolean imitation -> 0/1
    int* path = malloc( n*sizeof *path );
    int start = 0;

#ifdef DEBUG    
    ShowMeMatrix(n,g);
#endif

    for(int i =0; i<n; i++){  //inicjacja
	    visited[i] = 0;
	    path[i] = -1;
    }
    int IfConst=0;
    visited[start] = 1;
    Enqueue(q, start);
    while (!IsEmpty(q)){  
        int node = Dequeue(q);
        for (int j = 0; j < n; j++){
            if(g->graph[j+node*n] >= 0 && visited[j] == 0){
		IfConst++;
#ifdef DEBUG		    
    fprintf(stderr,"I will move from %d to %d and ID:%d\n",node, j,j+node*n);
#endif

  		path[j] = node; 
	    	visited[j] = 1;
                Enqueue(q, j);        
            }
	} 
    }

#ifdef DEBUG
    printf("p: %d  n-1: %d\n", IfConst,n-1);
#endif

    if( IfConst != n-1 )
	printf("\n\tPodany graf jest \tniespojny.\n\n");
    else 
	printf("\n\tPodany graf jest \tspojny.\n\n");
   

    freeQue(q);
return path;
}

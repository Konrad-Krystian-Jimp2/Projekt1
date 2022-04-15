#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "komunikaty.h"
#include "czytacz.h"
#include "bfs.h"
#include "generator.h"
#include "dij.h"

int main(int argc, char *argv[]) {
    
	if(argc==1)
		Show_Error(1);
    	
    int opt;
    int if_BFS = 0, if_file_MG = 0, if_P = 0,if_Q =0, if_F = 0, if_T = 0, if_file_RG = 0, if_file_RN = 0, if_N = 0, if_spojny = 0;  // imitacja boolean 0- fałsz, 1- prawda czyli dane wystąpienie podczas wprowadzania danych 
    
    char* Make_Graph = NULL;
    char* Read_Nodes = NULL;
    char* Read_Graph = NULL;
    int p,q; // p - kolumny, q - wiersze
    int n, i;
    double k,l;



    static struct option long_options[] = {
        {"help",      no_argument,       0,  'h' },
        {"spojny",    no_argument,       0,  'l' },
        {"bfs",       no_argument,       0,  'b' },
        {"file",    required_argument,   0,  'z' },
        {0,           0,                 0,   0  }
    };

    int long_index =0;

    while ((opt = getopt_long(argc, argv,"hg:p:q:f:t:r:b:p:n:", 
                   long_options, &long_index )) != -1) {
        switch (opt) {
	     case 'h' : Show_Error(1);
		 break;
	     case 'g' : Make_Graph = optarg; if_file_MG++;
                 break;
	     case 'l' : if_spojny++;
                 break;
             case 'p' : if( !(atoi(optarg) - atof(optarg)) && atoi(optarg) > 1){   // sprawdzam czy calkowita i czy wieksza niz jeden
		 	p = atoi(optarg);
			if_P++;
			} else
			Show_Error(2);
                 break;
             case 'q' : if( !(atoi(optarg) - atof(optarg)) && atoi(optarg) > 1){   
		 	q = atoi(optarg);
			if_Q++;
			} else
			Show_Error(2);
                 break;
             case 'f' : if(atoi(optarg) < 0)
			Show_Error(7);
		 	k = atof(optarg); if_F++; 
                 break;
             case 't' : if(atoi(optarg) < 0)
			Show_Error(7);
		 	l = atof(optarg); if_T++;
                 break;
	     case 'r' : Read_Graph = optarg; if_file_RG++;
		 break;
	     case 'b' : if_BFS++;
		 break;
	     case 'z' : Read_Nodes = optarg; if_file_RN++;
		 break; 
	     case 'n' : if( !(atoi(optarg) - atof(optarg)) && atoi(optarg) >= 1){
			n = atoi(optarg);
			if_N++;
			} else
			Show_Error(6);	
		 break;
	     default:  	
        	Show_Error(4);
	}
    }
       


    if(if_F && if_T) // gdy początek przedziału jest większy niż koniec)
    	if(k>l)
     		Show_Error(3);

    if(if_file_MG && if_P && if_Q && (!if_F  || !if_T)) // gdy nie podano przedziału wagowego
     	Show_Error(8);

    if(!if_file_MG && if_F && if_T && if_P && if_Q) //gdy nie podano -g a podano resztę
     	Show_Error(5);

    if(p*q>40000){
	    Show_Error(10);
	    return 0;
    }
    if(if_file_MG && if_F && if_T && if_P && if_Q && !if_file_RG && p*q<=40000){

		printf("\t Generowanie grafu\n");  
      		graph_t ptr = Make_Graph_Struct();
      		MakeSpace_Graph(ptr, p, q);
      		ptr->graph=grafgen(ptr->graph, p, q, k, l, if_spojny);
      		WriteToFile(Make_Graph, ptr);
		printf("Wygenerowany graf znajduje się w: \t %s\n",Make_Graph );
	    

	if(if_BFS){    // gdy sprawdzanie spojnosc, jezeli szukanie to rowniez if(if_BFS && if_N && if_file_RN)  czyli liczba szukanych par oraz info jakie to pary.
	//uzycie BFS
		int* pathBFS = BFS( ptr );
		if( pathBFS == NULL ){
     	     		free(pathBFS); 
             		exit(EXIT_FAILURE);
           	}	  
	free(pathBFS); 

	}

	//if(if_N && if_file_RN ...   -> Dijkstra
	if(if_N && if_file_RN){
		int* Nodes = ReadNodesFromFile( Read_Nodes, n, ptr ); 
	
		for(int z=0;z<n;z++){
			printf("Szukam sciezki z \t%d --- do --- > %d \n", Nodes[z*2], Nodes[z*2+1]);
			dij_t pd = dij( ptr, Nodes[z*2], Nodes[z*2+1] );
			double tem = ShowPath( pd, Nodes[z*2], Nodes[z*2+1], ptr->columns * ptr->rows );
			  if(tem != -1)
			    printf("Waga tej sciezki to: %g\n\n\n",tem);
			freeDIJ(pd);	
		}

		free(Nodes);
      	}	
        freeSpace(ptr);
	return 0;
    }

    

    if(if_file_RG && !if_file_MG && !if_F && !if_T && !if_P && !if_Q && !if_spojny){
     graph_t ptr2 = Make_Graph_Struct();
     ReadFromFile( Read_Graph, ptr2 );
         
       if( if_BFS ){
         int* pathBFS = BFS( ptr2 );
           if( pathBFS == NULL ){
     	     free(pathBFS); 
             exit(EXIT_FAILURE);
           }	  
       free(pathBFS); 
       }

      if(if_N && if_file_RN){
     	 int* Nodes = ReadNodesFromFile( Read_Nodes, n, ptr2 ); 
	
        for(int z=0;z<n;z++){
	  printf("Szukam sciezki z \t%d --- do --- > %d \n", Nodes[z*2], Nodes[z*2+1]);
		dij_t pd = dij( ptr2, Nodes[z*2], Nodes[z*2+1] );
		  double tem = ShowPath( pd, Nodes[z*2], Nodes[z*2+1], ptr2->columns * ptr2->rows );
		    if(tem != -1)
		      printf("Waga tej sciezki to: %g\n\n\n",tem);
		freeDIJ(pd);	
	}

      free(Nodes);
      }	
     	
      freeSpace(ptr2);
      return 0;
      }

	
    Show_Error(9); // Nie podano prawidlowej konfiguracji argumentow
    Show_Error(1); // help
    return 1;
}

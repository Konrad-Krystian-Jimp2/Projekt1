#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "komunikaty.h"


int main(int argc, char *argv[]) {
    
	if(argc==1)
	Show_Error(1);
	
    int opt;
    int if_BFS = 0, if_file_MG = 0, if_W = 0, if_F = 0, if_T = 0, if_file_RG = 0, if_file_RN = 0, if_N = 0; 
    
    char* Make_Graph = NULL;
    char* Read_Nodes = NULL;
    char* Read_Graph = NULL;
    int x;
    int k;
    int l;
    int n;



    static struct option long_options[] = {
        {"help",      no_argument,       0,  'h' },
        {"bfs",       no_argument,       0,  'b' },
        {"file",    required_argument,   0,  'p' },
        {0,           0,                 0,   0  }
    };

    int long_index =0;

    while ((opt = getopt_long(argc, argv,"hg:w:f:t:r:b:p:n:", 
                   long_options, &long_index )) != -1) {
        switch (opt) {
	     case 'h' : Show_Error(1);
		 break;
	     case 'g' : Make_Graph = optarg; if_file_MG++;      
                 break;
             case 'w' : if( !(atoi(optarg) - atof(optarg)) && atoi(optarg) > 1){   // sprawdzam czy calkowita i czy wieksza niz jeden
		 	x = atoi(optarg);
			if_W++;
			} else
			Show_Error(2);
                 break;
             case 'f' : if(atoi(optarg) < 0)
			Show_Error(7);
		 	k = atoi(optarg); if_F++; 
                 break;
             case 't' : if(atoi(optarg) < 0)
			Show_Error(7);
		 	l = atoi(optarg); if_T++;
                 break;
	     case 'r' : Read_Graph = optarg; if_file_RG++;
		 break;
	     case 'b' : if_BFS++;
		 break;
	     case 'p' : Read_Nodes = optarg; if_file_RN++;
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
       


    if(if_F && if_T)
     if(k>l)
     Show_Error(3);

    if(!if_file_MG && if_F && if_T && if_W)
     Show_Error(5);

        
    if(if_file_MG && if_F && if_T && if_W){   
    // generowanie grafu       
	
	if(if_BFS){    // gdy sprawdzanie spojnosc, jezeli szukanie to rowniez if(if_BFS && if_N && if_file_RN)  czyli liczba szukanych par oraz info jakie to pary.
	//uzycie BFS
	}

	//if(if_N && if_file_RN ...   -> Dijkstra
		
    }

    

    if(if_file_RG){
    //czytanie grafu
	     
		    
    
    }

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "czytacz.h"
#define MAX_SIZE 1024
//#define DEBUG

graph_t Make_Graph_Struct(){
    
    graph_t ptr = malloc( sizeof *ptr );
     if( ptr == NULL ){
       fprintf(stderr, "\t[czytacz.c]: Pamiec nie moze zostac zaalokowana\n");
       exit(EXIT_FAILURE);     
     }

    return ptr;
}

void MakeSpace_Graph( graph_t ptr, int p, int q ){
     
     ptr->rows = q;
     ptr->columns = p;
    
     int SIZE = ptr->rows * ptr->rows * ptr->columns * ptr->columns;

     ptr->graph = malloc( SIZE * sizeof(ptr->graph));
      if( ptr->graph == NULL ){
        fprintf(stderr, "\t[czytacz.c]: Pamiec nie moze zostac zaalokowana\n");	
        exit(EXIT_FAILURE);
      }

     for(int i =0; i<SIZE; i++)  // inicjalizacja grafu wartościami -1
	ptr->graph[i] = -1;
    
}

void freeSpace(graph_t ptr){
    free(ptr->graph);
    free(ptr);
}


void WriteToFile(char* file_name, graph_t ptr){

    int n = ptr->rows*ptr->columns;
    FILE* out = fopen(file_name, "w");
     if( out == NULL ){
       fprintf(stderr, "\t[czytacz.c]: Nie udalo sie otworzyc pliku:\t%s\n",file_name);
       exit(EXIT_FAILURE);
     }       

    fprintf(out,"%d %d", ptr->columns, ptr->rows);
      for(int j =0; j<n; j++){
	 fprintf(out,"\n\t ");
	   for(int i=0; i<n; i++)
	     if(ptr->graph[i+j*n] != -1)
	       fprintf(out,"%d :%0.16f  ",i, ptr->graph[i+j*n]); 		
      }
   fclose(out);
}		

void ReadFromFile(char* file_name, graph_t ptr){

    FILE* in = fopen(file_name, "r");
     if( in == NULL ){
       fprintf(stderr, "\t[czytacz.c]: Nie udalo sie otworzyc pliku z grafem :\t%s\n",file_name);
       exit(EXIT_FAILURE);	
     }

     int tempColumns, tempRows; 

     if(fscanf(in,"%d %d\n", &tempColumns, &tempRows) != 2){
	fprintf(stderr, "[czytacz.c]: Zly format pliku z grafem\n");
 //	fprintf(stderr, "\t[czytacz.c]: Nie udalo sie przeczytac ilosci wezlow\n");
        exit(EXIT_FAILURE);
     }

     MakeSpace_Graph(ptr, tempColumns, tempRows);

     int n = ptr->columns * ptr->rows;
     char BUF[MAX_SIZE];
     int i = 0;	
     int HowManyNumbersInRow = 0; // ile liczb do oczytania w linii
     int HowManyRows = 0;  // ile jest lini do czytania
     int NumbersInLine[n];  // przechowuje informacje ile jest liczb do odczytu w poszczególnej linii
     int ifallempty = 0; // sprawdza czy wszyskie linie nie sa puste (nie maja ':')
     int iftoobig = 0; // segfoult gdy ktos sie pomyli w rozmiarach

    while( fgets(BUF, MAX_SIZE, in) != NULL ){
	while( BUF[i] != '\n' ) {
 	   if( BUF[i] == ':' )      // każde wystąpienie ":" oznacza informację do oczytu
     	     HowManyNumbersInRow++;
	i++;	   
 	}
#ifdef DEBUG	
     printf("%s",BUF);
     printf("HowManyNumbersInRow = %d\n", HowManyNumbersInRow);
     printf("WhichRow = %d\n\n\n", HowManyRows);
#endif  
    NumbersInLine[HowManyRows] = HowManyNumbersInRow;
   	 
       HowManyRows++;

       if( HowManyRows > n ){ // czyta wiecej niz jest na to miejsca, czyli blad przy podawaniu danych  
	fprintf(stderr, "[czytacz.c]:  Zly format pliku z grafem (sprawdz poprawnosc podawanych wymiarow grafu) \n");
	exit(EXIT_FAILURE);
       }

       if( HowManyNumbersInRow == 0 )
	  ifallempty++;
    i=0;	
    HowManyNumbersInRow =0;
    }
      if(ifallempty == HowManyRows){
	fprintf(stderr, "[czytacz.c]: ! Zly format pliku z grafem\n");
	exit(EXIT_FAILURE);
      }
       


    fseek(in,4,SEEK_SET); // cofnięcie się na początek pliku (w miejsce po liczbach kolumn i wierszy)

    int tempWhereConnection;
    double tempValue;

	for(int x=0; x<HowManyRows; x++)
          for(int k=0; k<NumbersInLine[x]; k++){
	      if(fscanf(in, "%d :%lf", &tempWhereConnection, &tempValue)!= 2){
		 fprintf(stderr, "[czytacz.c]: Zly format pliku z grafem\n");
		   exit(EXIT_FAILURE);
	      }
      	    
#ifdef DEBUG	      
    printf("Row: %d, Column: %d and Value: %lf\n", x, tempWhereConnection, tempValue);
#endif	    
	      ptr->graph[x*n + tempWhereConnection] = tempValue;
	  }
#ifdef DEBUG
    ShowMeMatrix(n,ptr);
#endif
    fclose( in );

}

int* ReadNodesFromFile(char* file_name, int n, graph_t ptr){

    FILE* in = fopen(file_name,"r");
	 if( in == NULL ){
  	   fprintf(stderr,"[czytacz.c]: Nie udalo sie otworzyc pliku z wierzcholkami\n");
	   exit(EXIT_FAILURE);
	 }
	 
    int* NodesToFind = malloc( n * sizeof*NodesToFind );
    	 if( NodesToFind == NULL ){
	   fprintf(stderr,"[czytacz.c]: Nie udalo sie zaalokowac pamieci na wierzcholki\n");
	   exit(EXIT_FAILURE);
	 }

    for(int i=0; i<n*2; i++){
	 if(fscanf(in,"%d", &NodesToFind[i]) != 1 ){
	   fprintf(stderr,"[czytacz.c]: Zly format pliku z wierzcholkami lub bledna infomracja o ilosci drog do znalezienia '%d'\n", n);
	   exit(EXIT_FAILURE);
	 }
    }

    for(int i =0; i<2*n; i++)
	  if( NodesToFind[i] < 0 || NodesToFind[i] >= ptr->rows * ptr->columns ){
	    fprintf(stderr, "[czytacz.c]: Nie da sie znalezc drogi z badz do tego wierzcholka: [ %d ] \n",NodesToFind[i]);
    	    exit(EXIT_FAILURE);
	  }

return NodesToFind;
}


void ShowMeMatrix(int n, graph_t ptr){
	
    for(int j =0; j<n*n; j++){
      if(j%n == 0)
       printf("\n");
	printf("%lf ",ptr->graph[j]);
    }
    printf("\n");
}	


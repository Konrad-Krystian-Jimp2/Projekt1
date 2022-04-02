#ifndef _CZYTACZ_H_
#define _CZYTACZ_H_

typedef struct e{
	double* graph;
	int columns;
	int rows;
} *graph_t;

graph_t Make_Graph_Struct();

void MakeSpace_Graph( graph_t ptr, int p, int q );

void ShowMeMatrix(int n, graph_t ptr);

void freeSpace(graph_t ptr);

void WriteToFile(char* file_name, graph_t ptr);

void ReadFromFile(char* file_name, graph_t ptr);

#endif

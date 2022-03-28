#ifndef _CZYTACZ_H_
#define _CZYTACZ_H_

typedef struct e{
	double* x;
	int p;
	int q;
} *graph_t;

void WriteToFile(char* file_name,graph_t ptr);

#endif

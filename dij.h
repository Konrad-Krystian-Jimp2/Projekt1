#ifndef _DIJ_H_
#define _DIJ_H_

typedef struct p {
	int* path;
	double* dist;
} * dij_t;

dij_t dij( graph_t g, int StartPoint, int DestPoint );
double ShowPath( dij_t pd, int from, int to, int n );
void freeDIJ(dij_t pd);

#endif

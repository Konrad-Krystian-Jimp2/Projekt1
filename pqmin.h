#ifndef _PQ_H_
#define _PQ_H_
typedef struct { 
	int vert; // numer indeksu
	double dist; // dystans
} * v_t;


typedef struct {
	v_t *q;  // the queue of v_t
	int n;      // actual # of doubles in it
	int s;      // it's size
} * pq_t;


pq_t init_pq( int size );

void add_to_pq( pq_t pq, int vert, double dist );

int not_empty_pq( pq_t pq );

v_t pop_from_pq( pq_t pq );

void free_pq( pq_t pq );

#endif

#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

int main(){

	pq_t q = init_pq( 10 );

	add_to_pq(q,0, 0 );
	add_to_pq(q,1, 4);
	add_to_pq(q,2, 3 );
	add_to_pq(q,3, 4 );
	add_to_pq(q,4, 5 );
	add_to_pq(q,5, 6 );
	add_to_pq(q,7, 1);

	while( not_empty_pq(q) ){
		v_t d = pop_from_pq(q);
		
		printf(" wyjmuje wierzcholek o indx --> %d i o wadze: %g\n", d->vert, d->dist );
	}

	free_pq(q);

return 0;
}

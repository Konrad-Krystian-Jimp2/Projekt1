#include "czytacz.h"
#include "generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double los(double min, double max)//losowanie liczb rzeczywistych
{
	double przedzial=max-min;
	double x=RAND_MAX/przedzial;
	return min+(rand()/x);
}

double *grafgen(double *graf, int w, int k, double po, double pk)
{
	int i, j, dot=w*k, x;
	//double *graf=malloc((dot*dot)*sizeof(double));
	//double *graf=graph;
	srand(time(NULL));

	/*for(i=0; i<dot*dot; i++)
		graf[i]=-1;*/

	for(i=0; i<dot; i++)
	{
		if((i+1)%k==0 && i<dot-1)
		{
			x=rand()%2;
			if(x==1)
			{
				graf[i+((i+k)*dot)]=los(po, pk);
				graf[(i+k)+i*dot]=graf[i+((i+k)*dot)];
			}
		}
		if(i>=dot-k && i<dot-1)
		{
			x=rand()%2;
			if(x==1)
			{
				graf[(i+1)+i*dot]=los(po, pk);
				graf[i+(i+1)*dot]=graf[(i+1)+i*dot];
			}
		}
		if(i<dot-k && (i+1)%k!=0)
		{
			x=rand()%3;
			if(x==2)
			{
				graf[i+((i+k)*dot)]=los(po, pk);
				graf[(i+k)+i*dot]=graf[i+((i+k)*dot)];
				graf[(i+1)+i*dot]=los(po, pk);
				graf[i+(i+1)*dot]=graf[(i+1)+i*dot];
			}
			if(x==1)
			{
				x=rand()%100;
				if(x<50)
				{
					graf[i+((i+k)*dot)]=los(po, pk);
					graf[(i+k)+i*dot]=graf[i+((i+k)*dot)];
				}
				if(x>=50)
				{
					graf[(i+1)+i*dot]=los(po, pk);
					graf[i+(i+1)*dot]=graf[(i+1)+i*dot];
				}
			}
		}
	}
	return graf;
	free(graf);
}

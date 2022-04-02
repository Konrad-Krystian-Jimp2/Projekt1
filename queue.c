#define INIT_SIZE 1512
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//#define DEBUG

ptr_t initQue(){
	ptr_t q_t = malloc(sizeof(q_t));
	q_t->que = malloc( INIT_SIZE * sizeof( *q_t->que ));
	  if(q_t->que == NULL){
            fprintf(stderr, "[queue.c]: Nie udalo sie zaalokowac pamieci\n");
	    exit(4);
	  }

	q_t->front = -1;
	q_t->rear = -1;
	q_t->HowMany = 0;
	q_t->SIZE = INIT_SIZE;

return q_t;
}

int IsFull(ptr_t q_t){
	if( q_t->HowMany -1 == q_t->SIZE)
		return 1;
	else 
		return 0;
}
void DoubleSize(ptr_t q_t){

	q_t->SIZE *=2;
	q_t->que = realloc(q_t->que, q_t->SIZE*sizeof(*q_t->que));

#ifdef DEBUG
 printf("x2\n");	
#endif
}

int IsEmpty(ptr_t q_t){
	if( q_t->front == -1 && q_t->rear == -1)
		return 1;
	else
		return 0;
}

void Enqueue(ptr_t q_t, int val){
	if( IsFull(q_t) )
		DoubleSize(q_t);
	else if( IsEmpty(q_t) ){
		q_t->front=q_t->rear = 0;
		q_t->que[q_t->rear] = val;
		q_t->HowMany++;
	} else {
	q_t->rear++;
	q_t->HowMany++;
	}
	q_t->que[q_t->rear] = val;
}

int Dequeue(ptr_t q_t){
	if( IsEmpty(q_t) )
		return -1;
	else if( q_t->front == q_t->rear ){
		int temp2 = q_t->que[q_t->rear];
		q_t->front=q_t->rear = -1;
		return temp2;
	}
	else{
		int temp = q_t->que[q_t->front];
		q_t->front++;
		return temp;
	}
}

void freeQue(ptr_t q_t){
	free(q_t->que);
	free(q_t);
}

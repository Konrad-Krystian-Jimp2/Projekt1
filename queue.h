
typedef struct q{
	int* que;
	int front;
	int rear;
	int HowMany;
	int SIZE;
} *ptr_t;


ptr_t initQue();
int IsFull(ptr_t q_t);
void DoubleSize(ptr_t q_t);
int IsEmpty(ptr_t q_t);
void Enqueue(ptr_t q_t, int val);
int Dequeue(ptr_t q_t);
void freeQue(ptr_t q_t);

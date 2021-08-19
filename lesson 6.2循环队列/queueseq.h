#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXQUEUE 50 

typedef int Status;
typedef int Elem_type;

typedef struct Sqqueue{
	Elem_type  *base;
	int front;
	int rear;	
}squeue;

Status initqueue(squeue *);
Status isempty(squeue);
Status isfull(squeue);
Status inqueue(squeue *,Elem_type);
Status dequeue(squeue *,Elem_type *);
Status getfront(squeue,Elem_type *);
Status traversequeue(squeue);

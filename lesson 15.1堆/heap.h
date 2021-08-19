#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXHEAPSIZE 100

typedef int Status;
typedef int Elemtype;

typedef struct heapelem{
	Elemtype key;
}Heapelem;

typedef struct minheap{
	Heapelem data[MAXHEAPSIZE];
	int size;	
}Minheap;

void shiftdown(Minheap *,int,int);
void shiftup(Minheap *,int);
void createheap(Minheap *,Heapelem *,int);
void traverseheap(Minheap);
Status insert(Minheap *,Heapelem);
Status deletemin(Minheap *,Heapelem *);

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int Elem_type;


typedef struct Linknode{
	Elem_type data;
	struct Linknode *next;
}linknode,* linode;

typedef struct Linkqueue{
	linode front;
	linode rear;
}linkqueue;

Status initqueue(linkqueue *);
Status isemptyqueue(linkqueue);
Status traverse(linkqueue);
Status enqueue(linkqueue *,Elem_type);
Status dequeue(linkqueue *,Elem_type *);
Status gettop(linkqueue,Elem_type *);

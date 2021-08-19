#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLO -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int Elem_type;
typedef struct elem{
	Elem_type key;
}Elem;

typedef struct Seq{
	Elem *elem;
	int length;
	int size;
}seq;


Status initlist(seq *);
Status listinsert(seq *,int,Elem_type);
Status listtraverse(seq);
int bisearch(seq *,Elem_type);
int rebisearch(seq *,Elem_type,int,int);

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAXSIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int Elem_type;
typedef struct elem{
	Elem_type key;
	int cur;
}Elem;

Elem L[MAXSIZE];
Status initlist(Elem *);
int malloclist(Elem *);
int freelist(Elem *,int);
Status listinsert(Elem *,int,Elem_type);
Status listdelete(Elem *,int,Elem_type *);
Status listtraverse(Elem *);
int listlength(Elem *);
int listsearch(Elem *,Elem_type);

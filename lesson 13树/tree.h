#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char Elem_type;

typedef struct binode{
	Elem_type data;
	struct binode *leftchild,*rightchild;
}Binode,* Bitree;

typedef struct Linknode{
	Bitree data;
	struct Linknode *next;
}linknode,* linode;

typedef struct Linkqueue{
	linode front;
	linode rear;
}linkqueue;

typedef struct Linkstack{
	Bitree data;
	struct Linkstack *next;
}linkstack,* listack;

Status initqueue(linkqueue *);
Status isemptyqueue(linkqueue);
Status enqueue(linkqueue *,Bitree);
Status dequeue(linkqueue *,Bitree *);

Status initlink(listack *);
Status isemptylink(listack);
Status pushlink(listack *,Bitree);
Status poplink(listack *,Bitree *);

Status createbitree(Bitree *);
Status destroytree(Bitree *);
Status pretraverse(Bitree);
Status intraverse(Bitree);
Status posttraverse(Bitree);
Status leveltraverse(Bitree);
int heighttree(Bitree);
int allnodes(Bitree);
int leaves(Bitree);
Status traverstarget(Bitree,int,Elem_type *,int *);
Status deletetarget(Bitree *,Elem_type);
int similartrees(Bitree,Bitree);

//11.25
Status pretraverseno(Bitree);
Status intraverseno(Bitree);

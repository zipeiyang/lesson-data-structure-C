#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define N 100

typedef int Status;
typedef struct fnode{
	int weight;
	int parent,lchild,rchild;
}FNode;

typedef struct ftree{
	FNode F[2*N-1];
	int size;
}FTree;

typedef int Elem_type;

typedef struct Linkstack{
	Elem_type data;
	struct Linkstack *next;
}linkstack,* listack;

Status initlink(listack *);
Status isemptylink(listack);
Status pushlink(listack *,Elem_type);
Status poplink(listack *,Elem_type *);

void createtext(char *,char *,int *,int *);
void selectmin(FTree,int *,int *);
Status createftree(FTree *,int *,int);
float getwpl(FTree);
void setcode(FTree,char *);
void decode(FTree,char *);


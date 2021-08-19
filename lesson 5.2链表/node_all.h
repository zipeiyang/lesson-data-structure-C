#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLO -1

typedef int Status;
typedef int Elem_type;

typedef struct LNode{
	Elem_type data;
	struct LNode *next;
}linknode,* linklist;

typedef struct elem{
	float xi;
	int zhi;
}Elem;

typedef struct Pnode{
	Elem data;
	struct Pnode *next;
}polynode,* polylist;

Status initnode(linklist *);
Status insertnode(linklist,int,Elem_type);
Status deletenode(linklist,int,Elem_type *);
Status createnode(linklist);
Status traversnode(linklist);
//10.10
int length(linklist);
Status locatenode(linklist,Elem_type);
Status priornode(linklist,Elem_type,Elem_type *);
Status nextnode(linklist,Elem_type,Elem_type *);
Status clearnode(linklist);
Status destroynode(linklist); 
Status mergenode(linklist,linklist,linklist *);
Status initpoly(polylist *);
Status createpoly(polylist);
Status traverspolynode(polylist);
Status addpolynode(polylist,polylist,polylist *);
float sumpolynode(polylist,int);

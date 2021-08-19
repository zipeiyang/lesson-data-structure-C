#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXVALUE INT_MAX
#define NUMVERTEX 50

int visited[NUMVERTEX];
int visited_sec[NUMVERTEX];

typedef int Status;
typedef char vdata;
typedef int edata;

//邻接矩阵 
typedef struct graph{
	vdata vertex[NUMVERTEX];
    edata edge[NUMVERTEX][NUMVERTEX];
	int n;//具体顶点数 
	int e;//具体边数 
}Graph;

//邻接表 
typedef struct enode{
	int dest;
	edata cost;
	struct enode *next;
}Enode;

typedef struct vnode{
	vdata data;
	Enode *first;
}Vnode;

typedef struct adjgraph{
	Vnode vertexlist[NUMVERTEX];
	int n;
	int e;
}Adjgraph;

//队列 
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
Status enqueue(linkqueue *,Elem_type);
Status dequeue(linkqueue *,Elem_type *);

//邻接矩阵 
Status creategraph(Graph *);
Status isempy(Graph);
void printgraph(Graph);
int getfirst(Graph,int);
int getnext(Graph,int,int);
void dfs(Graph,int);
void traverse(Graph);
void bfs(Graph,int);
void traverse_sec(Graph);

//邻接表
Status createlist(Adjgraph *);
Status isempylist(Adjgraph);
void printlist(Adjgraph);

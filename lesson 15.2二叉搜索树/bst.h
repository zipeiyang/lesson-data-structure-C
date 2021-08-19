#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int Elemtype;

typedef struct bstnode{
	Elemtype data;
	struct bstnode *lchild,*rchild;
}BSTnode,* BST;

void find(BST,Elemtype,BST *,BST *);
void insert(BST *,Elemtype);
void createbst(BST *);
Status intraverse(BST);



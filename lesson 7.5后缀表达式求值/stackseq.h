#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLO -2

#define LIST_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;
typedef char Elem_type;

typedef struct Sqstack{
	Elem_type *base;
	Elem_type *top;
	int stacksize;	
}sqstack;

Status initstack(sqstack *);
Status isemptystack(sqstack);
Status pushstack(sqstack *,Elem_type);
Status popstack(sqstack *,Elem_type *);
Status gettop(sqstack,Elem_type *);
Status traverse(sqstack);
Status clearstack(sqstack *);
Status destroystack(sqstack *);

//10.24
Status isnum(Elem_type);
Elem_type compute(Elem_type,Elem_type,Elem_type);
Status evaluatestack(char *); 

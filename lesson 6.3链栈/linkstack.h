#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int Elem_type;

typedef struct Linkstack{
	Elem_type data;
	struct Linkstack *next;
}linkstack,* listack;

Status initlink(listack *);
Status isemptylink(listack);
Status traverse(listack);
Status pushlink(listack *,Elem_type);
Status poplink(listack *,Elem_type *);
Status gettop(listack,Elem_type *);

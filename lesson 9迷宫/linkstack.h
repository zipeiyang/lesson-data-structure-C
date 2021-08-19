#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2



typedef int Status;
typedef int Elem_type;

typedef struct elemtype{
	int x;
	int y;
}Elemtype;

typedef struct Linkstack{
	Elemtype data;
	struct Linkstack *next;
}linkstack,* listack;

typedef struct gridtype{
	Elemtype pos;
	char data;
	int direct;
}Gridtype;

Gridtype maze[10][10];

Status initlink(listack *);
Status isemptylink(listack);
Status traverse(listack);
Status pushlink(listack *,Elemtype);
Status poplink(listack *,Elemtype *);
Status gettop(listack,Elemtype *);

//11.2
void nextgrid(Elemtype *);
int gostep(Elemtype *);
void print();
Status search(Elemtype,Elemtype);

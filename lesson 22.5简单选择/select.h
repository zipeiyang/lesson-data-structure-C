#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAXSIZE 100

typedef int Status;
typedef int Elem_type;
typedef struct data{
	Elem_type key;
	//other data;	
}element;

typedef struct seqlist{
	element E[MAXSIZE];
	int length;
}Seqlist;

Status select(Seqlist *);
void traverse(Seqlist);

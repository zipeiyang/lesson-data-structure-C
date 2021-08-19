#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_ARRAY_DIM 8

typedef int Status;
typedef int Elem_type;

typedef struct array{
	int m;
	int n;
	Elem_type **A;
}Array;

Status initarray(Array *,int,int);
Status createarray(Array *);
Status destroyarray(Array *);
Status printarray(Array);
Status transmatrix(Array,int *);
Status printmatrix(int *,int);
Status transarray(int *,Array,int);

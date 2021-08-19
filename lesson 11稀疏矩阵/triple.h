#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_SIZE 4096

typedef int Status;
typedef int Elem_type;

typedef struct triple{
    int row;
    int col;
    Elem_type value;      
}Triple;

typedef struct matrix{
	int m;
	int n;
	int num;
	Triple data[MAX_SIZE];
}Matrix;

Status initmatrix(Matrix *);
Status printmatrix(Matrix);
Status transposematrix_fir(Matrix,Matrix *);
Status transposematrix_sec(Matrix,Matrix *);

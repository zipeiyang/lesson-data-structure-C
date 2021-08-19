#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLO -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int Elem_type;
typedef struct Seq{
	Elem_type *elem;
	int length;
	int size;
}seq;
typedef struct elem{
	float xi;
	int zhi;
}Elem;
typedef struct Polyseq{
	Elem *elem;
	int count;
	int size;
}polyseq;


Status initlist(seq *);
Status destroylist(seq *);
Status clearlist(seq *);
Status emptylist(seq);
int lengthlist(seq);
Status getelem(seq,int,Elem_type *);
Status locateelem(seq,Elem_type);
Status priorelem(seq,Elem_type,Elem_type *);
Status nextelem(seq,Elem_type,Elem_type *);
Status listdelete(seq *,int,Elem_type *);

Status listinsert(seq *,int,Elem_type);
Status listtraverse(seq);
//10.10
Status mergelist(seq,seq,seq *);

Status initpolyseq(polyseq *);
Status seqinsert(polyseq *,int,Elem);
Status polytraverse(polyseq);
Status addseq(polyseq,polyseq,polyseq *);
float sumseq(polyseq,int);

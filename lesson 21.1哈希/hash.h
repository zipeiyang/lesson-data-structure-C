#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAXSIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int Key_type;

typedef struct datatype{
	Key_type key;
	int flag;
}Data_type;

typedef struct hash{
	Data_type *data;
	int size;
	int cursize;
}Hash;

Key_type hashfunction(Key_type);
int find(Hash *,Key_type,int *);
int insert(Hash *,Data_type);
Status create(Hash *,int,int *,int);
void traverse(Hash);
float calculate(Hash);

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"bisearch.h"

int main()
{
	seq A;
	printf("��ʼ���б�A\n");
	initlist(&A);
	int f;
	Elem_type g;
	printf("\n����A(-111 ends)��");
	scanf("%d",&g);
	getchar();
	for(f=1;g!=-111;f++)
	{
	    listinsert(&A,f,g);	
		scanf("%d",&g);
		getchar();
	}
	printf("A��"); 
	listtraverse(A);
    printf("\n\n");
    
    printf("�۰����\n");
    Elem_type x;
    int y;
    printf("search for:");
    scanf("%d",&x);
    getchar(); 
    y=bisearch(&A,x);
    if(y==-1)
    printf("no such number");
    else
    printf("the number is on %d",y+1);   
	printf("\n\n");

    printf("�ݹ��۰����\n");
    Elem_type a;
    int b;
    printf("search for:");
    scanf("%d",&a);
    getchar(); 
    b=rebisearch(&A,a,0,A.length-1);
    if(b==-1)
    printf("no such number");
    else
    printf("the number is on %d",b+1);

	return 0;
}

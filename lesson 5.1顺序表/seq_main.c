#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"seq_all.h"

int main()
{
	//顺序表集合合并 
	seq A,B;
	initlist(&A);
	printf("初始化列表A\n");
	initlist(&B);
	printf("初始化列表B\n");
	int f;
	Elem_type g;
	printf("\n输入A(-111 ends)：");
	scanf("%d",&g);
	for(f=1;g!=-111;f++)
	{
	    listinsert(&A,f,g);	
		scanf("%d",&g);
	}
	printf("A："); 
	listtraverse(A);
    printf("\n");
    
	printf("\n输入B(-111 ends)：");
	scanf("%d",&g);
	for(f=1;g!=-111;f++)
	{
	    listinsert(&B,f,g);
		scanf("%d",&g);
	}
	printf("B："); 
	listtraverse(B);
    printf("\n");
    
	seq C;
	initlist(&C);
	printf("\n初始化列表C\n");
	mergelist(A,B,&C);
	printf("C："); 
	listtraverse(C);
	
	

	polyseq X,Y;
	initpolyseq(&X);
	printf("\n初始化多项式A\n");
	initpolyseq(&Y);
	printf("初始化多项式B\n");
	Elem a;
	int b=1;
	printf("\n输入多项式A(指数为-1 ends)：");
	while(1)
	{
		scanf("%f",&a.xi);
		scanf("%d",&a.zhi);
		if(a.zhi==-1) break;
		else
		{
			seqinsert(&X,b,a);	
		    b++;
		}
	}
	printf("X："); 
	polytraverse(X);
	
	printf("\n\n输入多项式B(指数为-1 ends)：");
	b=1;
	while(1)
	{
		scanf("%f",&a.xi);
		scanf("%d",&a.zhi);
		if(a.zhi==-1) break;
		else
		{
			seqinsert(&Y,b,a);	
		    b++;
		}
	}
	printf("Y："); 
	polytraverse(Y);
	
	//顺序表实现多项式相加	
	
	polyseq Z;
	initpolyseq(&Z);
	printf("\n\n多项式相加\n");
	addseq(X,Y,&Z);
	printf("Z："); 
	polytraverse(Z);
	
	
	//顺序表实现多项式求和
	polyseq W;
    b=1;
	initpolyseq(&W);
	printf("\n输入多项式W(指数为-1 ends)：");
	while(1)
	{
		scanf("%f",&a.xi);
		scanf("%d",&a.zhi);
		if(a.zhi==-1) break;
		else
		{
			seqinsert(&W,b,a);	
		    b++;
		}
	}
	printf("W："); 
	polytraverse(W);
	
	int h;
	printf("\n\nx的值为：");
	scanf("%d",&h);
	printf("多项式的值为：%.3f",sumseq(W,h));
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"seq_all.h"

int main()
{
	//˳����Ϻϲ� 
	seq A,B;
	initlist(&A);
	printf("��ʼ���б�A\n");
	initlist(&B);
	printf("��ʼ���б�B\n");
	int f;
	Elem_type g;
	printf("\n����A(-111 ends)��");
	scanf("%d",&g);
	for(f=1;g!=-111;f++)
	{
	    listinsert(&A,f,g);	
		scanf("%d",&g);
	}
	printf("A��"); 
	listtraverse(A);
    printf("\n");
    
	printf("\n����B(-111 ends)��");
	scanf("%d",&g);
	for(f=1;g!=-111;f++)
	{
	    listinsert(&B,f,g);
		scanf("%d",&g);
	}
	printf("B��"); 
	listtraverse(B);
    printf("\n");
    
	seq C;
	initlist(&C);
	printf("\n��ʼ���б�C\n");
	mergelist(A,B,&C);
	printf("C��"); 
	listtraverse(C);
	
	

	polyseq X,Y;
	initpolyseq(&X);
	printf("\n��ʼ������ʽA\n");
	initpolyseq(&Y);
	printf("��ʼ������ʽB\n");
	Elem a;
	int b=1;
	printf("\n�������ʽA(ָ��Ϊ-1 ends)��");
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
	printf("X��"); 
	polytraverse(X);
	
	printf("\n\n�������ʽB(ָ��Ϊ-1 ends)��");
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
	printf("Y��"); 
	polytraverse(Y);
	
	//˳���ʵ�ֶ���ʽ���	
	
	polyseq Z;
	initpolyseq(&Z);
	printf("\n\n����ʽ���\n");
	addseq(X,Y,&Z);
	printf("Z��"); 
	polytraverse(Z);
	
	
	//˳���ʵ�ֶ���ʽ���
	polyseq W;
    b=1;
	initpolyseq(&W);
	printf("\n�������ʽW(ָ��Ϊ-1 ends)��");
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
	printf("W��"); 
	polytraverse(W);
	
	int h;
	printf("\n\nx��ֵΪ��");
	scanf("%d",&h);
	printf("����ʽ��ֵΪ��%.3f",sumseq(W,h));
	
	return 0;
}

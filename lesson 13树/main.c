#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

int main()
{
	Bitree T;
	printf("ǰ�򴴽���������");
	createbitree(&T);
	getchar();
	
	printf("\nǰ�������");
	pretraverse(T);
	printf("\n���������");
    intraverse(T);
    printf("\n���������");
    posttraverse(T);
    printf("\n��α�����");
    leveltraverse(T);
	
	printf("\n\n���ĸ߶�Ϊ��%d",heighttree(T));
	printf("\n�����ܽڵ���Ϊ��%d",allnodes(T));
	printf("\n����Ҷ�ڵ���Ϊ��%d",leaves(T));
	
	int k,n;
	Elem_type f;
	printf("\n\n��ڼ����ڵ��ֵ��");
	scanf("%d",&k);
	getchar();
	traverstarget(T,k,&f,&n);
	printf("��%d���ڵ��ֵΪ��%c",k,f);
	
	Elem_type d;
	printf("\n\nɾ���ڵ��ֵ��");
	scanf("%c",&d);
	getchar();
	deletetarget(&T,d);
	printf("ǰ�������");
	pretraverse(T);
	
	printf("\n\n�Ƚ��Ƿ�����");
	Bitree T1,T2;
	printf("\nǰ�򴴽���һ�ö�������");
	createbitree(&T1);
	getchar();
	printf("ǰ�򴴽��ڶ��ö�������");
	createbitree(&T2);
	getchar();
	if(similartrees(T1,T2))
	printf("����");
	else
	printf("������");
	
	printf("\n\n���ٸö�����");
	destroytree(&T);
	printf("\nǰ�������");
	pretraverse(T);
	
	Bitree T3;
	printf("\n\nǰ�򴴽���������");
	createbitree(&T3);
	getchar();
	printf("�ǵݹ�ǰ�������");
	pretraverseno(T3);
	printf("\n�ǵݹ����������");
	intraverseno(T3);

	return 0;
}

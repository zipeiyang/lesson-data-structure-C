#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

int main()
{
	initlist(L);
	int i,a;
	Elem_type b;
	printf("�������ֵĸ�����");
	scanf("%d",&a);
	getchar();
	printf("�������֣�");
	for(i=1;i<a+1;i++)
	{
		scanf("%d",&b);
		getchar();
		listinsert(L,i,b);
	}
	listtraverse(L);
	
	printf("\n\n(ɾ��5)\n");
	Elem_type e;
	listdelete(L,4,&e);
	printf("ɾ���������ǣ�%d\n",e);
	listtraverse(L);

	printf("\n\n(����9)\n");
	Elem_type f;
	int g;
	printf("����������ǣ�");
	scanf("%d",&f);
	getchar();
	printf("�����λ���ǣ�");
	scanf("%d",&g);
	getchar();
	listinsert(L,g,f);
	listtraverse(L);
	
	printf("\n\n(����5)\n");
	Elem_type x;
	int y,length=listlength(L);
	printf("���ҵ������ǣ�");
	scanf("%d",&x);
	getchar();
	y=listsearch(L,x);
	if(y!=length)
	printf("%d�ڵ�%d��λ����",x,y);
	else
	printf("����ʧ��"); 
	
	printf("\n\n(����7)\n");
	printf("���ҵ������ǣ�");
	scanf("%d",&x);
	getchar();
	y=listsearch(L,x);
	if(y!=length)
	printf("%d�ڵ�%d��λ����",x,y);
	else
	printf("����ʧ��"); 
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"node_all.h"

int main() 
{
	linklist L;
    initnode(&L);
	createnode(L);
    traversnode(L);
    int i;
    Elem_type e;
    printf("\nɾ����1��3��5λ���\n"); 
    for(i=1;i<4;i++)
    {
	    deletenode(L,i,&e);
	}
	traversnode(L);
	printf("\n��7λ������7\n");
    insertnode(L,7,7);
	traversnode(L);
	int len;
	len=length(L);
	printf("��������Ϊ��%d\n",len);
	printf("\n���ҽ��ֵ��");
	scanf("%d",&e);
	locatenode(L,e);
  
	Elem_type cur,pre;
	printf("\nѰ��ֱ��ǰ����");
	scanf("%d",&cur);
	priornode(L,cur,&pre);	

	Elem_type next;
	printf("\nѰ��ֱ�Ӻ�̣�");
	scanf("%d",&cur);
	nextnode(L,cur,&next);

	clearnode(L);
	traversnode(L);
	len=length(L);
	printf("��������Ϊ��%d\n",len);
	destroynode(L);
	

//����ʵ�������ϲ�
    linklist La;
    initnode(&La);
    printf("\ncreate La");
	createnode(La);
    traversnode(La);
    linklist Lb;
    initnode(&Lb);
    printf("\ncreate Lb");
	createnode(Lb);
    traversnode(Lb);
    linklist Lc=NULL;
    mergenode(La,Lb,&Lc);
    traversnode(Lc);
	
    
   
//����ʵ�ֶ���ʽ���
    polylist A,B,C=NULL;
    initpoly(&A);
    initpoly(&B);
    createpoly(A);
    traverspolynode(A);
    createpoly(B);
    traverspolynode(B);
    printf("\n����ʽA��B�ϲ���"); 
	addpolynode(A,B,&C);
	traverspolynode(C);
	
//����ʵ�ֶ���ʽ���
    polylist D;
    int x;
    float sum;
    initpoly(&D);
    printf("����ʽ���ݴ��루�ݴ�С�������룩\n");
    createpoly(D);
    traverspolynode(D);
    printf("������x��ֵ��");
    scanf("%d",&x);
    sum=sumpolynode(D,x);
    printf("�ö���ʽ��ֵΪ��%.3f",sum);
	return 0;
}

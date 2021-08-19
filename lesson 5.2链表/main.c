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
    printf("\n删除第1、3、5位结点\n"); 
    for(i=1;i<4;i++)
    {
	    deletenode(L,i,&e);
	}
	traversnode(L);
	printf("\n第7位插入结点7\n");
    insertnode(L,7,7);
	traversnode(L);
	int len;
	len=length(L);
	printf("单链表长度为：%d\n",len);
	printf("\n查找结点值：");
	scanf("%d",&e);
	locatenode(L,e);
  
	Elem_type cur,pre;
	printf("\n寻找直接前驱：");
	scanf("%d",&cur);
	priornode(L,cur,&pre);	

	Elem_type next;
	printf("\n寻找直接后继：");
	scanf("%d",&cur);
	nextnode(L,cur,&next);

	clearnode(L);
	traversnode(L);
	len=length(L);
	printf("单链表长度为：%d\n",len);
	destroynode(L);
	

//链表实现有序表合并
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
	
    
   
//链表实现多项式相加
    polylist A,B,C=NULL;
    initpoly(&A);
    initpoly(&B);
    createpoly(A);
    traverspolynode(A);
    createpoly(B);
    traverspolynode(B);
    printf("\n多项式A和B合并："); 
	addpolynode(A,B,&C);
	traverspolynode(C);
	
//链表实现多项式求和
    polylist D;
    int x;
    float sum;
    initpoly(&D);
    printf("多项式降幂存入（幂从小到大输入）\n");
    createpoly(D);
    traverspolynode(D);
    printf("请输入x的值：");
    scanf("%d",&x);
    sum=sumpolynode(D,x);
    printf("该多项式的值为：%.3f",sum);
	return 0;
}

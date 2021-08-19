#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

int main()
{
	Bitree T;
	printf("前序创建二叉树：");
	createbitree(&T);
	getchar();
	
	printf("\n前序遍历：");
	pretraverse(T);
	printf("\n中序遍历：");
    intraverse(T);
    printf("\n后序遍历：");
    posttraverse(T);
    printf("\n层次遍历：");
    leveltraverse(T);
	
	printf("\n\n树的高度为：%d",heighttree(T));
	printf("\n树的总节点数为：%d",allnodes(T));
	printf("\n树的叶节点数为：%d",leaves(T));
	
	int k,n;
	Elem_type f;
	printf("\n\n求第几个节点的值：");
	scanf("%d",&k);
	getchar();
	traverstarget(T,k,&f,&n);
	printf("第%d个节点的值为：%c",k,f);
	
	Elem_type d;
	printf("\n\n删除节点的值：");
	scanf("%c",&d);
	getchar();
	deletetarget(&T,d);
	printf("前序遍历：");
	pretraverse(T);
	
	printf("\n\n比较是否相似");
	Bitree T1,T2;
	printf("\n前序创建第一棵二叉树：");
	createbitree(&T1);
	getchar();
	printf("前序创建第二棵二叉树：");
	createbitree(&T2);
	getchar();
	if(similartrees(T1,T2))
	printf("相似");
	else
	printf("不相似");
	
	printf("\n\n销毁该二叉树");
	destroytree(&T);
	printf("\n前序遍历：");
	pretraverse(T);
	
	Bitree T3;
	printf("\n\n前序创建二叉树：");
	createbitree(&T3);
	getchar();
	printf("非递归前序遍历：");
	pretraverseno(T3);
	printf("\n非递归中序遍历：");
	intraverseno(T3);

	return 0;
}

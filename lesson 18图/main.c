#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h" 


int main()
{
	//邻接矩阵 
	Graph G;
	creategraph(&G);
	printf("\n打印图：\n");
	printgraph(G);
	printf("\n深度优先搜索：\n");
	traverse(G);
	printf("\n\n广度优先搜索：\n");
	traverse_sec(G);
	
	//邻接表
	printf("\n---------------------------------\n");
	Adjgraph A;
	createlist(&A);
	printf("\n打印图：\n");
	printlist(A); 
	return 0;
}

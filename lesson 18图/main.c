#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h" 


int main()
{
	//�ڽӾ��� 
	Graph G;
	creategraph(&G);
	printf("\n��ӡͼ��\n");
	printgraph(G);
	printf("\n�������������\n");
	traverse(G);
	printf("\n\n�������������\n");
	traverse_sec(G);
	
	//�ڽӱ�
	printf("\n---------------------------------\n");
	Adjgraph A;
	createlist(&A);
	printf("\n��ӡͼ��\n");
	printlist(A); 
	return 0;
}

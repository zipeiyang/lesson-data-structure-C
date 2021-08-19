#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h" 


Status initqueue(linkqueue *Q)
{
	Q->rear=NULL;
	Q->front=Q->rear;
	return OK;
}

Status isemptyqueue(linkqueue Q)
{
	if(Q.front==NULL)
	return TRUE;
	else
	return FALSE;
}

Status enqueue(linkqueue *Q,Elem_type e)
{
	linode p;
	p=(linode)malloc(sizeof(linknode));
	if(!p) exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	if(Q->front==NULL)
	{
		Q->front=p;
		Q->rear=p;
	}
	else
	{
		Q->rear->next=p;
    	Q->rear=p;
	}
	return OK;
}

Status dequeue(linkqueue *Q,Elem_type *e)
{
	linode p;
	p=Q->front;
	Q->front=Q->front->next;
	if(Q->front==NULL)
	Q->rear=NULL;
	*e=p->data;
	free(p);
	return OK;
}
Status creategraph(Graph *G)
{
	int i,j,n,e,u,v,cost;
	printf("请输入顶点数和边数(空格隔开)：");
	scanf("%d %d",&n,&e);
	setbuf(stdin,NULL);
	G->n=n;
	G->e=e;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			G->edge[i][j]=0;
		}
	}//初始化结束
	
	printf("请输入顶点表(空格隔开)：");
	for(i=0;i<n;i++)
	{
		scanf("%c",&G->vertex[i]);
		setbuf(stdin,NULL);
	}
	
	printf("请输入每条边依附的顶点（横、竖坐标）及其权值(空格隔开)：\n");
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&u,&v,&cost);
		G->edge[u][v]=cost;
		G->edge[v][u]=cost;
		setbuf(stdin,NULL);
	}
	return OK;
}

Status isempy(Graph G)
{
	if(G.n==0)
	return TRUE;
	else
	return FALSE;
}

void printgraph(Graph G)
{
	int i,j;
	for(i=0;i<G.n;i++)
	{
		printf("%c->",G.vertex[i]);
		for(j=0;j<G.n;j++)
		{
			printf("%d ",G.edge[i][j]);
		}
		printf("\n");
	}
}

int getfirst(Graph G,int m)
{
	int i;
	for(i=0;i<G.n;i++)
		if(G.edge[m][i]>0)//&&G.edge[m][i]<MAXVALUE
		return i;
	return -1;	
}

int getnext(Graph G,int m,int w)
{
	int i;
	for(i=w+1;i<G.n;i++)
	{
		if(G.edge[m][i]>0)//&&G.edge[m][i]<MAXVALUE
		return i;
	}
	return -1;	
}

void dfs(Graph G,int v)
{
	int w;
	if(visited[v]==1)
	return;//出口 
	printf("%c ",G.vertex[v]);
	visited[v]=1;
	w=getfirst(G,v);
	while(w!=-1)
	{
		if(!visited[w])
		dfs(G,w);
		w=getnext(G,v,w);
	}
}

void traverse(Graph G)
{
	int i;
	for(i=0;i<G.n;i++)
	visited[i]=0;
	for(i=0;i<G.n;i++)
	{
		if(!visited[i])
		dfs(G,i);
	}
}

void bfs(Graph G,int v)
{
	int w;
	printf("%c ",G.vertex[v]);
	visited_sec[v]=1;
	linkqueue Q;
	initqueue(&Q);
	enqueue(&Q,v);
	while(!isemptyqueue(Q))
	{
		dequeue(&Q,&v);
		w=getfirst(G,v);
		while(w!=-1)
		{
			if(!visited_sec[w])
			{
				printf("%c ",G.vertex[w]);
				visited_sec[w]=1;
				enqueue(&Q,w);
			}
			w=getnext(G,v,w);
		}
	}
}

void traverse_sec(Graph G)
{
	int i;
	for(i=0;i<G.n;i++)
	visited_sec[i]=0;
	for(i=0;i<G.n;i++)
	{
		if(!visited_sec[i]) bfs(G,i);
	}
}

Status createlist(Adjgraph *A)
{
	int i,n,e,head,weight,tail;
	printf("请输入顶点数和边数(空格隔开)：");
	scanf("%d %d",&n,&e);
	setbuf(stdin,NULL);
	A->n=n;
	A->e=e;
	printf("请输入顶点表(空格隔开)：");
	for(i=0;i<n;i++)
	{
		scanf("%c",&A->vertexlist[i].data);
		setbuf(stdin,NULL);
		A->vertexlist[i].first=NULL;
	}
	
	printf("请输入每条边的起点、终点和权值(空格隔开)：\n"); 
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&head,&tail,&weight);
		setbuf(stdin,NULL);
		Enode *p=malloc(sizeof(Enode));
		p->dest=tail;
		p->cost=weight;
		p->next=A->vertexlist[head].first;
		A->vertexlist[head].first=p;
		Enode *q=malloc(sizeof(Enode));
		q->dest=head;
		q->cost=weight;
		q->next=A->vertexlist[tail].first;
		A->vertexlist[tail].first=q;
	}
	return OK;
}

Status isempylist(Adjgraph A)
{
	if(A.n==0)
	return TRUE;
	else
	return FALSE;
}

void printlist(Adjgraph A)
{
	int i,j;
	for(i=0;i<A.n;i++)
	{
		printf("%d: %c->",i,A.vertexlist[i].data);
		Enode *p=A.vertexlist[i].first;
		while(p)
		{
			printf("%c:%d,  ",A.vertexlist[p->dest].data,p->cost);
			p=p->next;
		}
		printf("\n");
	}
}

#include<stdio.h>
#include<stdlib.h>
#include"linkstack.h"

Status initlink(listack *L)
{
	*L=NULL;
	return OK;
}

Status isemptylink(listack L)
{
	if(L==NULL)
		return TRUE; 
	else
		return FALSE; 
}

Status traverse(listack L)
{
	printf("Á´Õ»Îª£º");
	while(L)
	{
		printf("%d ",L->data);
		L=L->next;
	}
	return OK;	
}

Status pushlink(listack *L,Elemtype e)
{
	listack p;
	p=(linkstack *)malloc(sizeof(linkstack));
	if(!p) exit(OVERFLOW);
	p->data=e;
	p->next=*L;
	*L=p;
	return OK;
}

Status poplink(listack *L,Elemtype *e)
{
	if(L==NULL) return ERROR;
	linkstack *p=*L;
	*L=(*L)->next;
	*e=p->data;
	free(p);
	return OK;
}

Status gettop(listack L,Elemtype *e)
{
	if(L==NULL) return ERROR;
	*e=L->data;
	return OK;	
}

void nextgrid(Elemtype *pos)
{
	if(maze[pos->x][pos->y].direct==1)
	pos->y+=1;
	if(maze[pos->x][pos->y].direct==2)
	pos->x+=1;
	if(maze[pos->x][pos->y].direct==3)
	pos->y-=1;
	if(maze[pos->x][pos->y].direct==4)
	pos->x-=1;
}

int gostep(Elemtype *pos)
{
    Elemtype newpos;
    newpos=*pos;
    nextgrid(&newpos);
	
	if(maze[newpos.x][newpos.y].data=='o')
	{
		*pos=newpos;
		return 1;
	}
	return 0;
}

void print()
{
	int a,b;
	for(a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			printf("%c",maze[a][b].data);			
		}
		printf("\n");
	}
	sleep(1);
}

Status search(Elemtype start,Elemtype end)
{
	listack L;
	Elemtype curpos;
	initlink(&L);
	pushlink(&L,start);
	if(maze[start.x][start.y].data!='o'||maze[start.x][start.y].data=='G') return FALSE;
	maze[start.x][start.y].data='-';
	system("cls");
	print();
	do
	{
		gettop(L,&curpos);
		while(maze[curpos.x][curpos.y].direct<=4)
		{
			if(gostep(&curpos))
			{
				if((curpos.x==end.x)&&(curpos.y==end.y))
				{
					pushlink(&L,curpos);
					break;
				}
				pushlink(&L,curpos);
				maze[curpos.x][curpos.y].data='-';
				system("cls");
				print();
			}
			else
			maze[curpos.x][curpos.y].direct++;
		}
		if(maze[curpos.x][curpos.y].direct>4)
		{
			poplink(&L,&curpos);
			maze[curpos.x][curpos.y].data='$';
		}
	}
	while(!isemptylink(L)&&(curpos.x!=end.x)&&(curpos.y!=end.y));
	if(isemptylink(L)) return 0;
	printf("maze succeeds.");
	return 1;
}

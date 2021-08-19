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
	{
		printf("Á´Õ»Îª¿Õ");
		return TRUE; 
	}
	else
	{
		printf("Á´Õ»²»Îª¿Õ");
		return FALSE; 
	}
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

Status pushlink(listack *L,Elem_type e)
{
	listack p;
	p=(linkstack *)malloc(sizeof(linkstack));
	if(!p) exit(OVERFLOW);
	p->data=e;
	p->next=*L;
	*L=p;
	return OK;
}

Status poplink(listack *L,Elem_type *e)
{
	if(L==NULL) return ERROR;
	linkstack *p=*L;
	*L=(*L)->next;
	*e=p->data;
	free(p);
	return OK;
}

Status gettop(listack L,Elem_type *e)
{
	if(L==NULL) return ERROR;
	*e=L->data;
	return OK;	
}

#include<stdio.h>
#include<stdlib.h>
#include"stackseq.h"

Status initstack(sqstack *S)
{
	S->base=(Elem_type *)malloc(LIST_INIT_SIZE*sizeof(Elem_type));
	if(!S->base) exit(OVERFLOW);
	S->top=S->base;
	S->stacksize=LIST_INIT_SIZE;
	return OK;
}

Status isemptystack(sqstack S)
{
	if(S.top==S.base)
	{
		printf("Ë³ÐòÕ»Îª¿Õ\n");
    	return TRUE;
	}
	else
	{
		printf("Ë³ÐòÕ»²»Îª¿Õ\n");	
	    return FALSE;
	}
}

Status pushstack(sqstack *S,Elem_type e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(Elem_type *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(Elem_type));
		if(!S->base) exit(OVERFLOW);
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*(S->top)=e;
	S->top++;
	return OK;
}

Status popstack(sqstack *S,Elem_type *e)
{
	if(S->top==S->base) return ERROR;
	S->top--;
	*e=*S->top;
	return OK;
}

Status gettop(sqstack S,Elem_type *e)
{
	if(S.top==S.base) return ERROR;
	*e=*(S.top-1);
	return OK;
}

Status traverse(sqstack S)
{
	Elem_type *p=S.base;
	while(p!=S.top)
	{
		printf("%d ",*p);
		p++;
	}
    return OK;
}

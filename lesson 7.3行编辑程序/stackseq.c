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
		return TRUE;
	else
	    return FALSE;
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
		printf("%c",*p);
		p++;
	}
    return OK;
}

Status clearstack(sqstack *S)
{
	S->top=S->base;
	return OK;
}

Status destroystack(sqstack *S)
{
	free(S->top);
	free(S->base);
	return OK;
}

Status lineedit()
{
	sqstack S;
	Elem_type ch,a;
	initstack(&S);
	printf("please enter:");
	ch=getchar();
	while(ch!=EOF)
	{
		while(ch!=EOF&&ch!='\n')
		{
			switch(ch)
			{
				case'#':popstack(&S,&a);break;
				case'@':clearstack(&S);break;
				default:pushstack(&S,ch);break;
			}
			ch=getchar();
		}
	traverse(S);
	clearstack(&S);
//	if(ch!=EOF) 
    ch=getchar();
	}
	destroystack(&S);
	return OK;
}

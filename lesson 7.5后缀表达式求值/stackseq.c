#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

Status isnum(Elem_type a)
{
	if(a>=48&&a<=57)
	return TRUE;
	else
	return FALSE;
}

Elem_type compute(Elem_type a,Elem_type b,Elem_type c)
{
	char sum;
	switch(b)
	{
		case'+':sum=a+c-96;break;
		case'-':sum=c-a;break;
		case'*':sum=(c-48)*(a-48);break;
		case'/':sum=(c-48)/(a-48);break;
		case'%':sum=(c-48)%(a-48);break;
		case'^':sum=pow((c-48),(a-48));break;
	}
	return sum+48;
}

Status evaluatestack(char *s)
{
	int i;
	Elem_type a,b,c;
	sqstack N,O;
	initstack(&N);
	initstack(&O);
	for(i=0;s[i]!='\0';i++)
	{
    	if(isnum(s[i]))
    	pushstack(&N,s[i]);
		else
		{   
		    pushstack(&O,s[i]);
            popstack(&O,&b);
			popstack(&N,&a);
			popstack(&N,&c);
            pushstack(&N,compute(a,b,c));
	    }					
	}
	gettop(N,&a);
	printf("½á¹ûÊÇ£º%d",a-48);
	return OK;
}

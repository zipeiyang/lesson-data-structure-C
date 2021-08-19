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

Status isnum(Elem_type a)
{
	if(a>=48&&a<=57)
	return TRUE;
	else
	return FALSE;
}

Status compare(Elem_type a,Elem_type b)
{
	switch(a)
	{
		case'+':a=3;break;
		case'-':a=3;break;
		case'*':a=5;break;
		case'/':a=5;break;
		case'%':a=5;break;
		case'^':a=7;break;
		case'(':a=1;break;
		
	}
	switch(b)
	{
		case'+':b=2;break;
		case'-':b=2;break;
		case'*':b=4;break;
		case'/':b=4;break;
		case'%':b=4;break;
		case'^':b=6;break;
		case'(':b=8;break;
	}
	if(a>b)
	return TRUE;
	else
	return ERROR;
}

Status transfer(char *s)
{
	int i;
	sqstack S;
	Elem_type a;
	initstack(&S);
	for(i=0;s[i]!='\0';i++)
	{
		if(isnum(s[i])) 
		printf("%c",s[i]);
		
		else if(s[i]=='(')
		pushstack(&S,s[i]); 
		
		else if(s[i]==')')
		{
			while(1) 
			{  
				popstack(&S,&a); 
				if(a!='(') 
				printf("%c",a); 
				else
				break;
			}
		}
		else
   		{
      		if(isemptystack(S)) 
			  	pushstack(&S,s[i]);
			else
			{
				gettop(S,&a);
	    		while(compare(a,s[i])&&!isemptystack(S))
				{   
		 			popstack(&S,&a); 
		 			printf("%c",a);
		 			gettop(S,&a);
		 		}     
		 		pushstack(&S,s[i]);    
		 	}
		}
	}
	while(!isemptystack(S))
	{
	  	popstack(&S,&a); 
	  	printf("%c",a);
	}
	return OK;
}

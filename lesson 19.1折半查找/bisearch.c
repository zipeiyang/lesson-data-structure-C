#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"bisearch.h"


Status initlist(seq *L)
{
	L->elem=(Elem *)malloc(LIST_INIT_SIZE*sizeof(Elem));
	if(!L->elem) exit(OVERFLO);
	L->length=0;
	L->size=LIST_INIT_SIZE;
	return OK;
}

Status listinsert(seq *L,int i,Elem_type e)
{
	Elem *newbase;
	int j;
	if(i<1||i>(L->length+1)) return ERROR;
	if(L->length>=L->size)
	{
		newbase=(Elem *)realloc(L->elem,(L->size+LISTINCREMENT)*sizeof(Elem));
	    if(!newbase) exit(OVERFLO);
	    L->elem=newbase;
	    L->size+=LISTINCREMENT;	
    }
	for(j=L->length-1;j>=i-1;j--)
    L->elem[j+1].key=L->elem[j].key;
	L->elem[i-1].key=e;
	L->length++;
	return OK;
}

Status listtraverse(seq L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d ",L.elem[i].key);
	}
	return OK;	
}

int bisearch(seq *L,Elem_type x)
{
	int high=L->length-1,low=0,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(L->elem[mid].key<x)
		low=mid+1;
		else if(L->elem[mid].key>x)
		high=mid-1;
		else
		return mid;		
	}
	return -1;	
}

int rebisearch(seq *L,Elem_type x,int low,int high)
{
	int mid=-1;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(L->elem[mid].key<x)
		mid=rebisearch(L,x,mid+1,high);
		else if(L->elem[mid].key>x)
		mid=rebisearch(L,x,low,mid-1);
	}
	return mid;
}

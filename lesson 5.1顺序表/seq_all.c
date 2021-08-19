#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"seq_all.h"

Status initlist(seq *L)
{
	L->elem=(Elem_type *)malloc(LIST_INIT_SIZE*sizeof(Elem_type));
	if(!L->elem) exit(OVERFLO);
	L->length=0;
	L->size=LIST_INIT_SIZE;
	return OK;
}


Status destroylist(seq *L)
{
	free(L->elem);
	L->elem=NULL;
	return OK;
}


Status clearlist(seq *L)
{
	L->length=0;
	return OK;
}


Status emptylist(seq L)
{
	if(L.length==0)
	return TRUE;
	else
	return FALSE;
}


int lengthlist(seq L)
{
	return L.length;
}


Status getelem(seq L,int i,Elem_type *e)
{
	if(i<1||i>L.length) 
	{
		printf("超出列表范围\n");
		return ERROR;
	}
	*e=L.elem[i-1];
	printf("第%d个数字为：%d\n",i,*e);
	return OK; 
}


Status locateelem(seq L,Elem_type e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(L.elem[i]==e+2)
		{
		    printf("比该数大2的数字%d排在第%d位\n",e+2,i+1);
		    return OK;
		}
    }
    printf("不存在\n");
    return ERROR;
}


Status priorelem(seq L,Elem_type cur,Elem_type *pre)
{
	int i;
    if(cur==L.elem[0])
    return ERROR;
	for(i=1;i<L.length;i++)
	{
		if(cur==L.elem[i])
		{
		    *pre=L.elem[i-1];
		    return OK;
		}
    }
    printf("无定义\n");
    return ERROR;
}



Status nextelem(seq L,Elem_type cur,Elem_type *next)
{
	int i;
    if(cur==L.elem[L.length-1])
    return ERROR;
	for(i=1;i<L.length;i++)
	{
		if(cur==L.elem[i])
		{
		    *next=L.elem[i+1];
		    return OK;
		}
    }
    printf("无定义\n");
    return ERROR;
}


Status listinsert(seq *L,int i,Elem_type e)
{
//	Elem_type *p,*q;
	int *newbase;
	int j;
	if(i<1||i>(L->length+1)) return ERROR;
	if(L->length>=L->size)
	{
		newbase=(Elem_type *)realloc(L->elem,(L->size+LISTINCREMENT)*sizeof(Elem_type));
	    if(!newbase) exit(OVERFLO);
	    L->elem=newbase;
	    L->size+=LISTINCREMENT;	
    }
/*  q=&(L->elem[i-1]);//i的位置
	if(L->length==0)
	{
		*q=e;
		++L->length; 
		return OK;
	}
	else
	{
		for(p=&(L->elem[L->length-1]);p>=q;--p)
        {*(p+1)=*p;}//i之后元素后移 
        *q=e;
	    ++L->length;
	}
	return OK;
	*/

	for(j=L->length-1;j>=i-1;j--)
    L->elem[j+1]=L->elem[j];
	L->elem[i-1]=e;
	L->length++;
	return OK;
}



Status listdelete(seq *L,int i,Elem_type *e)
{
	Elem_type *p,*q;
	if(i<1||i>L->length) return ERROR;
	p=&(L->elem[i-1]);
	e=p;
	q=L->elem+L->length-1;//表尾位置
	for(++p;p<=q;++p)
	*(p-1)=*p;
	--L->length;
	return OK;
}


Status listtraverse(seq L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d ",L.elem[i]);
	}
	return OK;	
}

Status mergelist(seq A,seq B,seq *C)
{
	int i=1,j=1,k=1;
	Elem_type a,b;
	while((i<=A.length)&&(j<=B.length))
	{
		a=A.elem[i-1];
		b=B.elem[j-1];
		if(a<b)
		{
			listinsert(C,k,a);
			k++;
			i++;
		}
		else if(a==b)
		{
			listinsert(C,k,a);
			k++;
			i++;
			j++;
		}
		else
		{
			listinsert(C,k,b);
			k++;
			j++;
		}
	}
	while(i<=A.length)
	{
		a=A.elem[i-1];
		listinsert(C,k,a);
		i++;
		k++;
	}
	while(j<=B.length)
	{
		b=B.elem[j-1];
		listinsert(C,k,b);
		j++;
		k++;
	}
	return OK;
}

Status initpolyseq(polyseq *L)
{
	L->elem=(Elem *)malloc(LIST_INIT_SIZE*sizeof(Elem));
	if(!L->elem) exit(OVERFLO);
	L->count=0;
	L->size=LIST_INIT_SIZE;
	return OK;
}


Status seqinsert(polyseq *L,int i,Elem e)
{
	Elem *newbase;
	int j;
	if(i<1||i>(L->count+1)) return ERROR;
	if(L->count>=L->size)
	{
		newbase=(Elem *)realloc(L->elem,(L->size+LISTINCREMENT)*sizeof(Elem));
	    if(!newbase) exit(OVERFLO);
	    L->elem=newbase;
	    L->size+=LISTINCREMENT;	
    }
	for(j=L->count-1;j>=i-1;j--)
    L->elem[j+1]=L->elem[j];
	L->elem[i-1]=e;
	L->count++;
	return OK;
}

Status polytraverse(polyseq L)
{
	int i;
	for(i=0;i<L.count;i++)
	{
		if(L.elem[i].zhi!=0)
		printf("%.2fx**%d",L.elem[i].xi,L.elem[i].zhi);
		else
		printf("%.2f",L.elem[i].xi);
		if(i!=L.count-1)
		printf("+");
	}
	return OK;	
}


Status addseq(polyseq A,polyseq B,polyseq *C)
{
	int i=1,j=1,k=1;
	float temp;
	while(i<=A.count&&j<=B.count)
	{   
	    if(C->count>=C->size)
        {
    	   	Elem *newbase;
	       	newbase=(Elem *)realloc(C->elem,(C->size+LISTINCREMENT)*sizeof(Elem));
	        if(!newbase) exit(OVERFLO);
	        C->elem=newbase;
	        C->size+=LISTINCREMENT;	
        }
		if(A.elem[i-1].zhi==B.elem[j-1].zhi)
		{
			temp=A.elem[i-1].xi+B.elem[j-1].xi;
			if(temp)
			{
				C->elem[k-1].xi=temp;
				C->elem[k-1].zhi=A.elem[i-1].zhi;
				C->count++;k++;
			}
			i++;
			j++;
						
		}
		
		else if(A.elem[i-1].zhi<B.elem[j-1].zhi)
		{
			C->elem[k-1].xi=A.elem[i-1].xi;
			C->elem[k-1].zhi=A.elem[i-1].zhi;
			C->count++;
			i++;
			k++;
		}
		else
		{
			C->elem[k-1].xi=B.elem[j-1].xi;
			C->elem[k-1].zhi=B.elem[j-1].zhi;
			C->count++;
			j++;
			k++;
		}
		}
		for(;i<=A.count;i++)
		{
			C->elem[k-1].xi=A.elem[i-1].xi;
			C->elem[k-1].zhi=A.elem[i-1].zhi;
			C->count++;
			k++;
		}
		for(;j<=B.count;j++)
		{
			C->elem[k-1].xi=B.elem[j-1].xi;
			C->elem[k-1].zhi=B.elem[j-1].zhi;
			C->count++;
			k++;
		}
	return OK;
}

float sumseq(polyseq L,int h)
{
	float sum=0;
	int i;
	for(i=0;i<L.count;i++)
	{
		sum+=L.elem[i].xi*pow(h,L.elem[i].zhi);
	}
	return sum;
}

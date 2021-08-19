#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"node_all.h"

Status initnode(linklist *list)
{
	
	*list=(linklist)malloc(sizeof(linknode));
	if(*list==NULL) exit(OVERFLO);
	(*list)->next=NULL;
	return OK;
}

Status insertnode(linklist L,int i,Elem_type e)
{
	linklist p,s;
	int j=0;
	p=L;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}//Ѱ��i-1���
	if(!p||j>i-1) return ERROR;
	s=(linklist)malloc(sizeof(linknode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status deletenode(linklist L,int i,Elem_type *e)
{
	linklist p,q;
	int j=0;
	p=L;
	while(p->next&&j<i-1)
	{
		p=p->next;
		++j;
	}//Ѱ��i-1��㣬��ȷ��iλ�ô���һ����� 
	if(!p||j>i-1) return ERROR;
	q=p->next;
	p->next=q->next;
	*e=q->data;
	printf("\nɾ����������%d",*e);
	free(q);
	return OK;
}

Status createnode(linklist L)
{
	linklist p;
	printf("\nͷ�巨������������(-111 ends)��");
	Elem_type e;
	while(1)
	{
		p=(linklist)malloc(sizeof(linknode));
		scanf("%d",&e);
		if(e==-111) break;
		p->data=e;
		p->next=L->next;
		L->next=p;
	}
	return OK;
}

Status traversnode(linklist L)
{
	linklist p;
	printf("\n����Ϊ:");
	if(L->next==NULL)
	printf("�޽��");
	for(p=L->next;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
	return OK;
}

int length(linklist L)
{
	int len=0;
	linklist p;
    for(p=L->next;p!=NULL;p=p->next)
	{
		len++;
	}
	return len;
}

Status locatenode(linklist L,Elem_type e)
{
	linklist p;
	int i=0;
	for(p=L->next;p!=NULL;p=p->next)
	{
		if(e==p->data)
		{
			printf("�ý���ڵ������У�λ���ǵ�%d��\n",i+1);
			break;
		}
		i++;
	}
	if(i==length(L))
	printf("�ý�㲻�ڵ�������\n");
	return OK;
}

Status priornode(linklist L,Elem_type cur,Elem_type *pre)
{
	linklist p,q;
	if(cur==L->next->data)
	{
		printf("��ֱ��ǰ��\n");
		return ERROR;
	}
	else
	{
		for(p=L->next->next,q=L->next;p!=NULL;p=p->next)
    	{
	    	if(cur==p->data)
	    	{
		        *pre=q->data;
		        printf("%d��ֱ��ǰ����%d\n",cur,*pre);
		        return OK;
		    }
		    else q=q->next;
    	}
	}
	printf("��ֱ��ǰ��\n");
	return ERROR;
}

Status nextnode(linklist L,Elem_type cur,Elem_type *next)
{
	linklist p;
	int i=0;
	for(p=L->next;p!=NULL;p=p->next)
	{
		i++;
		if(cur==p->data&&i!=length(L))
		{
		    *next=p->next->data;
		    printf("%d��ֱ�Ӻ�̣�%d\n",cur,*next);
		    return OK;
		}
	}
    printf("��ֱ�Ӻ��\n"); 
	return ERROR;
}

Status clearnode(linklist L)
{
	linklist p;
	printf("\nclear all nodes");
	while(L->next)
	{
		p=L->next;
		L->next=p->next;
		free(p);
	}
	return OK;
}

Status destroynode(linklist L)
{
	printf("\ndestroy all nodes\n");
	free(L);
	L=NULL;	
	return OK;
}


Status mergenode(linklist La,linklist Lb,linklist *Lc)
{
	linklist pa=La->next,pb=Lb->next,pc=La;
	*Lc=pc;
	*Lc=La;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(Lb);
	return OK;
}



Status initpoly(polylist *p)
{
	*p=(polylist)malloc(sizeof(polynode));
	if(*p==NULL) exit(OVERFLO);
	(*p)->next=NULL;
	return OK;
}

Status createpoly(polylist P)
{
	polylist q;
	printf("ͷ�巨�����������ʽ(ϵ����0 �� ָ����-1 ends)��");
	while(1)
	{
		q=(polylist)malloc(sizeof(polynode));
		scanf("%f",&q->data.xi);
		scanf("%d",&q->data.zhi);
		if(q->data.xi==0) break;
		q->next=P->next;
		P->next=q;
        if(q->data.zhi==-1) break;
	}
	return OK;
}

Status traverspolynode(polylist P)
{
	polylist p;
	printf("����ʽΪ:");
	if(P->next==NULL)
	printf("�޶���ʽ");
	for(p=P->next;p!=NULL;p=p->next)
	{
		if(p->data.xi!=1&&p->data.zhi!=-1&&p->data.zhi!=0)
		printf("%.2fx**%d",p->data.xi,p->data.zhi);
		else if(p->data.zhi==-1||p->data.zhi==0)
		printf("%.2f",p->data.xi);
		else
		printf("x**%d",p->data.zhi);
		if(p->next!=NULL)
		printf("+");
	}
	printf("\n\n");
	return OK;
}

Status addpolynode(polylist A,polylist B,polylist *C)
{
	polylist pa,pb,pc,p;
	Elem a,b;
	*C=pc;
	*C=A;
	pa=A->next;
	pb=B->next;
	free(B);
	while(pa&&pb)
	{
		a=pa->data;
		b=pb->data;
		if(a.zhi==b.zhi)
		{
			a.xi=a.xi+b.xi;
			p=pb;
			pb=pb->next;
			free(p);
			if(a.xi)
			{
				pa->data=a;
				pc->next=pa;
				pc=pa;
				pa=pa->next;
			}
			else
			{
				p=pa;
				pa=pa->next;
				free(p);
			}
		}
		else if(a.zhi<b.zhi)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	return OK;
}

float sumpolynode(polylist P,int x)
{
	float sum;
	polylist q;
	Elem a,b;
	q=P->next;
	sum=q->data.xi;
	if(q->next==NULL)
	return sum*pow(x,q->data.zhi);
	while(q&&q->next)
	{
		a=q->data;
		b=q->next->data;
		sum=sum*pow(x,a.zhi-b.zhi)+b.xi;
		q=q->next;
	}	
	return sum;
}

#include<stdio.h>
#include<stdlib.h>
#include"linkstack.h"

char m[10][10]={
{'#','#','#','#','#','#','#','#','#','#'},
{'#','o','o','#','o','o','o','#','o','#'},
{'#','o','o','#','o','o','o','#','o','#'},
{'#','o','o','o','o','#','#','o','o','#'},
{'#','o','#','#','#','o','o','o','o','#'},
{'#','o','o','o','#','o','o','o','o','#'},
{'#','o','#','o','o','o','#','o','o','#'},
{'#','o','#','#','#','o','#','#','o','#'},
{'#','#','o','o','o','o','o','o','G','#'},
{'#','#','#','#','#','#','#','#','#','#'}
};

int main()
{
	int a,b;
	Elemtype start,end;
	
	for(a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			maze[a][b].data=m[a][b];			
		}
	}
	
	printf("������ʼλ��x��");
	scanf("%d",&start.x);
	printf("������ʼλ��y��");
	scanf("%d",&start.y);
	
	printf("�������λ��x��");
	scanf("%d",&end.x);
	printf("�������λ��y��");
	scanf("%d",&end.y);
    search(start,end);
	
	return 0;
}

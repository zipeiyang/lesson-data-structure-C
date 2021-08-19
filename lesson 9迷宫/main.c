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
	
	printf("输入起始位置x：");
	scanf("%d",&start.x);
	printf("输入起始位置y：");
	scanf("%d",&start.y);
	
	printf("输入结束位置x：");
	scanf("%d",&end.x);
	printf("输入结束位置y：");
	scanf("%d",&end.y);
    search(start,end);
	
	return 0;
}

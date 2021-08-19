#include<stdio.h>
#include<stdlib.h>

char maze[10][10]={
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

void search(int,int);
void print();

int main()
{
	print(maze);
	search(1,1);
	
	return 0;
}

void search(int x,int y)
{   
	if(maze[x][y]=='G')
	{
		printf("maze succeeds.");
		exit(0);
	}
	if(maze[x][y]=='o')
	{
		system("cls");
		maze[x][y]='-';
		print();
		search(x,y+1);
		search(x+1,y);
		search(x,y-1);
		search(x-1,y);
		maze[x][y]='$';
	}
	
}

void print()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%c",maze[i][j]);
		}
		printf("\n");
	}
	sleep(1);
}

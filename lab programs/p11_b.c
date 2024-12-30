#include<stdio.h>
int graph[7][7]={
				{0,1,1,1,0,0,0},
				{1,0,1,0,0,0,0},
				{1,1,0,1,1,0,0},
				{1,0,1,0,1,0,0},
				{0,0,1,1,0,1,1},
				{0,0,0,0,1,0,0},
				{0,0,0,0,1,0,0}};
int visited[7]={0,0,0,0,0,0,0};

void DFS(int v){
	int i;
	printf("%d ",v);
	visited[v]=1;
	for(i=0;i<7;i++){
		if(graph[v][i]==1 && visited[i]==0){
			DFS(i);
		}
	}
}

int main(){
	int start;
	printf("Enter starting vertex from 0 to 6 = ");
	scanf("%d",&start);
	DFS(start);
}
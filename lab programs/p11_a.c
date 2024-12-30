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
int queue[7];
int front=-1,rear=-1;

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


void BFS(int v){
	int u,i;
	printf(" %d ",v);
	visited[v]=1;
	front=0;
	rear=0;
	queue[rear]=v;
	while(front<=rear){
		u=queue[front++];
		for(i=0;i<7;i++){
			if(graph[u][i]==1 && visited[i]==0){
				printf(" %d ",i);
				visited[i]=1;
				queue[++rear]=i;
			}
		}
	}
}



int main(){
	int start;
	printf("\nBFS: Enter starting vertex from 0 to 6 = ");
	scanf("%d",&start);
	BFS(start);
}

#include <stdio.h>
#include <time.h>

int arr[20][20], q[20],n,visited[20],f=0,r=-1;


void bfs(int startVertex)
{
	for(int i = 0; i<n; i++){
		if(arr[startVertex][i] && !visited[i]){
			q[++r] = i;
		}
	}
	if(f <= r){
		visited[q[f]] = 1;
		bfs(q[++f]);
	}
}

int main()
{
	int startVertex;
	clock_t t;
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("Enter the elements of the adjacency matrix: ");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Enter the starting vertex: ");
	scanf("%d",&startVertex);
	for(int i = 0; i<n;i++){
		q[i] = 0;
		visited[i] = 0;
	}
	t = clock();
	bfs(startVertex);
	t = clock() - 1;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	for(int i = 0; i<n; i++){
        if(visited[i]){
			printf("\nThe node %d is reachable",i);
		}
		else{
            printf("\nThe node %d is not reachable",i);
		}

	}
	printf("\nTime taken for BFS is: %f",time_taken);
}

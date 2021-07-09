#include <stdio.h>
#include<time.h>

int arr[20][20];
int visited[20];
int n;

void dfs(int v)
{
	for(int i = 0; i<n; i++){
		if(arr[v][i] != 0 && visited[i] == 0){
			visited[i] = 1;
			printf("%d",i);
			dfs(i);
		}
	}

}


int main()
{
    clock_t t;
    double time_taken = 0.0;
	int v;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter the graph: ");
	for(int i = 0; i<n;i++){
		for(int j = 0; j<n; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	printf("Enter the starting vertex: ");
	scanf("%d",&v);
	printf("\nDFS traversal is: ");
	visited[v] = 1;
	printf("%d",v);
	t = clock();
	dfs(v);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time taken is: %f", time_taken);
}

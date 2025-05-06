
#include<stdio.h>
#include<stdlib.h>

#define MAX 6

void dfs(int v, int adj[MAX][MAX], int visited[], int stack[], int *top, int n) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, adj, visited, stack, top, n);
        }
    }


    stack[++(*top)] = v;
}

void topological_sort(int adj[MAX][MAX], int visited[], int n) {
    int stack[MAX], top = -1;


    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            dfs(i, adj, visited, stack, &top, n);
        }
    }

    printf("Topological Sorted Order: \n");
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX], visited[MAX] = {0};

    printf("Enter the adjacency matrix :\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topological_sort(adj, visited, n);

    return 0;
}




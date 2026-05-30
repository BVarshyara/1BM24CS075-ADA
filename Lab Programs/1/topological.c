#include <stdio.h>
#include <time.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;
void dfs(int v)
{
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
    stack[++top] = v;
}
void topologicalSort()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    printf("\nTopological Ordering:\n");
    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
int main()
{
    clock_t start, end;
    double cpu_time_used;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    start = clock();
    topologicalSort();
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution Time = %lf seconds\n", cpu_time_used);
    return 0;
}

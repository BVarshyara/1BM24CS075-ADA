#include <stdio.h>
#include <time.h>
#define MAX 100
int parent[MAX];
int find(int v)
{
    while(parent[v] != 0)
        v = parent[v];
    return v;
}
void unite(int u, int v)
{
    parent[v] = u;
}
int main()
{
    int n, e;
    int u[MAX], v[MAX], w[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("\nEnter edges (source destination weight):\n");
    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &u[i],
              &v[i],
              &w[i]);
    }
    clock_t start, end;
    double execution_time;
    start = clock();
    for(int i = 0; i < e - 1; i++)
    {
        for(int j = 0; j < e - i - 1; j++)
        {
            if(w[j] > w[j + 1])
            {
                int temp;
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
                temp = u[j];
                u[j] = u[j + 1];
                u[j + 1] = temp;
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    int minCost = 0;
    int count = 0;
    printf("\nEdges in MST:\n");
    for(int i = 0; i < e && count < n - 1; i++)
    {
        int p1 = find(u[i]);
        int p2 = find(v[i]);
        if(p1 != p2)
        {
            printf("%d -- %d  Cost = %d\n",
                   u[i], v[i], w[i]);
            minCost += w[i];
            unite(p1, p2);
            count++;
        }
    }
    end = clock();
    execution_time =(double)(end - start) / CLOCKS_PER_SEC;
    printf("\nMinimum Cost = %d\n", minCost);
    printf("Execution Time = %lf seconds\n",execution_time);
    return 0;
}

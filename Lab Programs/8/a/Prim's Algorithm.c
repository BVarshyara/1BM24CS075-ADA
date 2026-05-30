#include <stdio.h>
#include <time.h>
#define MAX 20
#define INF 9999
int main()
{
    int n;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int minCost = 0;
    int edges = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter Cost Adjacency Matrix:\n");
    printf("(Enter %d for no edge)\n", INF);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    }
    clock_t start, end;
    double execution_time;
    start = clock();
    visited[0] = 1;
    printf("\nEdges in MST:\n");
    while(edges < n - 1)
    {
        int min = INF;
        int u = -1, v = -1;
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d -> %d  Cost = %d\n", u, v, min);
        minCost += min;
        visited[v] = 1;
        edges++;
    }
    end = clock();
    execution_time =(double)(end - start) / CLOCKS_PER_SEC;
    printf("\nMinimum Cost = %d\n", minCost);
    printf("Execution Time = %lf seconds\n",execution_time);
    return 0;
}

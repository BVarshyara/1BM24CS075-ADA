#include <stdio.h>
#include <time.h>
int NN;
int p[100], pi[100];
int dir[100];
void PrintPerm()
{
    for (int i = 1; i <= NN; i++)
        printf("%d ", p[i]);
    printf("\n");
}
void Move(int x, int d)
{
    int z;
    z = p[pi[x] + d];
    p[pi[x]] = z;
    p[pi[x] + d] = x;
    pi[z] = pi[x];
    pi[x] = pi[x] + d;
}
void Perm(int n)
{
    if (n > NN)
        PrintPerm();
    else
    {
        Perm(n + 1);
        for (int i = 1; i <= n - 1; i++)
        {
            Move(n, dir[n]);
            Perm(n + 1);
        }
        dir[n] = -dir[n];
    }
}
int main()
{
    clock_t start, end;
    double execution_time;
    printf("Enter n: ");
    scanf("%d", &NN);
    for (int i = 1; i <= NN; i++)
    {
        p[i] = i;
        pi[i] = i;
        dir[i] = -1;
    }
    printf("\nPermutations:\n");
    start = clock();
    Perm(1);
    end = clock();
    execution_time =
        (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nExecution Time = %lf seconds\n",
           execution_time);
    return 0;
}

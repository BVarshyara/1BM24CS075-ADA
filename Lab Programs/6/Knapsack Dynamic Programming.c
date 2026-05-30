#include <stdio.h>
#include <time.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
// 0/1 Knapsack using Dynamic Programming
int knapsack(int W, int wt[], int pt[], int n) {
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(pt[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int pt[n], wt[n];
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);
    printf("Enter profit of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pt[i]);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    clock_t start, end;
    start = clock();   // Start time
    int result = knapsack(W, wt, pt, n);
    end = clock();     // End time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nMaximum Profit = %d\n", result);
    printf("Execution Time = %f seconds\n", time_taken);
    return 0;
}

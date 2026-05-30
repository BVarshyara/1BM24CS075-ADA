#include <stdio.h>
#include <time.h>
int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int value[n], weight[n];
    float ratio[n];
    printf("Enter value and weight:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &value[i], &weight[i]);
        ratio[i] = (float)value[i] / weight[i];
    }
    printf("Enter capacity: ");
    scanf("%d", &W);
    clock_t start = clock();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(ratio[j] < ratio[j + 1]) {
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
                int t1 = value[j];
                value[j] = value[j + 1];
                value[j + 1] = t1;
                int t2 = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = t2;
            }
        }
    }
    float totalProfit = 0.0;
    for(int i = 0; i < n; i++) {
        if(weight[i] <= W) {
            totalProfit += value[i];
            W -= weight[i];
        } else {
            totalProfit += value[i] * ((float)W / weight[i]);
            break;
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Maximum Profit = %.2f\n", totalProfit);
    printf("Execution Time = %f seconds\n", time_taken);
    return 0;
}

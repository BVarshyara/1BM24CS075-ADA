#include <stdio.h>
#include <time.h>
#define MAX 100
int main()
{
    int low, mid, high;
    int a[MAX], b[MAX];
    printf("Enter low index: ");
    scanf("%d", &low);
    printf("Enter mid index: ");
    scanf("%d", &mid);
    printf("Enter high index: ");
    scanf("%d", &high);
    printf("\nEnter %d sorted elements:\n", high + 1);
    for (int i = low; i <= high; i++)
        scanf("%d", &a[i]);
    clock_t start, end;
    double execution_time;
    start = clock();
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    end = clock();
    execution_time =
        ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nMerged Array:\n");
    for (k = low; k <= high; k++)
        printf("%d ", b[k]);
    printf("\n");
    printf("\nExecution Time = %lf seconds\n",
           execution_time);
    return 0;
}

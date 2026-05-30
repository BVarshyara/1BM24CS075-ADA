#include <stdio.h>
#include <time.h>
#define MAX 100
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    while (1)
    {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}
void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(a, low, high);
        quicksort(a, low, pivotIndex - 1);
        quicksort(a, pivotIndex + 1, high);
    }
}
int main()
{
    int a[MAX];
    int n;
    clock_t start, end;
    double execution_time;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();
    execution_time =
        (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("\nExecution Time = %lf seconds\n",
           execution_time);
    return 0;
}

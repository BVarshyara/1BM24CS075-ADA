#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
int board[MAX];
int solutionCount = 0;
int isSafe(int row, int col)
{
    int i;
    for (i = 0; i < row; i++)
    {
        if (board[i] == col)
            return 0;
        if (abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}
void printBoard(int n)
{
    int i, j;
    printf("\nSolution %d:\n\n", ++solutionCount);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}
void solveNQueens(int row, int n)
{
    int col;
    if (row == n)
    {
        printBoard(n);
        return;
    }
    for (col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}
int main()
{
    int n;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    start = clock();
    solveNQueens(0, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTotal Solutions = %d\n", solutionCount);
    printf("Execution Time = %f seconds\n", cpu_time_used);
    return 0;
}

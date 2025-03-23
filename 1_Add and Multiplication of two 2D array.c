#include <stdio.h>
#define ROWS 2
#define COLS 2

// Function to input matrices
void inputMatrix(const char *input, int matrix[ROWS][COLS])
{
    printf("Enter the elements of %s\n", input);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%s[%d][%d]: ", input, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix
void displayMatrix(const char *operation, int matrix[ROWS][COLS])
{
    printf("\n%s:\n", operation);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrixA[ROWS][COLS], matrixB[ROWS][COLS], add[ROWS][COLS], multiply[ROWS][COLS];

    // Input first matrix
    inputMatrix("Matrix A", matrixA);

    // Input second matrix
    inputMatrix("Matrix B", matrixB);

    // Display matrices
    displayMatrix("Matrix A", matrixA);
    displayMatrix("Matrix B", matrixB);

    // Addition of matrices
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            add[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // result of addition
    displayMatrix("Addition of Matrix A and Matrix B", add);

    // Multiplication of matrices
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            multiply[i][j] = 0;
            for (int k = 0; k < COLS; k++)
            {
                multiply[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // result of multiplication
    displayMatrix("Multiplication of Matrix A and Matrix B", multiply);

    return 0;
}

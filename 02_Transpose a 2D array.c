#include <stdio.h>
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Input the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare the original and transposed matrices
    int matrix[rows][cols], transpose[cols][rows];

    // Input the matrix
    inputMatrix(rows, cols, matrix);

    // Transpose the matrix
    transposeMatrix(rows, cols, matrix, transpose);

    // Print the original matrix
    printf("\nOriginal Matrix:");
    printMatrix(rows, cols, matrix);

    // Print the transposed matrix
    printf("\nTransposed Matrix:");
    printMatrix(cols, rows, transpose);

    return 0;
}

#include <stdio.h>

#define MAX 100

void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[MAX][MAX], transposed[MAX][MAX];
    int rows, cols;

    // Read matrix dimensions
    printf("Enter the number of rows and columns:\n");
    scanf("%d%d", &rows, &cols);

    // Read matrix elements
    readMatrix(matrix, rows, cols);

    // Calculate transpose
    transposeMatrix(matrix, transposed, rows, cols);

    // Print original matrix
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, rows, cols);

    // Print transposed matrix
    printf("\nTransposed Matrix:\n");
    printMatrix(transposed, cols, rows);

    return 0;
}

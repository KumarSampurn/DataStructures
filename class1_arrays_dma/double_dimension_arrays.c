#include <stdio.h>

int calculateDiagonalSum(int size, int *matrix[size]) {
    int sum = 0;
    
    // Sum the diagonal elements
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }

    return sum;
}

int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the square matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element at position (%d, %d): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of diagonal elements using the function
    int diagonalSum = calculateDiagonalSum(n, matrix);

    printf("The sum of diagonal elements is: %d\n", diagonalSum);

    return 0;
}

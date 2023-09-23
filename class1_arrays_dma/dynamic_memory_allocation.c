#include <stdio.h>
#include <stdlib.h>

int* calculatePrefixSum(int* arr, int size) {
    int* prefixSum = (int*)malloc(size * sizeof(int));
    

    prefixSum[0] = arr[0];
    for (int i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

int main() {
    int n;

    printf("Enter size ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

  
    int* prefixSum = calculatePrefixSum(arr, n);


    printf("Prefix sum of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");


    free(arr);
    free(prefixSum);

    return 0;
}

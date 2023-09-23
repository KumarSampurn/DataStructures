#include <stdio.h>

int max_frequency_count(int *a, int n) {
    int max_freq = 0, freq;

    for (int i = 0; i < n; i++) {
        freq = 1;  // Initialize frequency for the current element to 1

        for (int j = i + 1; j < n; j++) {
            if (a[j] == a[i])
                freq++;
        }

        if (freq > max_freq) {
            max_freq = freq;
        }
    }

    return max_freq;
}

void reverse_array(int *array, int n) {
    int temp;

    for (int i = 0; i < n / 2; i++) {
        // Swap elements from the beginning and end of the array
        temp = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = temp;
    }
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    printf("Max frequency count: %d\n", max_frequency_count(array, n));

    printf("Array before reversal:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    reverse_array(array, n);

    printf("Array after reversal:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

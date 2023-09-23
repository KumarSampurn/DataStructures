#include <stdio.h>

int fibo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int fact(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void foo(int n) {
    if (n <= 1) {
        return;
    }

    printf("%d + %d\n", n, n - 1);
    foo(n - 1);
    printf("%d + %d\n", n, n - 1);
}

int main() {
    int n, result;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Fibonacci series
    printf("Fibonacci series:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibo(i));
    }
    printf("\n");

    // Factorial
    printf("Factorial of %d: %d\n", n, fact(n));

    // GCD using Euclidean algorithm
    int a = 48, b = 18;  // Example values, you can change them
    result = gcd(a, b);
    printf("GCD of %d and %d is: %d\n", a, b, result);

    // Recursive function demonstration
    printf("Recursive function demonstration:\n");
    foo(n);

    return 0;
}

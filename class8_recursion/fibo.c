#include <stdio.h>

int fibo(int n){

    if (n<=1)
    {
        return n;
    }

    return fibo(n-1)+fibo(n-2);
    
}

int fact(int n){

    if (n<=1)
    {
        return 1;
    }

    return n*fact(n-1);
    
}

//eculedian gcd 



int foo(int n){
    if(n<=1){
        return 0;
    }

    printf("%d + %d" , n,n-1);
    foo(n-1);
    printf("%d + %d" , n,n-1); 
}


// n=6


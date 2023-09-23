#include <stdio.h>

int max_frequency_count(int *a,int n){
    int freq=0, max_freq=0 , fre_ele;
    for (int i = 0; i < n; i++)
    {
        freq=0;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]==a[i])
                freq++;   
        }
        if (freq> max_freq)
            max_freq=freq;   
    }   
}

int reverse_array(int *array){
    

}

int main() {
    
    int n;

    printf("\nEnter n :");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("\n Element %d" , i);
        scanf("%d",&array[i]);
    }

    printf("%d", max_frequency_count(array,n));
   

    return 0; 
}
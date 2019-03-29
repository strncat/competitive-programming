#include <stdio.h>

/* 10107 - What is the Median? */

void insertion_sort_modified(long int *a, int size) {
    
    int j;
    long int temp;
    
    for (j=size-1; j>0; j--)
        if (a[j] < a[j-1]) {
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
        }
}

int main() {

    long int a[10000];
    int i=0, d;
    
    while (scanf("%ld", &a[i++]) == 1) {
        
        insertion_sort_modified(a, i);
        
        d = i/2;
        
        if (i%2 != 0)
            printf("%ld\n", a[d]);
        else {
            printf("%ld\n", (a[d]+a[d-1])/2);
        }
    }

    return 0;
}


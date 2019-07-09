#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

/* find the median using the parition method from quick sort */

#define M 1000001

void swap(int *a, int *b) {
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int first, int last) {
    
    int i, p; /* pivot element */
    int index; /* divide index for pivot element */
    
    p = last;
    index = first;
    
    for (i = first; i < last; i++)
        if (a[i] < a[p]) { /* swap */
            swap(&a[i], &a[index]);
            index++;
        }
    
    swap(&a[p], &a[index]);
    
    return index;
}

int median(int *a, int first, int last, int mid) {
    
    int p;
        if (first == last)
        return first;
        p = partition(a, first, last); /* select pivot */
    
    if (p == mid)
        return p;
    
    if (p > mid)
        return median(a, first, p - 1, mid);
    else
        return median(a, p + 1, last, mid);
}

int main() {
    
    int a[M] = {3, 1, 2, 4, 5}, n, i, p = -1, mid;
    
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
   
    mid = n / 2;
    p = median(a, 0, n - 1, mid);
    
    printf("%d", a[p]);
    
    return 0;
}
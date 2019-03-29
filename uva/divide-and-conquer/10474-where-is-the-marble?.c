#include <stdio.h>

/* 10474 - Where is the Marble?
 Sample Input
 4 1
 2
 3
 5
 1
 5
 5 2
 1
 3
 3
 3
 1
 2
 3
 0 0
 Sample Output
 CASE# 1:
 5 found at 4
 CASE# 2:
 2 not found
 3 found at 3
*/

#define MAX 10000

int binary_search(int* a, int low, int high, int x) { /* this binary search finds the first occurrence of the element */
    
    int mid;
    
    while (low <= high) {
        
        mid = (low + high) / 2;
        
        if( (mid == 0 || x > a[mid - 1]) && a[mid] == x)
            return mid;
        
        else if (x > a[mid])
            low = mid + 1;
        
        else
            high = mid - 1;
    }
    return -1;
}

void counting_sort(int* a, int* b, int n, int k) { /* n is the size of the array, k is the upper limit */
    
    int i, c[MAX];
    
    for (i = 0; i <= k; i++)
        c[i] = 0;
    
    for (i = 0; i < n; i++) /* c[i] contains the number of elements = i */
        c[a[i]]++;
    
    for (i = 1; i <= k; i++) /* c[i] contains the number of elements <= i */
        c[i] += c[i - 1];
    
    for (i = n - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
}

int main() {
    
    int i, N, Q, marples[MAX], sorted_marples[MAX], q, counter = 1, result;
    
    while (scanf("%d %d", &N, &Q) == 2 && N && Q) {
        
        for (i = 0; i < N; i++)
            scanf("%d", &marples[i]);
        
        counting_sort(marples, sorted_marples, N, MAX);
 
        printf("CASE# %d:\n", counter++);
        
        for (i = 0; i < Q; i++) {
            scanf("%d", &q);
            
            result = binary_search(sorted_marples, 0, N - 1, q);
            
            if (result == -1)
                printf("%d not found\n", q);
            else
                printf("%d found at %d\n", q, result + 1);
        }
    }
    return 0;
}
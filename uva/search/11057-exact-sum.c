#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

/* 11057 - Exact Sum
 Sample Input
 2
 40 40
 80
 
 5
 10 2 6 8 4
 10
 
 3
 20 35 5
 40
 
 Sample Output
 
 Peter should buy books whose prices are 40 and 40.
 
 Peter should buy books whose prices are 4 and 6.
 
 Peter should buy books whose prices are 5 and 35.

 */

#define MAX 10060

void merge(int a[], int begin, int end, int mid) {
    
    int b[MAX], c[MAX];
    int i, j, k, m, index;
    
    for (i = 0; begin + i <= mid; i++)
        b[i] = a[begin + i];
    
    for (j = 0; mid + 1 + j <= end; j++)
        c[j] = a[mid + 1 + j];
    
    k = 0, m = 0, index = begin;
    while (k < i && m < j) {
        if (b[k] < c[m])
            a[index++] = b[k++];
        else
            a[index++] = c[m++];
    }
    
    /* left overs */
    while (k < i)
        a[index++] = b[k++];
    while (m < j)
        a[index++] = c[m++];
    
}

void merge_sort(int a[], int begin, int end) {
    
    int mid = (end + begin) / 2;
    
    if (end - begin > 0) {
        merge_sort(a, begin, mid);
        merge_sort(a, mid + 1, end);
        merge(a, begin, end, mid);
    }
    return;
}

int main() {
    
    int i, j, N, M, books[MAX], min_diff, best_i, best_j;
 
    while (scanf("%d", &N) == 1) {
        
        for (i = 0; i < N; i++)
            scanf("%d", &books[i]);
        
        merge_sort(books, 0, N - 1);
        
        scanf("%d", &M);
        
        /* Peter should buy books whose prices are i and j
         where i and j are the prices of the books whose sum is equal to M and i ≤ j
         if there are multiple solutions print the solution that minimizes the difference between the prices i and j*/
        
        min_diff = INT_MAX;
        best_i = -1;
        best_j = -1;
        
        for (i = 0; i < N; i++)
            for (j = i + 1; j < N; j++) {
                if (books[i] + books[j] == M && (books[j] - books[i]) < min_diff) {
                    min_diff = books[j] - books[i];
                    best_i = i;
                    best_j = j;
                }
            }
        printf("Peter should buy books whose prices are %d and %d.\n\n", books[best_i], books[best_j]);
    }
    
    return 0;
}
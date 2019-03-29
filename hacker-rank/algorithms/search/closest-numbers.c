#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Closest Numbers
 Sample Input #1
 10
 -20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854
 Sample Output #1
 -20 30
 Sample Input #2
 12
 -20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 -520 -470
 Sample Output #2
 -520 -470 -20 30
 Sample Input #3
 4
 5 4 3 2
 Sample Output #3
 2 3 3 4 4 5
*/

#define N 200001

void merge(int *a, int first, int mid, int last) {
    
    int b[N], c[N];
    int i, j, k, m, index;
    
    for (i = 0; i + first <= mid; i++)
        b[i] = a[i + first];
    
    for (j = 0; j + mid + 1 <= last; j++)
        c[j] = a[j + mid + 1];
    
    m = k = 0;
    index = first;
    while (m < i && k < j) {
        if (b[m] < c[k]) {
            a[index++] = b[m++];
        } else {
            a[index++] = c[k++];
        }
    }
    while (m < i)
        a[index++] = b[m++];
    
    while (k < j)
        a[index++] = c[k++];
}

void merge_sort(int *a, int first, int last) {
    
    int mid = (first + last) / 2;
    
    if (first < last) {
        merge_sort(a, first, mid);
        merge_sort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

int main() {
    
    int n, min, a[N], pairs[N + N], count = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    merge_sort(a, 0, n - 1);
    
    min = INT_MAX;
    for (int i = 0; i < n - 1; i++)
        if (a[i + 1] - a[i] < min)
            min = a[i + 1] - a[i];
    
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] == min) {
            pairs[count++] = a[i];
            pairs[count++] = a[i + 1];
        }
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d ", pairs[i]);
    }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Pairs
 N <= 10^5
 0 < K < 10^9
 --
 Sample Input #00:
 5 2
 1 5 3 4 2
 Sample Output #00:
 3
 Sample Input #01:
 10 1
 363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 1069262793
 Sample Output #01:
 0
*/

#define N 500001

int binary_search(int *a, int n, int key) {
    
    int first = 0, last = n - 1;
    
    while (first <= last) {
        int mid = (first + last) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

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
    
    int i, n, k, a[N], index, total = 0;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    merge_sort(a, 0, n - 1);
    
    for (i = 0; i < n; i++) {
        index = binary_search(a, n, a[i] + k);
        if (index != -1 && index != i) {
            total++;
        }
    }
    
    printf("%d", total);
    
    return 0;
}



#include <stdio.h>

/* 10720 - Graph Construction
Sample Input
4 3 3 3 3
6 2 4 5 5 2 1
5 3 2 3 2 1
0
Output for Sample Input
Possible
Not possible
Not possible
*/

#define N 10001

void merge(int a[], int begin, int end, int mid) {
    
    int b[N], c[N];
    int i, j, k, m, index;
    
    for (i = 0; begin + i <= mid; i++)
        b[i] = a[begin + i];
    
    for (j = 0; mid + 1 + j <= end; j++)
        c[j] = a[mid + 1 + j];
    
    k = 0, m = 0, index = begin;
    while (k < i && m < j) {
        if (b[k] > c[m])
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

int erdos_gallai(int a[], int n) {
    
    int i, k, sum, min_sum;
    
    for (k = 1; k <= n; k++) {
        
        /* find the sum first */
        sum = 0;
        for (i = 1; i <= k; i++)
            sum += a[i];
        
        min_sum = k * (k - 1);
        for (i = k+1; i <= n; i++)
            if (a[i] < k)
                min_sum += a[i];
            else
                min_sum += k;
        
        if (sum > min_sum)
            return 0;
    }
    return 1;
}

int main() {

    int n, i, a[N], total, negative;
    
    while (scanf("%d", &n) == 1 && n) {
        
        total = 0;
        negative = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            total += a[i];
            if (a[i] < 0)
                negative = 1;
        }
        
        merge_sort(a, 1, n);
        
        if ((total % 2 == 0) && n != 1 && !negative && erdos_gallai(a, n))
            printf("Possible\n");
        else if (n == 1 && a[1] == 0)
            printf("Possible\n");
        else
            printf("Not possible\n");
    }
    
    return 0;
}


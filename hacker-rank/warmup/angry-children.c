#include <stdio.h>

/* Angry Children
1 <= N <= 10^5
1 <= K <= N
0 <= number of candies in any packet <= 10^9
Sample Input #00
7
3
10
100
300
200
1000
20
30
Sample Output #00
20
Sample Input #01
10
4
1
2
3
4
10
20
30
40
100
200
Sample Output #01
3
*/

#define N 100000

void merge(unsigned long long int a[], int begin, int end, int mid) {
    
    long long int b[N], c[N];
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

void merge_sort(unsigned long long int a[], int begin, int end) {
    
    int mid = (end + begin) / 2;
    
    if (end - begin > 0) {
        merge_sort(a, begin, mid);
        merge_sort(a, mid + 1, end);
        merge(a, begin, end, mid);
    }
    return;
}

int main() {

    int i, n, k;
    unsigned long long int a[N];
    
    scanf("%d", &n);
    scanf("%d", &k);
    
    for (i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    
    merge_sort(a, 0, n - 1);
    
    unsigned long long int min = 10000000000;
    for (i = 0; i <= n - k; i++) {
        if (a[k + i - 1] - a[i] < min)
            min = a[k + i - 1] - a[i];
    }
    printf("%lld\n", min);
    
    return 0;
}

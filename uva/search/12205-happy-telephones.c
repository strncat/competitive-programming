#include <stdio.h>

/* 12205 - Happy Telephones
  1 <= N < 10 000
  1 <= M < 100
  1 <= Duration <= 10,000
  Start >= 0
 Sample Input
 3 2
 3 4 2 5
 1 2 0 10
 6 5 5 8
 0 6
 8 2
 1 2
 8 9 0 10
 9 1
 10 1
 0 0
 Sample Output
 3
 2
 1
 0
*/

#define N 10000
#define M 100

void merge(int a[N][2], int begin, int end, int mid) { /* standard merge sort, maybe sorting isn't really needed */
    
    int b[N][2], c[N][2];
    int i, j, k, m, index;
    
    for (i = 0; begin + i <= mid; i++) {
        b[i][0] = a[begin + i][0];
        b[i][1] = a[begin + i][1];
    }
    
    for (j = 0; mid + 1 + j <= end; j++) {
        c[j][0] = a[mid + 1 + j][0];
        c[j][1] = a[mid + 1 + j][1];
    }
    
    k = 0, m = 0, index = begin;
    while (k < i && m < j) {
        if (b[k][0] < c[m][0] || (b[k][0] == c[m][0] && b[k][1] < c[m][1])) {
            a[index][0] = b[k][0];
            a[index][1] = b[k][1];
            index++;
            k++;
        }
        else {
            a[index][0] = c[m][0];
            a[index][1] = c[m][1];
            index++;
            m++;
        }
    }
    /* left overs */
    while (k < i) {
        a[index][0] = b[k][0];
        a[index][1] = b[k][1];
        index++;
        k++;
    }
    while (m < j) {
        a[index][0] = c[m][0];
        a[index][1] = c[m][1];
        index++;
        m++;
    }
}

void merge_sort(int a[N][2], int begin, int end) {
    
    int mid = (end + begin) / 2;
    
    if (end - begin > 0) {
        merge_sort(a, begin, mid);
        merge_sort(a, mid + 1, end);
        merge(a, begin, end, mid);
    }
    return;
}

int main() {

    int i, j, n, m, calls[N][2], intervals[M][2], source, destination, count;
    
    while (scanf("%d %d", &n, &m) == 2) {
        
        if (n == 0 && m == 0)
            break;
        
        for (i = 0; i < n; i++) { /* read calls */
            scanf("%d %d %d %d", &source, &destination, &calls[i][0], &calls[i][1]);
            calls[i][1] += calls[i][0]; /* store finish time instead of duration */
        }
        
        merge_sort(calls, 0, n - 1); /* sort calls based on start time then finish time */
        
        for (i = 0; i < m; i++) { /* real intervals */
            scanf("%d %d", &intervals[i][0], &intervals[i][1]);
            intervals[i][1] += intervals[i][0];
            
            count = 0;
            for (j = 0; j < n; j++) { /* for each interval check if it intersects with any call from 0 to n */
                if (intervals[i][0] >= calls[j][0] && intervals[i][0] < calls[j][1]) /* interval intersection */
                    count++;
                else if (calls[j][0] >= intervals[i][0] && calls[j][0] < intervals[i][1]) /* interval intersection */
                    count++;
                else if (calls[j][0] > intervals[i][1]) /* call start time > interval end time => no more calls can intersect since they are sorted */
                    break;
            }
            printf("%d\n", count);
        }
    }
    return 0;
}
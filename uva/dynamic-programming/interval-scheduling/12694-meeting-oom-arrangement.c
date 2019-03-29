#include <stdio.h>

/* 12694 - Meeting Room Arrangement
 Used Interval Scheduling from Algorithms Design, way over the top for this one I know
 Sample Input 3 0 6 5 7 8 9 5 9 1 2 3 4 0 5 0 0 6 10 5 6 0 3 0 5 3 5 4 5 0 0 1 5 3 9 0 0 Sample Output
 4 4 1
 */

#define N 25
#define maximum(a, b) a > b ? a : b

void merge(int a[N][2], int begin, int end, int mid) {
    
    int b[N][N], c[N][N];
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
        if (b[k][1] < c[m][1]) {
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

/* let p(j) be the (largest) index i < j such that i & j are disjoint */
void disjoint(int a[N][2], int p[N], int n) {
    
    int i, j;
    
    p[0] = 0;
    for (i = 1; i < n; i++)
        for (j = i - 1; j >= 0; j--)
            if (a[i][0] >= a[j][1]) {
                p[i] = j;
                break;
            }
}

void build_table(int a[N][2], int M[N], int v[N], int p[N], int n) {
    
    int j;
    
    M[0] = 0;
    for (j = 1; j < n; j++)
        M[j] = maximum(v[j] + M[p[j]], M[j - 1]);
    
}



int main() {
    
    int i, n, s, f, test_cases;
    int events[N][2], value[N], p[N] = {0}, M[N];
    
    scanf("%d", &test_cases);

    while(test_cases--) {
        
        n = 1;
        while (scanf("%d %d", &s, &f) == 2) {
            if (!s && !f)
                break;
            events[n][0] = s;
            events[n][1] = f;
            n++;
        }
        
        merge_sort(events, 1, n - 1); /* sorted in decreasing order by finish time */
        
        for (i = 1; i < n; i++)
            value[i] = 1;
        
        disjoint(events, p, n);
        
        build_table(events, M, value, p, n);
        
        printf("%d\n", M[n - 1]);
    }
    return 0;
}
#include <stdio.h>

/* 12049 - Just Prune The List */

/*
 1
 1 1
 1
 2
total = 2
 */

void merge(int a[], int begin, int end, int mid) {
    
    int b[10000], c[10000];
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
    
    if (k < i)
        while (k < i)
            a[index++] = b[k++];
    else
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

    int i, j, N, M, cases, first[10000], second[10000], total;
    
    scanf("%d", &cases);
    
    while (cases--) {
        
        scanf("%d %d", &N, &M);
        
        for (i = 0; i < N; i++)
            scanf("%d", &first[i]);
        
        for (i = 0; i < M; i++)
            scanf("%d", &second[i]);
        
        
        merge_sort(first, 0, N-1);
        merge_sort(second, 0, M-1);
        
        i = 0; j = 0, total = 0;
        while (i < N && j < M) {
            
            if (first[i] > second[j]) {
                j++;
                total++;
            }
            else if (first[i] < second[j]) {
                i++;
                total++;
            }
            else {
                i++;
                j++;
            }
        }
        
        if (i < N)
            while (i++ < N)
                total++;
        else if (j < M)
            while (j++ < M)
                total++;
        
        printf("%d\n", total);
    }

    return 0;
}


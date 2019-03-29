#include <stdio.h>
#include <string.h>

/* 10635 - Prince and Princess
 Sample Input
 1
 3 6 7
 1 7 5 4 8 3 9
 1 4 3 5 6 2 8 9
 Output for Sample Input
 Case 1: 4
 */

#define N 62600
#define max(a, b) (a > b ? a : b)

int binary_search(int *s, int *a, int first, int last, int x) {
    
    int mid;
    
    while (first < last) {
        
        mid = (first + last) / 2;
        
        if (a[s[mid]] == x)
            return mid;
        
        else if (a[s[mid]] > x)
            last =  mid;
        
        else
            first = mid + 1;
    }
    
    return first; /* or last */
}


int longest_increasing_sequence(int *a, int n) {
    
    int i, index, k, s[N];
    
    index = 1;
    s[1] = 0; /* s[i] is the smallest (index of) integer that ends an increasing sequence of length i */
    
    for (i = 1; i < n; i++) {
        
        if (a[i] > a[s[index]]) /* a new larger element is found, extend the sequence */
            s[++index] = i;
        
        /* else find the smallest element in s >= a[i] using binary search since s is sorted */
        /* basically insert a[i] in s such that s stays sorted */
        
        else {
            k = binary_search(s, a, 1, index, a[i]);
            if (a[s[k]] > a[i]) /* if truly greater than, otherwise no */
                s[k] = i;
        }
    }
    return index;
}

int main() {
    
    int test_cases, n, p, q, prince[N], princess[N];
    int i, j, x, count;
    
    scanf("%d", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
        
        count = 0;
        
        scanf("%d %d %d", &n, &p, &q);
        
        memset(prince, 0, sizeof(prince));
        memset(princess, 0, sizeof(princess));
        
        for (j = 1; j <= p + 1; j++) {
            scanf("%d", &x);
            prince[x] = j; /* the prince visited block x at step j */
        }
        
        for (j = 1; j <= q + 1; j++) {
            scanf("%d", &x);
            if (prince[x]) /* The princess steped on a block visited by the prince (common block) */
                princess[count++] = prince[x]; /* the prince visited block x on his step = prince[x] */
        }
        printf("Case %d: %d\n", i, longest_increasing_sequence(princess, count));
    }
    return 0;
}
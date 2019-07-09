#include <stdio.h>

/* Counting Sort 1 */

#define N 1000001

int main() {
    
    int i, n;
    int a[N], count[101];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
        count[i] = 0;
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        count[a[i]]++;
    }
    
    for (i = 0; i < 100; i++)
        printf("%d ", count[i]);
    printf("\n");
    
    return 0;
}

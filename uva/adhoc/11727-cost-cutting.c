#include <stdio.h>

/* 11727 - Cost Cutting
 3
 1000 2000 3000 Case 1: 2000
 3000 2500 1500 Case 2: 2500
 1500 1200 1800 Case 3: 1500
 */

#define N 3

int main() {
        
    int i, j, temp, n=1, a[3], test_cases;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        
        for (i=0; i<N; i++)
            for (j=i+1; j<N; j++)
                if (a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
        
        printf("Case %d: %d\n", n++, a[1]);
    }
    return 0;
}

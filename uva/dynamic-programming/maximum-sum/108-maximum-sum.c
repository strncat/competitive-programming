#include <stdio.h>
#include <string.h>

#define INF 999999 /* -127 is the least sum */

int main() {
    
    int N=0, i=0, j=0, k=0, sum=0, current_max = -INF, max = -INF;
    
    scanf("%d", &N);
    
    int a[N][N];
    int total[N];
        
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            scanf("%d", &a[i][j]);
    
    for (i = 0; i < N; i++) {
        
        memset(total, 0, N * sizeof(int));
        
        for (k = i; k < N; k++) {
            
            sum = 0;
            current_max = -INF;
            
            /* ---------- start kadane ------------ */
            for (j = 0; j < N; j++) {
                
                total[j] += a[k][j];
                sum += total[j];
                
                if (sum < 0) 
                    sum = 0;
                
                if (current_max < sum) 
                    current_max = sum;
            }
            /* ---------- end kadane ------------ */
            
            if (max < current_max) 
                max = current_max;
        }
    }
    printf("%d\n", max);

    return 0;
}

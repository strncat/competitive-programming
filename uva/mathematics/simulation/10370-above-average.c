#include <stdio.h>
#include <math.h>

int main() {
    
    int i=0, test_cases=0, sum=0, N=0, count=0; /* N: [1,1000] */
    int a[1000]; /* [0,100] */
    double avg=0.0f, percent=0.0f;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        sum = 0;
        count = 0;
        
        scanf("%d", &N);
        
        for (i=0; i<N; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        avg = (double)sum/(double)N;
        
        for (i=0; i<N; i++) 
            if (a[i] > avg)
                count++;
        
        percent = ((double)count/(double)N)*100;
        printf("%.3f%c\n", percent, '%');
    }
    return 0;
}

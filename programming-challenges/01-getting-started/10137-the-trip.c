#include <stdio.h>

// UVa [10137 - The Trip]

int main() {
    
    int i;
    long N;
    double sum, average, a[1000], diff, lowest, take, give;
    
    while (scanf("%ld", &N) == 1 && N) {
        
        sum = 0.0;
        for (i = 0; i < N; i++) {
            scanf("%lf", &a[i]);
            sum += a[i];
        }
        
        average = sum / N;
        take = 0.0;
        give = 0.0;
        

        for (i = 0; i < N; i++) {
            
            /*  Decrease percision by one digit by first multiplying by 100,
                casting to integer and back to double and finally dividing by 100!
            */
            diff = ((double) (long) ((a[i] - average) * 100)) / 100;
            
            if (diff < 0) /* Below Average */
                take += diff; /* should take money */
            else
                give += diff; /* should give money */
        }
        
        if (-take > give)
            lowest = -take;
        else
            lowest = give;
        
        printf("$%0.2lf\n", lowest);
        
    }
    return 0;
}

#include <stdio.h>

/* UVa [10137 - The Trip]
 3
 10.00
 20.00
 30.00
 4
 15.00
 15.01
 3.00
 3.01
 3
 6.17
 5.00
 4.03
 12
 123.12
 6.13
 9.44
 89.08
 278.78
 223.78
 78.45
 912.89
 554.76
 547.57
 1781.89
 907.07
 2
 4.99
 15.00
 1
 10.00
 15
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.01
 0.03
 5
 5000.00
 11.11
 11.11
 11.11
 11.11
 15
 0.01
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 0.03
 4
 25.00
 25.00
 25.00
 28.00
 3
 10.01
 15.25
 18.96
 4
 25.03
 25.00
 25.00
 25.00
 
 Output:
 $10.00
 $11.99
 $1.10
 $2407.09
 $5.00
 $0.00
 $0.01
 $3991.11
 $0.01
 $2.25
 $4.73

 */

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

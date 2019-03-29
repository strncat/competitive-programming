#include <stdio.h>
#include <math.h>

/* UVa [382 - Perfection]
 Sample Input
 15 28 6 56 60000 22 496 1 0
 Sample Output
 PERFECTION OUTPUT
 15  DEFICIENT
 28  PERFECT
 6  PERFECT
 56  ABUNDANT
 60000  ABUNDANT
 22  DEFICIENT
 496  PERFECT
 1   DEFICIENT
 END OF OUTPUT
 */
int factors[1000];

int unique_factors(int x) {
    
    int i = 2, counter = 0, max;
    max = sqrt(x);
    
    factors[counter++] = 1;
    
    while(i < max) {
        if(x%i == 0) {
            factors[counter++] = i;
            factors[counter++] = x/i;
        }
        i++;
    }
    
    if(x%i == 0) {
        factors[counter++] = i;
        if (i != x/i)
            factors[counter++] = x/i;
    }
    return counter;
}

int main() {
    
    int sum, x, counter, i;
    
    printf("PERFECTION OUTPUT\n");
    
    while (scanf("%d", &x) == 1 && x) {
        
        sum = 0;
        counter = unique_factors(x);
        
        for (i=0; i<counter; i++)
            sum += factors[i];
        
        if (x == 1)
            printf("%5d  DEFICIENT\n", x);
        else if(sum == x)
            printf("%5d  PERFECT\n", x);
        else if (sum < x)
            printf("%5d  DEFICIENT\n", x);
        else
            printf("%5d  ABUNDANT\n", x);
    }
    printf("END OF OUTPUT\n");
    return 0;
}

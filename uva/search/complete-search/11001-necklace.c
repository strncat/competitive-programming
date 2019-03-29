#include <stdio.h>
#include <math.h>

/* 11001 - Necklace
 Sample Input
 10 1
 10 2
 26145 11
 0 0
 Sample Output
 5
 0
 1188
 */

#define MAX 10060

int main() {
    
    double D, total, v, part, best_length, length, previous_length;
    int i, best_i;
 
    while (scanf("%lf %lf", &total, &v) == 2 && total && v) {
        
        if (total > v) {
            
            best_length = 0.3 * sqrt ((total - v)); /* for when i = 1 */
            previous_length = best_length;
            
            for (i = 2; i <= total; i++) {
                
                part = total / i;
                
                if (part <= v)
                    break;
                    
                D = 0.3 * sqrt ((part - v));
                
                length = D * i;
                
                if (fabs(previous_length - length) < 1e-12 ) {
                    best_length = -1;
                    break;
                }
                previous_length = length;
        
                if (length > best_length) {
                    best_length = D * i;
                    best_i = i;
                }
            }
            
            if (best_length > 0)
                printf("%d\n", best_i);
            else
                printf("0\n");
        }
        else
            printf("0\n");
    }
    return 0;
}
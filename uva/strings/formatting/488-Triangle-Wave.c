#include <stdio.h>

/*  488 - Triangle Wave

 Sample Input
 
 1
 
 3
 2
 Sample Output
 
 1
 22
 333
 22
 1
 
 1
 22
 333
 22
 1

*/

int main() {
    
    int i, j, amplitude, frequency, p, cases;
    
    scanf("%d", &cases);
    
    while (cases--) {
        
        scanf("%d %d", &amplitude, &frequency);
        
        while (frequency--) {
            
            /* print wave */
            for (i=0; i<amplitude; i++) {
                p = i;
                for (j=p; j>=0; j--)
                    printf("%d", p+1);
                printf("\n");
            }
            for (i=amplitude-1; i>=0; i--) {
                p = i;
                for (j=p; j>0; j--)
                    printf("%d", p);
                
                if(frequency != 0 || cases != 0 || i != 0)
                    printf("\n");
            }
        }
    }
    return 0;
}
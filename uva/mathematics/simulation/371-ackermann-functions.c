#include <stdio.h>

/* UVa [371 - Ackermann Functions] */

int main() {
    
    int L, H, temp;
    long term, sum, max_sum, a, max_term;
    
    while (scanf("%d %d", &L, &H) == 2 && L && H) {
        
        if (L > H) {
            temp = L;
            L = H;
            H = temp;
        }

        max_sum = 0;
        for (a=L; a<=H; a++) {
            term = a;
            sum = 0;
            
            do {
                sum += 1;
                if (term%2)
                    term = 3*term+1;
                else
                    term = term/2;
            } while (term != 1);
            
            if (sum > max_sum) {
                max_sum = sum;
                max_term = a;
            }
        }
        printf("Between %d and %d, %ld generates the longest sequence of %ld values.\n", L, H, max_term, max_sum);
    }
    return 0;
}

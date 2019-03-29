#include <stdio.h>

/* 694 - The Collatz Sequence 
 3 100
 34 100
 75 250
 27 2147483647
 101 304
 101 303
 -1 -1
 
 Case 1: A = 3, limit = 100, number of terms = 8
 Case 2: A = 34, limit = 100, number of terms = 14
 Case 3: A = 75, limit = 250, number of terms = 3
 Case 4: A = 27, limit = 2147483647, number of terms = 112
 Case 5: A = 101, limit = 304, number of terms = 26
 Case 6: A = 101, limit = 303, number of terms = 1
 
 Step 2: If A = 1 then stop.
 Step 3: If A is even, then replace A by A / 2 and go to step 2.
 Step 4: If A is odd, then replace A by 3 * A + 1 and go to step 2.
 */

int main() {
    
    long int A, L, a;
    int n=0, t=0;
    
    while (scanf("%ld %ld", &A, &L) == 2) {
        
        if (A <0 && L < 0)
            break;
        
        a = A;
        t = 0;
        while (a <= L && a != 1) {
            
            if (a%2 == 0)
                a /= 2;
            else 
                a = 3*a + 1;
            
            t++;
        }
        
        if (a == 1) t++;
        
        n++;
        
        printf("Case %d: A = %ld, limit = %ld, number of terms = %d\n", n, A, L, t);
        
    }
    
    return 0;
}



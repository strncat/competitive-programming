#include <stdio.h>
#include <math.h>

/*  UVa - 10110 - Light, more light
   
   1- nth switch is on if it was switched for an odd number of times
   2- also nth switch gets turned on/off whenever i is a factor of n. 
   3- If the number of factors is odd => yes else => no
   4- The number of factors is odd iff n is a perfect square
   
   test cases:
   3     no
   6241  yes
   8191  no   
 */

int main() {
    
    unsigned int n;
    double t;
    
    while (scanf("%ud", &n) == 1)
    {
        if (n == 0)
            break;
        
        t = sqrt(n);
        
        if (floor(t) == t)
            printf("yes\n");
        else
            printf("no\n");

    }

    return 0;
}


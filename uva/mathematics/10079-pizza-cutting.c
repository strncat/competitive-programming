#include <stdio.h>

/* 10079 - Pizza Cutting
 f(n) = n(n+1)/2  + 1
 1->2
 2->4
 3->7
 4->11
 5->16
 10->56
 Sample Input:
 5
 10
 -100
 Sample Output:
 16
 56
 
*/

int main() {

    long int n;
    
    while (scanf("%ld", &n) == 1) {
       
        if (n < 0)
            break;
        
        printf("%ld\n", (n * (n + 1)) / 2 + 1);
        
    }
    return 0;
}
#include <stdio.h>
#include <math.h>

/* test cases 
 
 12
 15 10
 88 9
 155 22
 20 10
 40 12
 75 25
 13 7
 888 222
 9999 1111
 12365 123
 99 11
 13 19
 
 impossible
 impossible
 impossible
 15 5
 26 14
 50 25
 10 3
 555 333
 5555 4444
 6244 6121
 55 44
 impossible
 
*/

int main() {
    
    long int n, a, b;
    long int first, second;
    
    scanf("%ld", &n);

    while (n--) {
        
        scanf("%ld %ld", &a, &b);
        
        first = (a + b) / 2;
        second = (a - b) / 2;
        
        if (first < 0 || second < 0 || (a + b)%2)
            printf("impossible\n");
        else if (first > second)
            printf("%ld %ld\n", first, second);
        else
            printf("%ld %ld\n", second, first);
    }
    return 0;
}
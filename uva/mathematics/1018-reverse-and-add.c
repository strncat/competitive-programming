#include <stdio.h>
#include <string.h>

/* Example: 
 test cases:
 3004344444  -> 1 7448778447
 2 -> 0 2
 */

long long int reverse(long long int x) {
    
    long long int y = 0;
    
    while (x) {
        y = y * 10;
        y = y + x%10;
        x = x/10;
    }
    return y;
}

int is_palindrome(long long int x) {
    
    int digits[10]; /* MAX 10 digits */
    int n=0, i=0;
    
    while(x){
        digits[n++] = x%10;
        x = x/10;
    }
    
    for(i=0; i<n-i-1; ++i)
        if(digits[i] != digits[n-i-1])
            return 0;
    
    return 1;
}

int main() {
    
    int test_cases=0, i=0;
    long long int sum=0;
    
    scanf("%d", &test_cases);
 
    while(test_cases--) {

        scanf("%lld", &sum);
        i = 0;
            
        while (!is_palindrome(sum)) {
            sum += reverse(sum);
            ++i;
        }
        
        printf("%d %lld\n", i, sum);
}
    return 0;
}

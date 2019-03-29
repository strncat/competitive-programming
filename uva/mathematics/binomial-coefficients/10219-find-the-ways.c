#include <stdio.h>
#include <math.h>

/* 10219 - Find the ways !
 Sample Input
 20 5
 100 10
 200 15
 
 Sample Output
 5
 14
 23
 
 tried first the naive approach and it didn't work of course
 The number of digits in a number is floor (log10 (abs (x))) + 1
 WOW! got so many wrong answers!! the double has to be long double! thanks to the uva forum hint
 */

int bionomial_rec(int n, int k) { /* for reference */
    if (k == 0 || n == k)
        return 1;
    return bionomial_rec(n - 1, k - 1) + bionomial_rec(n - 1, k);
}

int digit_count(long long int n, long long int k) {
    long long int i;
    long double total = 0;
    
    for (i = n; i > n - k; i--)
        total += log10(i);
    
    for (i = 1; i <= k; i++)
        total -= log10(i);
    
    return (int) total + 1;
}

int main() {

    long long int n, k;

    while (scanf("%lld %lld", &n, &k) == 2)
        printf("%d\n", digit_count(n, k));
    
    return 0;
}

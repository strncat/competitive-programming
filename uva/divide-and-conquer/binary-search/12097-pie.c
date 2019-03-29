#include <stdio.h>
#include <limits.h>
#include <math.h>

#define PI 3.14159265358979323846

/* N and F with 1 ≤ N, F ≤ 10000: */

/* 12097 - Pie
 Sample Input
 6
 3 3
 4 3 3
 1 24
 5
 10 5
 1 4 2 3 4 5 6 5 4 2
 1 1
 1
 5 5
 9 8 8 7 1
 25 100
 99 87 56 45 23 56 98 45 32 54 65 12 11 43 34 78 87 22 33 44 55 66 77 88 99
 1 0
 10000
 314159265.3587
 Sample Output
 25.1327
 3.1416
 50.2655
 1.5708
 100.5309
 2736.9555
 314159265.3587
 */

#define N 10010

int main() {
    
    int i, test_cases, n, people, pies[N], count, counter;
    double high, low, mid;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d %d", &n, &people);
        people++; /* include self */
        
        for (i = 0; i < n; i++) {
            scanf("%d", &pies[i]);
            pies[i] = pies[i] * pies[i];
            if (pies[i] > high)
                high = (double) pies[i]; /* using this gives WA as an upper limit */
        }
        
        /* choosing the(p)th smallest pie as the initial choice (if we have enough cakes) gives WA */
        /* the partition method takes O(n) anyways not worth it? since we're using binary search lg(n) */
        
        /* trying the brute force approach gives a TLE, Imagine 10000 pies and 10000 people
         with different pie sizes ~ 10000 * 10000 possible pie sizes to try out */
        
        /* Using a binary search (setting the high size to the biggest pie + 10000 and the low to zero */
        
        high = 100000000; /* biggest pie radius is 10000, radius * radius */
        low = 0.0;
        counter = 0;
        while (high - low > 1e-4) { /* comparing doubles in binary search needs an error window */
            
            mid = (low + high) / 2.0;
            
            /* is this size possible? */
            count = 0;
            for (i = 0; i < n; i++) {
                count += (pies[i] / mid);
                if (count >= people)
                    break;
            }
            if (count >= people) /* was more than enough maybe */
                low = mid; /* you can't do mid + 1 since since this is a double, look up binary search for doubles */
            else
                high = mid;
        }
        printf("%.4lf\n", mid * PI);
    }
    return 0;
}
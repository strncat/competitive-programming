#include <stdio.h>

/* 507 - Jill Rides Again
 Sample Input
 6
 
 3
 -1
 6
 
 10
 4
 -5
 4
 -3
 4
 4
 -4
 4
 -5
 
 4
 -2
 -3
 -4
 
 11
 1
 1
 1
 -100
 2
 2
 -100
 1
 1
 1
 
 7
 1
 2
 3
 -34
 3
 3
 
 7
 3
 3
 -34
 1
 2
 3
 Sample Output
 The nicest part of route 1 is between stops 2 and 3
 The nicest part of route 2 is between stops 3 and 9
 Route 3 has no nice parts
 The nicest part of route 1 is between stops 5 and 7
 The nicest part of route 1 is between stops 1 and 4
 The nicest part of route 2 is between stops 4 and 7
*/

void kadane(int *a, int size, int *location) {
    
    int i, sum = 0, max_sum = 0, begin = 0, distance = 0;
    
    location[0] = location[1] = -1;
    
    for (i = 0; i < size; i++) {
        
        sum += a[i];
        
        if (sum < 0) {
            sum = 0;
            begin = i + 1;
            continue;
        }
        
        if (sum > max_sum || (sum == max_sum && (i - begin) > distance)) {
            max_sum = sum;
            location[1] = i; /* so far it ends here */
            location[0] = begin; /* and it began the first time we reached sum < 0 */
            distance = location[1] - location[0];
        }
    }
}

int main() {
    
    int i, j, test_cases, stops, s[20000], location[2];
    
    scanf("%d", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
        
        scanf("%d", &stops);
        
        for (j = 0; j < stops - 1; j++)
            scanf("%d", &s[j]);

        kadane(s, stops-1, location);
        
        if (location[1] != -1)
            printf("The nicest part of route %d is between stops %d and %d\n", i, location[0]+1, location[1]+2);
        else
            printf("Route %d has no nice parts\n", i);
        
    }
    
    return 0;
}




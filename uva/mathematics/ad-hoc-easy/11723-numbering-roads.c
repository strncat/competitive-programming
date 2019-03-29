#include <stdio.h>

/* 11723 - Numbering Roads
 Sample Input
 8 5
 100 2
 1 1
 5 8
 53 2
 11 6
 7 7
 16 8
 0 0
 Sample Output
 Case 1: 1
 Case 2: impossible
 Case 3: 0
 Case 4: 0
 Case 5: 26
 Case 6: 1
 Case 7: 0
 */

int main() {
    
	int N, R, left, counter=1, total;
    
	while (scanf("%d %d", &R, &N) == 2 && N && R) {
        
        total = (R-1)/N;
        
        if (total <= 26)
            printf("Case %d: %d\n", counter++, total);
        else
            printf("Case %d: impossible\n", counter++);
    }
	return 0;
}
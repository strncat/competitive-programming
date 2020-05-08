#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

/* 1237 - Expert Enough?
 Sample Input
 1
 4
 HONDA 10000 45000
 PEUGEOT 12000 44000
 BMW 30000 75900
 CHEVROLET 7000 37000
 4
 60000
 7500
 5000
 10000
 Sample Output
 BMW
 CHEVROLET
 UNDETERMINED
 UNDETERMINED
 */

#define MAX 10000

int main() {
    
    int i, j, count, index, test_cases, nq, q, ncars, car[10000][2];
    char car_name[10000][25];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &ncars);
        
        for (i = 0; i < ncars; i++)
            scanf("%s %d %d", car_name[i], &car[i][0], &car[i][1]);
        
        scanf("%d", &nq);
        
        for (i = 0; i < nq; i++) {
            scanf("%d", &q);
            
            count = 0;
            for (j = 0; j < ncars; j++) {
                if (q >= car[j][0] && q <= car[j][1]) {
                    count++;
                    index = j;
                }
                if (count > 1)
                    break;
            }
    
        if (count == 1)
            printf("%s\n", car_name[index]);
        else
            printf("UNDETERMINED\n");
        }
        
        if (test_cases) /* no newline after the last test_case */
            printf("\n");
    }
    
    return 0;
}
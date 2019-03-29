#include <stdio.h>

/* 12157 - Tariff Plan
 Input:
 3
 2
 61 10
 3
 40 40 40
 2
 60 65
 Output:
 Case 1: Mile 40
 Case 2: Juice 45
 Case 3: Mile Juice 60
 */

int main() {

    int N, test_cases, i, k = 0, juice, mile, duration;
    
    scanf("%d", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
        
        scanf("%d", &N);
        mile = 0;
        juice = 0;
        
        for (k = 0; k < N; k++) {
            scanf("%d", &duration);
            
            mile += (duration / 30) + 1;
            juice += (duration / 60) + 1;
        }
        
        mile *= 10;
        juice *= 15;
        
        if (mile > juice)
            printf("Case %d: Juice %d\n", i, juice);
        
        else if (mile < juice)
            printf("Case %d: Mile %d\n", i, mile);
        
        else
            printf("Case %d: Mile Juice %d\n", i, mile);
    }
    return 0;
}
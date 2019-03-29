#include <stdio.h>

/* 11608 - No Problem
SAMPLE INPUT:
5
3 0 3 5 8 2 1 0 3 5 6 9
0 0 10 2 6 4 1 0 1 1 2 2
-1
 SAMPLE OUTPUT:
 Case 1:
 No problem! :D
 No problem! :D
 No problem. :(
 No problem! :D
 No problem! :D
 No problem! :D
 No problem! :D
 No problem! :D
 No problem! :D
 No problem! :D
 No problem! :D
 No problem! :D
*/

int main() {
    
    int i, n, repo[13], required, test_case = 1;
    
    while(1) {
        
        scanf("%d", &n);

        if (n < 0)
            break;
        
        repo[0] = n;
        
        for (i = 1; i <= 12; i++)
            scanf("%d", &repo[i]);
        
        printf("Case %d:\n", test_case++);
        
        for (i = 1; i <= 12; i++) {
            scanf("%d", &required);
            
            if (repo[i - 1] >= required) {
                repo[i] += (repo[i - 1] - required);
                printf("No problem! :D\n");
            }
            else {
                repo[i] += repo[i - 1];
                printf("No problem. :(\n");
            }
        }
    }
    return 0;
}
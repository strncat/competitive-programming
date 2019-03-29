#include <stdio.h>
#include <string.h>

/* CUBE SUMMATION
 2
 4 5
 UPDATE 2 2 2 4
 QUERY 1 1 1 3 3 3
 UPDATE 1 1 1 23
 QUERY 2 2 2 4 4 4
 QUERY 1 1 1 3 3 3
 2 4
 UPDATE 2 2 2 1
 QUERY 1 1 1 1 1 1
 QUERY 1 1 1 2 2 2
 QUERY 2 2 2 2 2 2
 
 OUTPUT
 4
 4
 27
 0
 1
 1
 */

int main() {
    
    int i, m, test_cases, N, M, x, y, z, x2, y2, z2, index, insert;
    long long int w, a[1010][4], total = 0;
    char operation[10];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        memset(a, 0, sizeof(a));
        index = 1;
        
        scanf("%d %d", &N, &M);
        
        for (m = 0; m < M; m++) {
            
            scanf("%s", operation);
            
            if (strcmp(operation, "UPDATE") == 0) {
                scanf("%d %d %d %lld", &x, &y, &z, &w);
                insert = 1;
                
                for (i = 1; i < index; i++)
                    if (a[i][1] == x && a[i][2] ==y && a[i][3] == z) {
                        a[i][0] = w;
                        insert = 0;
                    }
                if (insert) {
                    a[index][0] = w;
                    a[index][1] = x;
                    a[index][2] = y;
                    a[index][3] = z;
                    index++;
                }
            }
            else { /* QUERY */
                
                total = 0;
                scanf("%d %d %d %d %d %d", &x, &y, &z, &x2, &y2, &z2);
                
                for (i = 1; i < index; i++)
                    if (a[i][1] >= x && a[i][2] >=y && a[i][3] >= z && a[i][1] <= x2 && a[i][2] <= y2 && a[i][3] <= z2)
                        total += a[i][0];
                printf("%lld\n", total);
            }
        }
    }
    return 0;
}
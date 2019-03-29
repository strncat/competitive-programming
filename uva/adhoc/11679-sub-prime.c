#include <stdio.h>

/* 11679 - Sub-prime
 Sample Input
 3 3
 1 1 1
 1 2 1
 2 3 2
 3 1 3
 3 3
 1 1 1
 1 2 1
 2 3 2
 3 1 4
 3 3
 1 1 1
 1 2 2
 2 3 2
 3 1 2
 0 0
 Sample Output
 S
 N
 S
 */

int main() {

    int i, banks, debentures, total[21], debtor, creditor, value, flag;
    
    while (scanf("%d %d", &banks, &debentures) == 2) {
        
        flag = 1; /* 1 means can pay back */
       
        if (banks == 0 && debentures == 0)
            break;
        
        /* reseves */
        for (i = 1; i <= banks; i++)
            scanf("%d", &total[i]);
        
        for (i = 1; i <= debentures; i++) {
            scanf("%d %d %d", &debtor, &creditor, &value);
            total[creditor] += value;
            total[debtor] -= value;
        }
        
        for (i = 1; i <= banks; i++) {
            if (total[i] < 0) {
                flag = 0;
                break;
            }
        }
        
        if (flag)
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}


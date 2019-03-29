#include <stdio.h>
#include <string.h>

/* 10141 - Request for Proposal
 Really Annoying problem!!!! seriously avoid 
 
 Sample Input
 6 4
 engine
 brakes
 tires
 ashtray
 vinyl roof
 trip computer
 Chevrolet
 20000.00 3
 engine
 tires
 brakes
 Cadillac
 70000.00 4
 ashtray
 vinyl roof
 trip computer
 engine
 Hyundai
 10000.00 3
 engine
 tires
 ashtray
 Lada
 6000.00 1
 tires
 1 1
 coffee
 Starbucks
 1.50 1
 coffee
 0 0
 
 Output for Sample Input
 RFP #1
 Cadillac
 
 RFP #2
 Starbucks
 */

int main() {

    int i, j, requirements, proposals, total, best_total, counter = 0;
    double price, best_price;
    char temp[100], proposal[100], best_proposal[100];
    
    while (1) {
        
        scanf("%d %d", &requirements, &proposals);
        getchar();
        
        if (requirements == 0 && proposals == 0)
            break;
        
        getchar();
        for (i = 0; i < requirements; i++)
            gets(temp);
        
        /* first proposal to set the max */
        gets(best_proposal);
        scanf("%lf %d", &best_price, &best_total);
        getchar();
        
        for (i = 0; i < best_total; i++)
            gets(temp);

        /* all other proposals */
        for (i = 1; i < proposals; i++) {
            
            gets(proposal);
            scanf("%lf %d", &price, &total);
            getchar();
            
            if (total > best_total || (total == best_total && price < best_price)) {
                strcpy(best_proposal, proposal);
                best_price = price;
                best_total = total;
            }
            for (j = 0; j < total; j++)
                gets(temp);
        }
        /* print */
        if (counter)
            printf("\n");
        printf("RFP #%d\n%s\n", ++counter, best_proposal);
    }
    return 0;
}
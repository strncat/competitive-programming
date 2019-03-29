#include <stdio.h>

/* UVa [10050 - Hartals] */

int main() {
    
    int i, j, party, sum, cases, n_parties, n_days, days[4000];
    
    scanf("%d", &cases);
    
    while (cases--) {

        sum = 0;
        scanf("%d", &n_days);
        
        /* Reset Days - day 1 is Sunday */
        for (i=1; i<=n_days; i++)
            days[i] = 0;
        
        scanf("%d", &n_parties);
        
        for (i=0; i<n_parties; i++) {
            scanf("%d", &party);
            
            for (j=party; j<=n_days; j+=party)
                days[j] = 1;
        }
        
        /* reset fridays and saturdays */
        for (i=6; i<=n_days; i+=7)
            days[i]=0;
        
        for (i=7; i<=n_days; i+=7)
            days[i]=0;
        
        for (i=1; i<=n_days; i++)
            sum += days[i];
        
        printf("%d\n", sum);
    }
    return 0;
}

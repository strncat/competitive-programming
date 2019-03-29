#include <stdio.h>

/* Sample Input
 661 - Blowing Fuses
 2 2 10
 5
 7
 1
 2
 3 6 10
 2
 5
 7
 2
 1
 2
 3
 1
 3
 0 0 0
 Sample Output
 Sequence 1
 Fuse was blown.
 
 Sequence 2
 Fuse was not blown.
 Maximal power consumption was 9 amperes.
*/

int main() {

    int n, i, power[21], capacity, m, counter = 1, state[21], consumption, device, blown, max;
    
    while (scanf("%d %d %d", &n, &m, &capacity) == 3) {
        
        if (m == 0 && n == 0 && capacity == 0)
            break;
        
        for (i = 1; i <= n; i++)
            state[i] = 0;
        
        /* scan devices */
        for (i = 1; i <= n; i++)
            scanf("%d", &power[i]);
        
        consumption = 0;
        blown = 0;
        max = 0;
        for (i = 1; i <= m; i++) {
            
            scanf("%d", &device);
            
            if (state[device] == 0) {
                consumption += power[device];
                state[device] = 1;
                if (consumption > capacity)
                    blown = 1;
                if (consumption > max)
                    max = consumption;
            }
            else {
                state[device] = 0;
                consumption -= power[device];
            }
        }
        
        printf("Sequence %d\n", counter++);
        if (blown)
            printf("Fuse was blown.\n\n");
        else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n", max);
        }
    }
    
    return 0;
}


#include <stdio.h>

/* 151 - Power Crisis
 Critical input:
 13
 14
 15
 16
 18
 19
 20
 97
 98
 99
 Critical output:
 1
 18
 10
 11
 17
 11
 15
 52
 113
 15
*/

/* for n=17, m=5: 1,6,11,16,5,12,2,9,17,10,4,15,14,3,8,13,7 */

int last_city(int N, int m) {
    
    int i, power[100], counter, turned_off;
    
    /* all cities lights on */
    for (i=1; i<=N; i++) {
        power[i] = 1;
    }

    /* first to turn off is 1 */
    power[1] = 0;
    turned_off = 1;
    i = 2;
    counter = 0;
    
    while (1) {
        
        /* if it's not turned off, count it */
        if (power[i])
            counter++;
        
        /* if it's the mth city, turn it off */
        if (counter == m && power[i]) {
            power[i] = 0;
            counter = 0;
            turned_off++;
            
            if (turned_off == N)
                break;
        }
        
        i++;
        if (i == N+1)
            i = 1;
    }
    return i;
}

int main() {
    
	int i, N;
    
    while (scanf("%d", &N) == 1 && N) {
        i = 0;
        while (1) {
           if (last_city(N, ++i) == 13) {
               printf("%d\n", i);
               break;
           }
        }
    }
	return 0;
}



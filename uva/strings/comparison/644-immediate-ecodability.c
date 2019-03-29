#include <stdio.h>
#include <string.h>

/* 644 - Immediate Decodability

 Sample Input
01
10
0010
0000
9
01
10
010
0000
9
 
Sample Output
Set 1 is immediately decodable
Set 2 is not immediately decodable
*/

int main() {

    char set[10][11], *p;
    int i, j, n = 0, fail = 0, counter = 1;
    
    while (scanf("%s", set[n]) != EOF) { /* Gotta be explicit about EOF otherwise you'll get TLE */
        
        if (set[n][0] == '9') {
            
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++) {
                    if (i != j) {
                        p = strstr(set[i], set[j]);
                        if (p != NULL && strcmp(p, set[i]) == 0)
                            fail = 1;
                    }
                }
            if (fail)
                printf("Set %d is not immediately decodable\n", counter);
            else
                printf("Set %d is immediately decodable\n", counter);
            
            /* reset */
            n = 0;
            fail = 0;
            counter++;
        }
        else
            n++;
    }
    return 0;
}


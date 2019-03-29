#include <stdio.h>
#include <string.h>

/* 11661 - Burger Time?
 Sample Input
 2
 RD
 5
 ..Z..
 10
 .R......D.
 10
 .R..Z...D.
 10
 ...D..R...
 25
 ..D...R.RR...DD...D.R...R
 0
 Sample Output
 1
 0
 7
 0
 3
 2
 */

int main() {

    int i, length, min_distance, distance, restuarant, drugstore;
    char highway[2000001];
    
    while (scanf("%d", &length) == 1 && length) {
        
        scanf("%s", highway);
        length = (int) strlen(highway);
        
        min_distance = 2000000; /* max L = 2,000,000 */
        drugstore = -1;
        restuarant = -1;
        
        for (i = 0; i < length; i++) {
            if (highway[i] == 'R')
                drugstore = i;
            
            else if (highway[i] == 'D')
                restuarant = i;
            
            else if (highway[i] == 'Z')
                min_distance = 0;
            
            if (drugstore != -1 && restuarant != -1) {
                distance = (drugstore - restuarant) > 0 ? drugstore - restuarant : restuarant - drugstore;
                if (min_distance > distance)
                    min_distance = distance;
            }
        }
        printf("%d\n", min_distance);
    }
    return 0;
}


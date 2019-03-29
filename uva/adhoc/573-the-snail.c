#include <stdio.h>
#include <string.h>

/* 573 - The Snail
 Sample Input
 6 3 1 10
 10 2 1 50
 50 5 3 14
 50 6 4 1
 50 6 3 1
 1 1 1 1
 0 0 0 0
 
 Sample Output
 success on day 3
 failure on day 4
 failure on day 7
 failure on day 68
 success on day 20
 failure on day 2
 */

int main() {

    int wall, day_distance, slide, day, climbed, fatigue;
    
    while (scanf("%d %d %d %d", &wall, &day_distance, &slide, &fatigue) == 4 && wall) {
        
        fatigue = day_distance * fatigue;
        day_distance *= 100;
        slide *= 100;
        wall *= 100;
        day = 0;
        climbed =0;
        
        while (1) {
            day++;
            
            climbed += day_distance;
            
            day_distance = (day_distance - fatigue < 0) ? 0 : day_distance - fatigue; /* new distance, substract fatigue */
            
            if (climbed > wall) break;
            
            climbed -= slide;
            
            if (climbed < 0) break;
            
        }
        
        if (climbed > wall)
            printf("success on day %d\n", day);
        else
            printf("failure on day %d\n", day);
    }
    
    return 0;
}
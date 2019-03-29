#include <stdio.h>
#include <string.h>

/* 10409 - Die Game
 Sample Input
 1
 north
 3
 north
 east
 south
 0
 Output
 5
 1
*/

int main() {

    int i, n, top, bottom, west, east, south, north, temp;
    
    char direction[10];
    
    while (scanf("%d", &n) && n) {
        
        /* initial state */
        south = 5;
        west = 3;
        top = 1;
        east = 4;
        north = 2;
        bottom = 6;
        
        for (i = 0; i < n; i++) {
            scanf("%s", direction);
            
            if (strcmp(direction, "north") == 0) {
                temp = top;
                top = south;
                south = bottom;
                bottom = north;
                north = temp;
            }
            else if (strcmp(direction, "east") == 0) {
                temp = top;
                top = west;
                west = bottom;
                bottom = east;
                east = temp;
            }
            else if (strcmp(direction, "west") == 0) {
                temp = top;
                top = east;
                east = bottom;
                bottom = west;
                west = temp;
            }
            else {
                temp = top;
                top = north;
                north = bottom;
                bottom = south;
                south = temp;
            }
        }
        
        printf("%d\n", top);
    }
    return 0;
}


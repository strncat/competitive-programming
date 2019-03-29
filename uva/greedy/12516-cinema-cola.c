#include <stdio.h>
#include <string.h>

/* 12516 - Cinema-cola
 Sample Input
 3 5
 3
 A3 -
 B1 -
 B4 -
 4
 A1
 A2
 B2
 B3
 3 5
 3
 A3 -
 B1 +
 B4 -
 4
 A1
 A2
 B2
 B3
 3 5
 1
 A2 +
 2
 A4
 A3
 0 0
 Sample Output
 YES
 NO
 YES
 */

#define N 30
#define M 120

void print(int holder[N][M], int R, int C) { /* for debugging */
    int i, j;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++)
            printf("%d\t", holder[i][j]);
        printf("\n");
    }
}

int main() {
    
    int i, j, holders[N][M], seats[N][M], R, C, fail, col, row, people, friends;
    char c_row, place;
    
    while (scanf("%d %d\n", &R, &C) == 2) {
        
        if (R == 0 && C == 0)
            break;
        
        C++; /* 1 more since seat 1 can put the cup on the left (i = 0) and seat c can put the cup on the right (i = c) */
        
        memset(holders, 0, sizeof(holders));
        memset(seats, 0, sizeof(seats));
        
        scanf("%d\n", &people);
        
        for (i = 0; i < people; i++) {
            scanf("%c%d %c\n", &c_row, &col, &place);
            
            row = c_row - 'A';
            
            if (place == '-') /* left */
                holders[row][col - 1] = 1;
            
            else /* right */
                holders[row][col] = 1;
        }
        
        scanf("%d\n", &friends);
        
        fail = 0;
        for (i = 0; i < friends; i++) {
            
            scanf("%c%d\n", &c_row, &col);
            row = c_row - 'A';
            seats[row][col] = 1; /* pre-determine where friends will sit */
        }
        
        for (i = 0; i < R; i++)
            for (j = 1; j <= C; j++) {
                if (seats[i][j] == 1) { /* put the drink */
                    
                    if (holders[i][j - 1] == 0) /* try putting the drink in the left cup holder first */
                        holders[i][j - 1] = 1;
                    
                    else if (holders[i][j] == 0) /* try right if left is taken */
                        holders[i][j] = 1;
                    
                    else /* FAIL */ {
                        fail = 1;
                        break;
                    }
                }
            }
        if (fail)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
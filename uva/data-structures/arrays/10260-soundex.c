#include <stdio.h>
#include <string.h>

/* UVa [10260 - Soundex]
 1 represents B, F, P, or V
 2 represents C, G, J, K, Q, S, X,  or Z
 3 represents D or T
 4 represents L
 5 represents M or N
 6 represents R
 Sample Input
 KHAWN
 PFISTER
 BOBBY
 Output for Sample Input
 25
 1236
 11
 */

int sound(char x) {
    if (x == 'B' || x == 'F' || x == 'P' || x == 'V')
        return 1;
    else if (x == 'C' || x == 'G' || x == 'J' || x == 'K' || x == 'Q' || x == 'S' || x == 'X' || x == 'Z')
        return 2;
    else if (x == 'D' || x == 'T')
        return 3;
    else if (x == 'L')
        return 4;
    else if (x == 'M' || x == 'N')
        return 5;
    else if (x == 'R')
        return 6;
    return 0;
}

int main() {
    
    char str[20];
    int i, length, prev, current;

    while (scanf("%s", str) == 1) {
        
        length = (int) strlen(str);
        
        prev = -1;
        for (i=0; i<length; i++) {
            current = sound(str[i]);
        
            if (prev != current && current)
                printf("%d", current);
            
            prev = current;
        }
        printf("\n");
    }
    return 0;
}

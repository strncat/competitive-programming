#include <stdio.h>
#include <string.h>
#include <math.h>

/* 11716 - Digital Fortress
Sample Input
3
WECGEWHYAAIORTNU
DAVINCICODE
DTFRIAOEGLRSI TS
 
Output for Sample Input
WEAREWATCHINGYOU
INVALID
DIGITAL FORTRESS
*/

int main() {

    int test_cases, length, i, j;
    char line [10010];
    double squareroot;
    
    scanf("%d\n", &test_cases);
    
    while (test_cases--) {
    
        fgets(line, 10010, stdin);
        length = (int) strlen(line);
        
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }
        
        squareroot = sqrt(length);
        
        if (squareroot != (int) squareroot)
            printf("INVALID\n");
        else {
            
            for (i = 0; i < squareroot; i++)
                for (j = i; j < length; j+=squareroot)
                    printf("%c", line[j]);
            printf("\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

/* 11586 - Train Tracks
 Sample input
4
MF MF
FM FF MF MM
MM FF
MF MF MF MF FF
 Sample output
 LOOP
 LOOP
 LOOP
 NO LOOP
 */

int main() {
    
    int test_cases, b[3], offset;
    char c[3], line[1000], *data;
    
    scanf("%d\n", &test_cases);
    
    while (test_cases--) {
        
        b[0] = 0; b[1] = 0; b[2] = 0;
        
        fgets(line, 1000, stdin);
        
        data = line;
        while (sscanf(data, "%s%n", c, &offset) == 1) {
            
            data += offset;
            
            if (c[0] == '\n')
                break;

            if (c[0] == 'F' && c[1] == 'F')
                b[0]++;
            else if (c[0] == 'M' && c[1] == 'M')
                b[1]++;
            else
                b[2]++;
        }
        if (b[0] == b[1] && (b[2] % 2 == 0))
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }
    return 0;
}
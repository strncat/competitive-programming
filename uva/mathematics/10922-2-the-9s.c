#include <stdio.h>
#include <string.h>

/* 10922 - 2 the 9s
Sample input:
999999999999999999999
9
9999999999999999999999999999998
0
Sample output
999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9.
*/

int main() {
    
    int i, length, sum, depth, new_sum;
    char line[2000];
    
    while (scanf("%s", line) == 1) {
        
        length = (int) strlen(line);
        
        if (line[0] == '0' && length == 1)
            break;
        
        sum = 0;
        for (i = 0; i < length; i++)
            sum += line[i] - '0';
        
        depth = 0;
        while (sum % 9 == 0 && sum > 9) {
            
            depth++;
            new_sum = 0;
            
            while (sum > 0) {
                new_sum += (sum % 10);
                sum /= 10;
            }
            sum = new_sum;
        }
        
        if (sum % 9 == 0)
            depth++;
        
        if (depth)
            printf("%s is a multiple of 9 and has 9-degree %d.\n", line, depth);
        else
            printf("%s is not a multiple of 9.\n", line);
    }
    return 0;
}
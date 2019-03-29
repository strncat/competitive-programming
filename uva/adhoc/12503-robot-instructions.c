#include <stdio.h>
#include <string.h>

/* 12503 - Robot Instructions
 Sample Input
 2
 3
 LEFT
 RIGHT
 SAME AS 2
 5
 LEFT
 SAME AS 1
 SAME AS 2
 SAME AS 1
 SAME AS 4
 Sample Output
 1
 -5
 */

int main() {

    int test_cases, i, n, number, instructions[101], robot;
    char instruction[10];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        scanf("%d", &n);
        
        robot = 0;
        for (i = 1; i <= n; i++) {
            scanf("%s", instruction);
            
            if (strcmp(instruction, "LEFT") == 0) {
                instructions[i] = -1;
                robot += -1;
            }
            else if (strcmp(instruction, "RIGHT") == 0) {
                instructions[i] = 1;
                robot += 1;
            }
            else {
                scanf("%s %d", instruction, &number);
                robot += instructions[number];
                instructions[i] = instructions[number];
            }
        }
        printf("%d\n", robot);
    }
    
    return 0;
}


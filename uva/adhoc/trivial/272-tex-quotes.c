#include <stdio.h>
#include <string.h>

int main() {
    
    int ch=0;
    int flag=0;
        
    while ( (ch=getchar()) != EOF ) { /* for EOF use CTRL-D */
                
        if (ch != '\n') {
        
            if (ch == '"') {
                if (flag == 0) {
                    printf("``");
                    flag = 1;
                }
                else if (flag == 1) {
                    printf("''");
                    flag = 0;
                }
            }
            else
             
            putchar(ch);
        }
        else {
            printf("\n");
        }

    }
    return 0;
}
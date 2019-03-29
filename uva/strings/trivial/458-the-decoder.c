#include <stdio.h>
#include <string.h>

int main() {
    
    int ch=0;
    int flag=0;
    while ( (ch=getchar()) != EOF ) { /* for EOF use CTRL-D */
        if (ch != '\n') {
            putchar(ch-7);
        }
        else {
            printf("\n");
        }
    }
    return 0;
}
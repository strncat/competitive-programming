#include <stdio.h>
#include <string.h>

/* 11956 - Brainfuck
 >	Increment the pointer (to point to the next cell to the right).
 <	Decrement the pointer (to point to the next cell to the left).
 +	Increment (increase by one) the byte at the pointer.
 –	Decrement (decrease by one) the byte at the pointer.
 .	Output the value of the byte at the pointer.
*/

int main() {

    int test_cases, i, j, k, index = 0, length;
    char line[100005];
    unsigned char LED[100] = {0};
    
    scanf("%d", &test_cases);
    getchar();
    
    for (i = 1; i <= test_cases; i++) {
        
        memset(LED, 0, sizeof(LED));
        index = 0;
        
        gets(line);
        length = (int) strlen(line);
        
        for (k = 0; k < length; k++) {
            if (line[k] == '+')
                LED[index]++;
            else if (line[k] == '-')
                LED[index]--;
            else if (line[k] == '<') {
                if (index == 0)
                    index = 99;
                else
                    index--;
            }
            else if (line[k] == '>') {
                if (index == 99)
                    index = 0;
                else
                    index++;
            }
        }
        printf("Case %d:", i);
        for (j = 0; j < 100; j++)
            printf(" %02X", LED[j]);
        printf("\n");
    }
    return 0;
}
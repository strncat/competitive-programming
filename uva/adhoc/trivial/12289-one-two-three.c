#include <stdio.h>
#include <string.h>

/*
 12289 - One-Two-Three
 Sample Input
 
 3
 owe
 too
 theee
 Sample Output
 
 1
 2
 3
*/

int main ()
{
    int cases, sum;
    char input[10];
    
    scanf ("%d", &cases);
    
    while (cases--) {
        
        sum = 0;
        scanf("%s", input);
        
        if ( strlen(input) == 5 )
            printf ("3\n");
        
        else {
            if (input[0] == 'o')
                sum++;
            if (input[1] == 'n')
                sum++;
            if (input[2] == 'e')
                sum++;
            /* at most one character wrong, 2 is enough */
            if (sum >= 2)
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}
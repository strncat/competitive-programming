#include <stdio.h>
#include <string.h>

/* 
 123456789012345678901234567890 *3 =
 370370367037037036703703703670
*/

#define N 102 /* '\0' && carry */

int main() {
    
    int i=0, j=0, k=0, n=0, sum=0, carry=0, max=0;
    char input[N];
    int digits[N][N];
    int result[N];

    for (i=0; i<N; i++) {
        result[i] = 0;
        for (j=0; j<N; j++) 
            digits[i][j]=0;
    }
    
    while (fgets(input, sizeof(input), stdin) != NULL) { /* NULL on EOF */
        
        if (strcmp(input, "0\n") == 0)
            break;
        
        for (j=(int)strlen(input)-2, k=0; j >= 0 ; j--, k++)
            digits[n][N-1-k] = input[j]-'0';
        
        if (k >= max)
            max = k;
        
        n++;
    }

    /* for (i=0; i<N; i++)
        printf("%d", digits[0][i]);
    printf("\n"); */
        
    for (i=N-1; i>=0; i--) {
        
        sum=0;
        
        for (j=0; j<n; j++) {
            sum += digits[j][i];
        }
        
        sum += carry;
        carry=0;

        if (sum > 9) {
            result[i] = sum%10;
            carry = sum/10;
        }
        else
            result[i] = sum;
                
    }
    
    /* two digits extra max */
    
    if (result[N-max-2] != 0)
        printf("%d", result[N-max-2]);
    
    if (result[N-max-1] != 0)
        printf("%d", result[N-max-1]);
    
    /* rest */
    
    for (j=N-max; j<N; j++)
        printf("%d", result[j]);
    printf("\n");
    
    return 0;
}


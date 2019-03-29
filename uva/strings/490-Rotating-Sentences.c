#include <stdio.h>
#include <string.h>
/* 490 - Rotating Sentences 
 Rene Decartes once said,
 "I think, therefore I am."
 "R
 Ie
  n
 te
 h
 iD
 ne
 kc
 ,a
  r
 tt
 he
 es
 r
 eo
 fn
 oc
 re
 e
  s
 Ia
  i
 ad
 m,
 .
 "
 */

#define N 105

int main() {
    
    char line[N], matrix[N][N];
    int i, j, n, length, max;
    
    n = 0;
    
    /* Initialize Matrix */
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            matrix[i][j] = '\0';
    
    while (fgets(line, sizeof(line), stdin) != NULL) {
        
        length = (int)strlen(line);
                
        for (i=0; i<length; i++)
            if (line[i] != '\n') 
                matrix[i][n] = line[i]; /* store line vertically */
                
        if (length > max)
            max = length;
        
        n++;
    }
            
    for (i=0; i<max-1; i++) {
        for (j=n-1; j>=0; j--) {
            if (matrix[i][j] != '\0')
                printf("%c", matrix[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}

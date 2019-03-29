#include <stdio.h>
#include <string.h>

int main() {
    
    int m=0, n=0; /* 0 < n,m <= 100 */
    int i=0, j=0;
    int field=1; /* arbitrary number of fields */
    
    /* Instead of coding edge cases, add 2 to each dimension */ 

    while(1) {
        
        scanf("%d %d", &m, &n); 

        if ((n == 0) && (m == 0))
            break;
        
        char input[m+2][n+2];
        int output[m+2][n+2];
        
        /* Initialize */
        for (i=0; i<m+2; i++)
            for (j=0; j<n+2; j++)
                output[i][j] = 0;
        
        /* input */
        char line[n]; /* to hold a row of input */
        
        for (i = 0; i < m; i++) { /* read m rows */
            
            scanf("%s\n",line);
            
            for (j = 1; j < n+1; j++) { /* fill the inner columns (1-n) */
                input[i+1][j] = line[j-1]; /* only starting from row 1 */
            }
        }
        
        /* calculate */
        for (i=1; i<m+1; i++) {
            for (j=1; j<n+1; j++)
                if (input[i][j] == '*') {
                    
                    output[i][j-1]++;
                    output[i][j+1]++;
                    
                    output[i-1][j-1]++;
                    output[i-1][j]++;
                    output[i-1][j+1]++;
                    
                    output[i+1][j-1]++;
                    output[i+1][j]++;
                    output[i+1][j+1]++;
                }
        }
        
        /* print!! */
        
        if (field > 1)
            printf("\n");
        
        printf("Field #%d:\n", field++);
        for (i=1; i<m+1; i++) {
            for (j=1; j<n+1; j++) {
                if (input[i][j] == '*')
                    printf("*");
                else
                    printf("%d", output[i][j]);
            }
            printf("\n");
        }
        
    }
    
    return 0;
}

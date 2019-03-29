#include <stdio.h>

/* 541 - Error Correction */

int main() {
    
	int N, a[100][100], i, j, row[100], col[100], total_rows, total_cols, odd_row, odd_col;
    
	while(scanf("%d", &N) == 1 && N) {
        
        total_rows = 0;
        total_cols = 0;
        
        /* Sums */
        for (i=0; i<N; i++)
            for (j=0; j<N; j++) {
                row[i] = 0;
                col[j] = 0;
            }
		
        /* Read Matrix & Sum */
		for (i=0; i<N; i++) {
            for (j=0; j<N; j++) {
                scanf("%d", &a[i][j]);
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        }
        
        /* Check row sums and column sums */
        for (i=0; i<N; i++) {
            if (row[i]%2) {
                odd_row = i;
                total_rows++;
            }
            if (col[i]%2) {
                odd_col = i;
                total_cols++;
            }
        }
        /* if more than one odd row or one odd column, can't be fixed */
        if (total_rows > 1 || total_cols > 1)
            printf("Corrupt\n");
        
        else if (total_rows+total_cols == 0)
            printf("OK\n");
        
        else if (total_cols+total_rows > 0)
            printf("Change bit (%d,%d)\n", odd_row+1, odd_col+1); /* because counting starts at zero */
                
	}
	return 0;
}
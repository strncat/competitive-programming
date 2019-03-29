#include <stdio.h>

/* 11875 - Brick Game */

void insertion_sort(int *a, int size) {
    
    int i, j, temp;
    
    for (i=1; i<size; i++)
        for (j=i; j>0; j--)
            if (a[j] < a[j-1]) {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
}

int main() {
    
	int cases, counter, N, age[11], i;
    
    scanf("%d", &cases);
    
	for (counter=1; counter<=cases; counter++) {
        
        scanf("%d", &N);
        
        /* Read Ages */
        for (i=0; i<N; i++)
            scanf("%d", &age[i]);
		
        insertion_sort(age, N);
        
        printf("Case %d: %d\n", counter, age[N/2]);
	}
	return 0;
}
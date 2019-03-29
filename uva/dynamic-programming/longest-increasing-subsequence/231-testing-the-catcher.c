#include <stdio.h>

/*
231 - Testing the CATCHER
Sample Input
389
207
155
300
299
170
158
65
-1
23
34
21
-1
-1
Sample Output
Test #1:
maximum possible interceptions: 6

Test #2:
maximum possible interceptions: 2
*/

#define N 100000 /* not sure about this */

int LS(int *a, int n) { /* O(n^2) */
    
    int i, j, maximum = 1, c[N];

    for (i = 0; i < n; i++)
        c[i] = 1;
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) { /* {max LS[j] where j < i && a[i] <= a[j]} */
            if (a[i] <= a[j] && c[i] < c[j] + 1)
                c[i] = c[j] + 1;
        }
        if (c[i] > maximum)
            maximum = c[i];
    }
    return maximum;
}

int main() {
    
    int i, value, a[N], counter = 1;
    
    while (1) {

        scanf("%d", &value);
        
        if (value == -1)
            break;
        
        i = 0;
        a[i++] = value;
        
        while (scanf("%d", &a[i]) && a[i] != -1)
            i++;
        
        if (counter > 1)
            printf("\n");
        
        printf("Test #%d:\n  maximum possible interceptions: %d\n", counter++, LS(a, i));
    }
    
    return 0;
}
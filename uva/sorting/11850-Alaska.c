#include <stdio.h>

/* UVa [11850 - Alaska]
 
 Sample Input
 2
 0
 900
 8
 1400
 1200
 1000
 800
 600
 400
 200
 0
 0
 Sample Output
 IMPOSSIBLE
 POSSIBLE
*/

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
    
    int i, n, charge, flag;
    int d[1423];
    
    while (scanf("%d", &n) == 1 && n) {

        for (i=0; i<n; i++)
            scanf("%d", &d[i]);
        
        insertion_sort(d, n);
        
        /* there is a charging station at location 0 */
        charge=200;
        flag=1;
        
        for (i=1; i<n; i++) {
            if ((d[i]-d[i-1]) > 200) {
                flag = 0;
                break;
            }
        }
        
        /* she has to make it back to the station with the same fuel */
        if ( 2*(1422-d[n-1]) > 200)
            flag = 0;
        
        if (flag)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
        
    }
    return 0;
}

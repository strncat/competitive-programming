#include <stdio.h>

/* 11364 - Parking
 Sample Input
 2
 4
 24 13 89 37
 6
 7 30 41 14 39 42
 
 Sample Output
 152
 70
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
    
    int i=0, cases, total, sum;
    int shops[20];
    
    scanf("%d", &cases);
    
    while (cases--) {
        
        scanf("%d", &total);
        
        for (i=0; i<total; i++)
            scanf("%d", &shops[i]);
        
        insertion_sort(shops, total);

        /* sum of total distance mike is gonna take */
        sum = 0;
        for (i=1; i<total; i++)
            sum += shops[i]-shops[i-1];
        
        printf("%d\n", sum*2);
    }
    return 0;
}
#include <stdio.h>
#include <math.h>

/* 10041 - Vito's Family
 Sample Input
 2
 2 2 4
 3 2 4 6
 
 Sample Output
 2
 4
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
    
    int i=0, cases, median=0, total, sum;
    int relatives[500];
    
    scanf("%d", &cases);
    
    while (cases--) {
        
        scanf("%d", &total);
      
        for (i=0; i<total; i++)
            scanf("%d", &relatives[i]);
            
        insertion_sort(relatives, total);
        
        /* location of Vito's house is the median */
        if (total % 2 == 0)
            median = (relatives[total/2]+relatives[total/2-1])/2;
        else
            median = relatives[total/2];
        
        /* sum of total distance from Vito to everyone else */
        sum = 0;
        for (i=0; i<total; i++)
            sum += abs(relatives[i]-median);
        
        printf("%d\n", sum);
    }
    return 0;
}
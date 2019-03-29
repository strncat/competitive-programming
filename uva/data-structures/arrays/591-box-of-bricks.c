#include <stdio.h>

/* double \n! */

int main()
{
    int i, n, sum, h[50], avg, count, set=0;
    
    while(scanf("%d", &n)==1) {
        
        if(n == 0)
            break;
        
        sum = 0;
        count = 0;
        set++;
        
        for (i=0; i<n; i++) {
            scanf("%d", &h[i]);
            sum += h[i];
        }
        
        avg = sum/n;
        
        for (i=0; i<n; i++)
            if (h[i] > avg)
            count += h[i]-avg;
        
        
        printf("Set #%d\n", set);
        printf("The minimum number of moves is %d.\n\n", count);
        
    }
    return 0;
}

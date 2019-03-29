#include <stdio.h>
#include <string.h>

/* UVa - 10424 - Love Calculator
 
 saima    India      USA
 shanto   Pakistan   USSR
 71.43%   100        100 */

#define N 27

int main() {
    
    int i=0, n=0, sum=0, asum=0, bsum=0;
    double ratio=0;
    char a[N], b[N];
    
    while (fgets(a, sizeof(a), stdin) != NULL) { /* NULL on EOF */
        
        
        fgets(b, sizeof(b), stdin);
        
        sum=0;
        
        n = (int) strlen(a);
        for (i=0; i<n; i++) 
            if (a[i] >= 'A' && a[i] <= 'Z') 
                sum += a[i] - 'A' + 1;
            else if (a[i] >= 'a' && a[i] <= 'z') 
                sum += a[i] - 'a' + 1;

        if(sum%9==0)
            asum=9;
        else asum = sum%9;
                
        sum = 0;
        n = (int) strlen(b);
        for (i=0; i<n; i++)
            if (b[i] >= 'A' && b[i] <= 'Z')
                sum += b[i] - 64;
            else if (b[i] >= 'a' && b[i] <= 'z')
                sum += b[i] - 96;
        
        if(sum%9==0)
            bsum=9;
        else bsum = sum%9;
        
        if (asum >= bsum)
            ratio = (double)bsum/(double)asum;
        else
            ratio = (double)asum/(double)bsum;
        
        printf("%.2f %%\n", ratio*100);
    }
    return 0;
}


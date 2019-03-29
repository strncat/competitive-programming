#include <stdio.h>
#include <string.h>

int main() {
    
    int test_cases=0, i=0, j=0, n=0, sum=0, x=0, y=0, z=0;
    
    scanf("%d",&test_cases);
    
    for (i=0; i<test_cases; i++) {
    
        n=0;
        sum=0;
        scanf("%d",&n);
        
        for (j=0; j<n; j++) {
            
            scanf("%d %d %d",&x, &y, &z);
            sum += x * z;
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
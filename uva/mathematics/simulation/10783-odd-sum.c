#include <stdio.h>

int main() {
    
    int test_cases=0; /* T[1,100] a,b[0,100]*/
    int i=1, sum=0;
    
    int a=0, b=0, d=2, n=0;
    
    /* 
    b=a+(n-1)d => (n-1) = (1/d)(b - a)
    sn=n/2[2a + (n-1)d] 
    b=last term
    a= first term
    n=number of terms
    d= difference between terms
    */
    
    scanf("%d", &test_cases);

    while(test_cases > 0)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        
        if (a%2 == 0)
            a++;
        if (b%2 == 0)
            b--;
        
        n = ((b - a)/d) + 1;
        
        sum = (n * (2*a + (n-1)*d))/2;

        printf("Case %d: %d\n", i, sum);
        
        test_cases--;
        i++;
    }
    return 0;
}

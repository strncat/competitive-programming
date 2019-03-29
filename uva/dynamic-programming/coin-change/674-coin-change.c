#include <stdio.h>

/* 674 - Coin Change (also check 357 - Let Me Count The Ways)
 
 http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615

 check this http://nemo.la/?p=555
 
 a[7489] = 2,146,113,925
  
*/

#define N 8000
long long int a[N];

int main() {
    
    int n, c[5] = {50, 25, 10, 5, 1};
    
    a[0] = 1;
    long long int i, j;
    for (i=0; i<5; i++)
        for (j=c[i]; j<N; j++)
            a[j] += a[j - c[i]];

    while(scanf("%d",&n) == 1)
        printf("%lld\n", a[n]);
        
    return 0;
}

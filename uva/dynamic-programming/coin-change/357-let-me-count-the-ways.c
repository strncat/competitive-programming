#include <stdio.h>

/* 357 - Let Me Count The Ways
 
 http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=293

 Check http://nemo.la/?p=555
 
 a[30000] = 543,427,145,501
 
 This problem drove me insane, pay attention to every single line
 having long long int a[N] inside main was giving me wrong answers!! 
  
*/

#define N 30010
long long int a[N];

int main() {
    
    int n, c[5] = {50, 25, 10, 5, 1};
    
    a[0] = 1;
    long long int i,j;
    for (i=0; i<5; i++)
        for (j=c[i]; j<N; j++)
            a[j] += a[j - c[i]];

    while(scanf("%d",&n) == 1)
        if(a[n]>1)
            printf("There are %lld ways to produce %d cents change.\n", a[n], n);
        else
            printf("There is only %lld way to produce %d cents change.\n", a[n], n);
        
    return 0;
}

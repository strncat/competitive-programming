#include <stdio.h>
#include <limits.h>

/* 147 - Dollars
 
 For explanation please refer to http://nemo.la/?p=555
 
Sample input
0.20
2.00
0.00
Sample output
0.20                4
2.00              293
*/

#define N 11
int d[N] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
#define M 40000
long long int c[M] = {0};

void build_table() {
    
    int i, j;
    
    c[0] = 1;
    for (i = 0; i < N; i++)
        for (j = d[i]; j <= M; j++)
            c[j] += c[j - d[i]]; /* we "overwrite" the previous row with the new one */
}

int main() {
    
    long a, b, note;
    
    build_table();
    
    while(1) {
        
        scanf("%ld.%ld", &a, &b);
        
        if (a == 0 && b == 0)
            break;
        
        note = a * 100 + b;
        
        printf("%3ld.%.2ld%17lld\n", a, b, c[note]);
    }
    return 0;
}
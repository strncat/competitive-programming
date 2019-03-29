#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 11340 - Newspaper
SAMPLE INPUT:
1
7
a 3
W 10
A 100
, 10
k 7
. 3
I 13
7
ACM International Collegiate Programming Contest (abbreviated
as ACM-ICPC or just ICPC) is an annual multi-tiered competition
among the universities of the world. The ICPC challenges students
to set ever higher standards of excellence for themselves
through competition that rewards team work, problem analysis,
and rapid software development.
From Wikipedia.

 SAMPLE OUTPUT:
3.74$
*/

int main() {
    
    int test_cases, K, i, j, ascii[300], n, size;
    unsigned char c, line[10010];
    long long int total;
    
    scanf("%d\n", &test_cases);
    
    while(test_cases--) {
        
        for (i = 0; i < 256; i++)
            ascii[i] = 0;
        
        scanf("%d\n", &K);
        
        for (i = 0; i < K; i++) { /* paid characters */
            scanf("%c", &c);
            scanf("%d\n", &ascii[c]);
        }
        
        scanf("%d\n", &n);
        
        total = 0;
        for(i = 0; i < n; i++) {
            
            gets(line);
            size = (int) strlen(line);
            
            for (j = 0; j < size; j++)
                total += ascii[line[j]];
        }
        printf("%.2f$\n", total/100.0);
    }
    return 0;
}
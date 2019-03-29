#include <stdio.h>

/* 11461 - Square Numbers
 input
 1 4
 1 10
 0 0 
 output
 2
 3
 */

#define N 100000

int squares[N] = {0};

void square() {
    
    int i;
    
    for (i = 0; i * i <= N; i++)
        squares[i * i] = 1;
    
}

int main() {
    
    int a, b, i, count;
    
    square();
    
    while (scanf("%d %d", &a, &b) == 2) {
        
        if (a == 0 && b == 0)
            break;
        
        count = 0;
        for (i = a; i <= b; i++)
            count += squares[i];
        
        printf("%d\n", count);
    }
    return 0;
}
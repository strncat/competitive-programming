#include <stdio.h>

/* 11417 - GCD */

int GCD(int a, int b) {
    
    while (b != 0)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}

int main() {
    
    int N, i, j, G=0;
    
    while(scanf("%d", &N) && N != 0) {
        
        G=0;
        for(i=1;i<N;i++)
            for(j=i+1;j<=N;j++)
                G+=GCD(i, j);
        
        printf("%d\n", G);
            
    }
    return 0;
}
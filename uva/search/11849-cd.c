#include <stdio.h>

/* 11849 - CD */

/*
 input:
 3 3
 1
 2
 3
 1
 2
 4
 0 0
 
 output:
 2
 */

int main() {

    int i, j, N, M, jill[1000000], jack[1000000], total, prev;
    
    while (scanf("%d %d", &N, &M) == 2) {
        
        if (N == 0 && M == 0)
            break;
    
        for (i = 0; i < N; i++)
            scanf("%d", &jack[i]);
        
        for (i = 0; i < M; i++)
            scanf("%d", &jill[i]);
        
        i = 0, j = 0, total = 0;
        
        while (j < M && i < N) {
            
            if (jack[i] < jill[j]) {
                i++;
            }
            else if (jack[i] > jill[j]) {
                j++;
            }
            else if (jack[i] == jill[j] && jack[i] != prev) {
                prev = jack[i];
                total++;
                i++;
                j++;
            }
        }
        printf("%d\n", total);
    }

    return 0;
}


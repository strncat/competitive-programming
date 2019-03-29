#include <stdio.h>

int main() {

    int cases, x[4], y[4], z[4];

    scanf("%d", &cases);  
    
    while (cases--) {
        for (int i = 0; i < 4; i++) {
            scanf("%d %d %d", &x[i], &y[i], &z[i]); 
        }
        if ((x[0] == x[1] && x[1] == x[2] && x[2] == x[3])
           || ((y[0] == y[1] && y[1] == y[2] && y[2] == y[3])) 
           || ((z[0] == z[1] && z[1] == z[2] && z[2] == z[3]))) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
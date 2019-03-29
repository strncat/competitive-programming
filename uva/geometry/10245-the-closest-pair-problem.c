#include <stdio.h>
#include <math.h>

/* 10245 - The Closest Pair Problem
Sample Input
3
0 0
10000 10000
20000 20000
5
0 2
6 67
43 71
39 107
189 140
2
0 0
7071.0678118654752440084436210485 7071.0678118654752440084436210485
0
Sample Output
INFINITY
36.2215
10000.0000
*/

#define MAX 500

int main() {
    
    int i, j, N;
    double min_distance, distance, x[10000], y[10000];
    
    while (scanf("%d", &N) == 1 && N) {
        
        min_distance = 100000000;
        
        for (i = 0; i < N; i++)
            scanf("%lf %lf", &x[i], &y[i]);
        
        for (i = 0; i < N; i++)
            for (j = i + 1; j < N; j++) {
                distance = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
                if (min_distance > distance)
                    min_distance = distance;
            }
        
        min_distance = sqrt(min_distance);
        
        if (min_distance < 10000)
            printf("%.4lf\n", min_distance);
        else
            printf("INFINITY\n");
    }
    return 0;
}
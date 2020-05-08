#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

/* 624 - CD
Sample Input
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
32 5 14 1 11 5 9
15 8 13 10 20 19 4 19 7 20
29 6 20 15 5 7 20 19
60 8 10 8 3 11 3 19 7 8
Sample Output
1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45
81 7 19 20 12 18 14 14 114 1 11 5 sum:31
10 4 sum:14
20 7 sum:27
10 8 3 11 19 8 sum:59
19 20 12 14 14 1 sum:80
 */

#define NMAX 20000
#define CMAX 20000

bool finished = false;
int target, tracks[25], best_sum = INT_MIN, best_tracks[25], best_total_tracks;

int is_a_solution(int* a, int k, int n) {
    
    return (k == n);
}

void construct_candidate(int* a, int k, int n, int* c, int* ncandidates) {
    
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}

void process_solution(int* a, int k) {
    
    int i, sum, index = 0;

    sum = 0;
    for (i = 1; i <= k; i++)
        if (a[i] == true)
            sum += tracks[i];
    
    if (sum <= target && sum > best_sum) {
        best_sum = sum;
        for (i = 1; i <= k; i++)
            if (a[i] == true)
                best_tracks[index++] = tracks[i];
        best_total_tracks = index;
    }
}

void backtrack(int *a, int k, int size) {
    
    int c[CMAX]; /* candidates for the next position */
    int ncandidates = 0; /* next position candidate count */
    int i;
    
    if (is_a_solution(a, k, size))
        process_solution(a, k);
    else {
        k = k + 1;
        construct_candidate(a, k, size, c, &ncandidates);
        
        for (i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            backtrack(a, k, size);
            if (finished)
                return;
        }
    }
}

void generate_solution(int n) {
    
    int a[NMAX];
    backtrack(a, 0, n);
}

int main() {
    
    int i, n;
    
    while (scanf("%d", &target) == 1) {
        
        memset(best_tracks, 0, sizeof(best_tracks));
        best_total_tracks = 0;
        best_sum = INT_MIN;
        
        scanf("%d", &n);
        
        for (i = 1; i <= n; i++)
            scanf("%d", &tracks[i]);
        
        generate_solution(n);
        
        for (i = 0; i < best_total_tracks; i++)
            printf("%d ", best_tracks[i]);
        
        printf("sum:%d\n", best_sum);
        
        
        
    }
    
    return 0;
}
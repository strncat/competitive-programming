#include <stdio.h>

/* Look at the Longest Common Subsequence in Introduction to Algorithms (CLRS)

Ridiculous!!!!!!! This problem will waste your time, most hated? don't know yet
 
 When reading the input => remember that you are given POSITIONS of the numbers!!!!
 
 3 1 2 4
 ===== 3 is the position of number 1 ======== 
 so the correct sequence is the following:
 2 3 1 4
 
 UVa [111 - History Grading]
 Sample 1
 4
 4 2 3 1
 1 3 2 4
 3 2 1 4
 2 3 4 1
 Output 1
 1
 2
 3
 Sample 2
 10
 3 1 2 4 9 5 10 6 8 7
 1 2 3 4 5 6 7 8 9 10
 4 7 2 3 10 6 9 1 5 8
 3 1 2 4 9 5 10 6 8 7
 2 10 1 3 8 4 9 5 7 6
 Output 2
 6
 5
 10
 9
 */
#define N 21

int correct[N], answer[N], score[N][N];

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int LCS(int n) {
        
    int i, j;
    
    for (i = 0; i < n; i++)
        score[i][0] = 0;
    
    for (j = 0; j < n; j++)
        score[0][j] = 0;
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (correct[i] == answer[j])
                score[i][j] = 1 + score[i - 1][j - 1];
            else
                score[i][j] = max(score[i - 1][j], score[i][j - 1]);
    
    return score[n][n];
}

int main() {
    
    int i, position, n;
    
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        scanf("%d", &position);
        correct[position ] = i; /* WE ARE GIVEN THE POSITION */
    }
    
    while (1) {
        
        for (i = 1; i <= n; i++) {
            
            if (scanf("%d", &position) == EOF)
                return 0;
            
            answer[position] = i; /* WE ARE GIVEN THE POSITION */
        }
        printf("%d\n", LCS(n));
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>

/* 12337 - Bob's Beautiful Balls
 Sample Input
 12
 BGWBBGGGBBWGBBGWBB
 GBBWBBWBBB
 BBBBBBBBBBBBBBB
 GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGWW
 GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
 GGGGGGGGGGGG
 BGWBBGGGBBWGBBGWBBB
 BBBBWWBBBB
 BBBB
 BB
 BGGB
 WWBWW
 BGWWWWWGBBBBGGG
 Output for Sample Input
 Case 1: 9
 Case 2: -1
 Case 3: 8
 Case 4: -1
 Case 5: 20
 Case 6: 7
 Case 7: -1
 Case 8: 7
 Case 9: 4
 Case 10: -1
 Case 11: 4
 Case 12: -1
 Case 13: 8
 */

#define N 100

void print(char a[N][N], int row, int col) {
    
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%c\t", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void spiral(char *a, int n, int row, int col, char b[N][N]) { /* col >= row */
    
    int i = 0, j, l, cur_row = 0, height, index = 0, layers;
    
    if (row < col)
        layers = row / 2;
    else
        layers = col / 2;
    
    for (l = 0; l < layers; l++) {
        
        cur_row = j = l;
        height = row - ((l + 1) * 2); /* height of the column to fill */
        
        while (j < col - l) /* (1) go right */
            b[cur_row][j++] = a[index++];
        
        cur_row++; /* (2) go down */
        j = col - 1 - l;
        i = height;
        while (i--)
            b[cur_row++][j] = a[index++];
        
        for (j = col - 1 - l; j >= l; j--)  /* (3) go left */
            b[cur_row][j] = a[index++];
        
        /* (4) go up */
        cur_row--;
        i = height;
        j = l;
        while (i--)
            b[cur_row--][j] = a[index++];
    }
    
    cur_row++;
    j++;
    if (col >= row)
        while (index < n)
            b[cur_row][j++] = a[index++];
    else
        while (index < n)
            b[cur_row++][j] = a[index++];
}

int check_solution(char b[N][N], int row, int col) {
    
    int i, j;
    
    for (j = 0; j < col; j++)
        for (i = 1; i < row; i++)
            if (b[i][j] != b[i - 1][j])
                return 0;
    return 1;
}

int main() {
    
    int test_cases, i, length, width, factor, height, success, min;
    char s[150], b[N][N], c[N][N];
    
    scanf("%d", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
        
        success = 0;
        min = 99999;
        scanf("%s", s);
        
        length = (int) strlen(s);
        factor = sqrt(length);
        
        for (width = factor; width >= 2; width--) { /* try factors */
            
            if (length % width == 0) { /* if a factor check if each column has the same color */
                
                height = length / width;
                
                spiral(s, length, width, height, b);
                
                spiral(s, length, height, width, c);
                
                if (check_solution(b, width, height) || check_solution(c, height, width)) {
                    success = 1;
                    if (min > (height + width))
                        min = height + width;
                }
            }
        }
        if (success)
            printf("Case %d: %d\n", i, min);
        else
            printf("Case %d: -1\n", i);
    }
    return 0;
}
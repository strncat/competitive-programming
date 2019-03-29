#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 526 - String Distance and Transform Process
 
 http://www.cs.toronto.edu/~frank/csc401/tutorials/Levenshtein.pdf
 
 Sample Input
abcac
bcd
 
aaa
aabaaaa
 
aabaaaa
aaa
Sample Output
3
1 Delete 1
2 Replace 3,d
3 Delete 4
 
4
1 Insert 1,a
2 Insert 2,a
3 Insert 3,b
4 Insert 7,a
 
4
1 Delete 1,a
2 Delete 2,a
3 Delete 3,b
4 Delete 7,a
*/

#define N 100

int distance[N][N];
char path[N][N];

int min(int a, int b) {
    
    return a < b ? a : b;
}

void print(char *s1, char *s2, int n1, int n2) { /* debug */
    
    int i, j;
    
    for (i = 0; i <= n1; i++) {
        for (j = 0; j <= n2; j++)
            printf("%d\t", distance[i][j]);
        printf("\n");
    }
    printf("\n");
}

void print_path(char *s1, char *s2, int n1, int n2) { /* debug */
    
    int i, j;
    
    for (i = 0; i <= n1; i++) {
        for (j = 0; j <= n2; j++)
            printf("%c\t", path[i][j]);
        printf("\n");
    }
    printf("\n");
}

int edit_distance(char *s1, char *s2, int n1, int n2) {
    
    int i, j, insert, replace, delete;
    
    memset(distance, 0, sizeof(distance));
    memset(path, '0', sizeof(path));

    for (i = 1; i <= n1; i++) {
        distance[i][0] = i;
        path[i][0] = 'd';
    }
    
    for (j = 1; j <= n2; j++) {
        distance[0][j] = j;
        path[0][j] = 'i';
    }
    
    /* YOU HAVE TO FOLLOW THIS !!!!!
     http://www.cs.toronto.edu/~frank/csc401/tutorials/Levenshtein.pdf
     */
    for (i = 1; i <= n1; i++)
        for (j = 1; j <= n2; j++) {
            
            delete = distance[i - 1][j] + 1;
            insert = distance[i][j - 1] + 1;
            replace = distance[i - 1][j - 1] + (s1[i] != s2[j]);
            
            distance[i][j] = min(min(insert, delete), replace);
            
            if (delete == distance[i][j]) /* if the minimum came from up, we delete a character */
                path[i][j] = 'd';
                
            else if (insert == distance[i][j]) /* if the minimum came from left we insert a character */
                    path[i][j] = 'i';
                
            else if (s1[i] != s2[j]) /* replace */
                path[i][j] = 'r';
            else
                path[i][j] = '0'; /* no operation required */
            
        }
    return distance[n1][n2];
}

int step, delete, insert;

void construct_path(char *s1, char *s2, int i, int j) {
    
    if (path[i][j] == '0') /* same letter */ {
        construct_path(s1, s2, i - 1, j - 1);
    }
    
    else if (path[i][j] == 'd') { /* if we deleted a character we go up in the matrix (row up) */
        construct_path(s1, s2, i - 1, j);
        printf("%d Delete %d\n", step++, i + insert - delete);
        delete++;
    }
    
    else if (path[i][j] == 'i') { /* if we inserted a character we go left (column to the left) */
        construct_path(s1, s2, i, j - 1);
        printf("%d Insert %d,%c\n", step++, j, s2[j]);
        insert++;
    }
    
    else if (path[i][j] == 'r') {
        construct_path(s1, s2, i - 1, j - 1);
        printf("%d Replace %d,%c\n", step++, i + insert - delete, s2[j]);
    }
}

int main() {
    
    char s1[N], s2[N];
    int n1, n2, first = 1;

    while (gets(s1 + 1)) {
        
        /* (1) read input and make indices start at 1 instead of zero */
        gets(s2 + 1);
        
        /* (2) stupid necessity to print a blank line between two outputs */
        if (!first)
            printf("\n");
        first = 0;
        
        /* (3) build distance and path matrices */
        n1 = (int) strlen(s1 + 1);
        n2 = (int) strlen(s2 + 1);

        printf("%d\n", edit_distance(s1, s2, n1, n2));
        
        /* (4) re-construct path using the path matrix */
        step = 1;
        delete = 0;
        insert = 0;
        
        /* FUN TIMES
        print(s1, s2, n1, n2);
        print_path(s1, s2, n1, n2);
        */
        
        construct_path(s1, s2, n1, n2);
    }
    return 0;
}
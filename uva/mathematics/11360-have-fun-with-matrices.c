#include <stdio.h>
#include <string.h>
/*
11360 - Have Fun with Matrices
 Sample Input
 2
 4
 1234
 5678
 1234
 5678
 1
 transpose
 3
 000
 111
 000
 2
 row 1 2
 inc
 
 Sample Output
 Case #1
 1515
 2626
 3737
 4848
 
 Case #2
 222
 111
 111
*/

int a[9][9]; /* Max Length */

void print(int N) {
    int i, j;
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void transpose(int N) {
    int i, j, temp;
    
    for (i=0; i<N; i++)
        for (j=i; j<N; j++) {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
}

void row(int N, int x, int y) {
    
    int j, temp;
    
    for (j=0; j<N; j++) {
        temp = a[x][j];
        a[x][j] = a[y][j];
        a[y][j] = temp;
    }
}

void col(int N, int x, int y) {
    
    int i, temp;
    
    for (i=0; i<N; i++) {
        temp = a[i][x];
        a[i][x] = a[i][y];
        a[i][y] = temp;
    }
}

void inc(int N) {
    
    int i, j;
    
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            a[i][j] = (a[i][j] + 1)%10;
        
}

void dec(int N) {
    
    int i, j;
    
    for (i=0; i<N; i++)
        for (j=0; j<N; j++) {
            a[i][j] -= 1;
            if (a[i][j] < 0)
                a[i][j] = 9;
        }
    
}

int main() {
    
    int numbers;
    int cases, total_operations, i, j, N, counter;
    char operation[10];
    int input1, input2;
    
    scanf("%d", &cases);
    
    for (counter=1; counter<=cases; counter++) {
        
        scanf("%d",&N);
        
        /* Read Matrix, might be easier to do it with a string */
        for (i=0; i<N; i++) {
            scanf("%d", &numbers);
            j=0;
            a[i][N-j-1] = numbers%10;
            for (j=1; j<N; j++) {
                numbers = numbers/10;
                a[i][N-j-1] = numbers%10;
            }
        }
        
        /* Read Operations */
        scanf("%d", &total_operations);
        
        while (total_operations--) {
            
            scanf("%s", operation);
            
            if (!strcmp(operation, "row") || !strcmp(operation, "row")) /* read two more */ {
                scanf("%d %d", &input1, &input2);
                row(N, input1-1, input2-1);
            }
            else if (!strcmp(operation, "col")) {
                scanf("%d %d", &input1, &input2);
                col(N, input1-1, input2-1);
            }
            
            /* transpose is easy */
            else if (!strcmp(operation, "transpose"))
                transpose(N);
            
            else if (!strcmp(operation, "inc"))
                inc(N);
            
            else if (!strcmp(operation, "dec"))
                dec(N);
        }
     
        /* Print Matrix */
        printf("Case #%d\n", counter);
        print(N);

    }
    return 0;
}
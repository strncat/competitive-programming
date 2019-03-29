#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 482 - Permutation Arrays
 input
 3
 
 3 1 2
 32.0 54.7 -2
 
 3 1 2
 32.0 54.7 -2
 
 3 1 2
 32.0 54.7 -2
 output:
 54.7
 -2
 32.0
 
 54.7
 -2
 32.0
 
 54.7
 -2
 32.0
*/

#define N 100000

int a[N];
char b[N][50];

void selection_sort(int n) {
    
    int i, j, min, temp;
    char temp2[50];
    
    for(i=0; i<n; i++) {
        min = i;
        for (j=i+1; j<n; j++)
            if (a[j] < a[min])
                min = j;
        
        if (min != i) {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        
            strcpy(temp2, b[min]);
            strcpy(b[min], b[i]);
            strcpy(b[i], temp2);
        }
    }
}

int main() {
    
    int test_cases, n, i, first = 0;
    char input[N], *output;
    
    scanf("%d\n", &test_cases);
    
    while(test_cases--) {
        
        if (first) {
            getchar();
            printf("\n");
        }
        first = 1;
        
        gets(input);
        
        output = strtok(input, " ");
        n = 0;
        while (output != NULL) {
            a[n++] = atoi(output);
            output = strtok (NULL, " "); /* http://www.cplusplus.com/reference/cstring/strtok/ */
        }
        
        gets(input);
        
        output = strtok(input, " ");
        n = 0;
        while (output != NULL) {
            strcpy (b[n++], output);
            output = strtok (NULL, " ");
        }
        
        selection_sort(n);
        
        for (i = 0; i < n; i++)
            printf("%s\n", b[i]);
    }
    return 0;
}
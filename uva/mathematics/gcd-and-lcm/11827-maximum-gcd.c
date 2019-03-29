#include <stdio.h>
#include <string.h>

/* 11827 - Maximum GCD
SAMPLE INPUT:
3
10 20 30 40
7  5 12
125 15 25
SAMPLE OUTPUT:
20
1
25
*/

int GCD(int a, int b) {
    
    while (b != 0)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}

int main() {
    
    int i, j, test_cases, offset, n, a[100], cd, max, length, number;
    char line[100000], *data;
    
    scanf("%d\n", &test_cases);
    
    while(test_cases--) {
        
        fgets(line, 100000, stdin); /* fgets doesn't read the newline \n white gets does */
        data = line;
        
        length = (int) strlen(line);
        
        for (i = length - 1; i >= 0; i--)
            if (line[i] == '\n')
                line[i] = '\0';
        
        n = 0;
        max = 0;
        
        while (sscanf(data, " %d%n", &number, &offset) == 1) { /* found this (%n) on stack overflow! */
            data += offset;
            a[n++] = number;
        }
        
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++) {
                cd = GCD(a[i], a[j]);
                if (cd > max)
                    max = cd;
            }
        printf("%d\n", max);
    }
    return 0;
}
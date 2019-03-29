#include <stdio.h>
#include <string.h>

/* 12626 - I ❤ Pizza
Sample Input
5
MARGARITA
AAAAAAMMRRTITIGGRRRRRRRR
AMARGITA
BOLOGNESACAPRICHOSATOMATERA
ABCDEFGHIJKLMNOPQRSTUVWXYZ
Sample Output
1
2
0
1
0
*/


int main() {
    
    int i, test_cases, M[256], margarita;
    char c;
    
    scanf("%d\n", &test_cases);
    
    while (test_cases--) {
        
        for (i = 0; i < 256; i++)
            M[i] = 0;
        
        while ((c = getchar()) != '\n')
            M[c] += 1;
        
        margarita = 0;
        
        while (M['M'] > 0 && M['A'] > 2 && M['R'] > 1 && M['G'] > 0 && M['I'] > 0 && M['T'] > 0) {
            margarita += 1;
            
            M['M'] -= 1;
            M['A'] -= 3;
            M['R'] -= 2;
            M['G'] -= 1;
            M['I'] -= 1;
            M['T'] -= 1;
        }
        
        printf("%d\n", margarita);
    }

    
    return 0;
}
#include <stdio.h>

/* 408 - Uniform Generator
 Sample Input
 3 5
 15 20
 63923 99999
 Sample Output
 3         5    Good Choice
 15        20    Bad Choice
 63923     99999    Good Choice
 */

int GCD(int a, int b) {
    
    if(b == 0)
        return a;
    
    return GCD(b, a%b);
}

int main() {
    
    int step, mod;
    
    while (scanf("%d  %d", &step, &mod) == 2) {
        
        printf("%10d%10d    ", step, mod);
        
        if (GCD(step, mod) == 1)
            printf("Good Choice\n\n");
        else
            printf("Bad Choice\n\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
/*
 12403 - Save Setu
 Sample Input
 4
 donate 1000
 report
 donate 500
 report
 
 Sample Output
 1000
 1500
*/
int main() {
    
    int cases, amount, total=0;
    char operation[10];
    
    scanf("%d", &cases);
    
    while (cases--) {
        scanf("%s", operation);
        
        if (!strcmp(operation, "donate")) {
            scanf("%d", &amount);
            total += amount;
        }
        else
            printf("%d\n", total);
    }
    
    return 0;
}
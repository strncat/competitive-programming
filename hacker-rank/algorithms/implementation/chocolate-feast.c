#include <stdio.h>

/* Chocolate Feast
money <= 100,000
Sample input
3
10 2 5
12 4 4
6 2 2
Sample Output
6
3
5
*/

int main() {
    
    int test_cases, money, price, deal, pieces, wrappers, remainder;
    
    scanf("%d", &test_cases);
    
    while(test_cases--) {
        
        scanf("%d %d %d", &money, &price, &deal);
        
        pieces = money / price;
        wrappers = pieces;
        
        while (wrappers >= deal) {
            remainder = wrappers % deal;
            pieces += wrappers / deal;
            wrappers = (wrappers / deal) + remainder;
        }
        printf("%d\n", pieces);
    }
    return 0;
}

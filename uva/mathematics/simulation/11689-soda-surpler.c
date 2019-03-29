#include <stdio.h>

/* UVa [11689 - Soda Surpler]
 Input
 25
 999 998 44
 999 998 7
 999 998 14
 999 998 9
 999 998 6
 999 998 3
 999 998 113
 999 998 13
 999 998 17
 999 998 123
 9 0 3
 5 5 2
 999 998 222
 50 50 6
 855 22 32
 665 21 4
 800 200 14
 147 651 21
 333 265 8
 222 144 28
 255 666 34
 889 554 1001
 362 879 214
 999 999 1225
 214 689 140
 Output
 46
 332
 153
 249
 399
 998
 17
 166
 124
 16
 4
 9
 9
 19
 28
 228
 76
 39
 85
 13
 27
 1
 5
 1
 6
 */

int main() {
    
    int cases, e, f, c, bottles, sum, extra;
    
    scanf("%d", &cases);
    
    while (cases--) {
        
        scanf("%d %d %d", &e, &f, &c);
        
        bottles = e+f;
        sum = 0;
        
        while (bottles >= c) {
            extra = bottles%c;
            sum += (bottles/c);
            bottles = bottles/c + extra;
        }
        
        printf("%d\n", sum);
        
    }
    return 0;
}

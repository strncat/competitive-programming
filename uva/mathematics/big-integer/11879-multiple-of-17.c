#include <stdio.h>
#include <string.h>

/* SO I fall for the trick, I did this using the algorithm in the problem and after I got my solution accepted I checked other solutions and learned that this was supposed to be very simple using modular arithmetic!! 
 
 11879 - Multiple of 17
Input
34
201
2098765413
1717171717171717171717171717171717171717171717171718
8115008370134377512665417134
0
Output
1
0
1
0
1
*/

int main() {
    
    long long int final, multiply;
    int i, length, d, index, borrow, number[1000], ds[2];
    char line[2000];
    
    while (gets(line)) { /* fgets(number, 150, stdin); */
        
        if (line[0] == '0' && line[1] == '\0')
            break;
        
        length = (int) strlen(line);
        
        for (i = 0; i < length; i++)
            number[i] = line[i] - '0';

        while (length > 10) {
            
            d = number[length - 1]; /* maximum is 2 digits for the [last digit * 5] */
            d *= 5;
            ds[0] = d % 10;
            ds[1] = d / 10;
            length--;
            
            index = 0;
            borrow = 0;
            for (i = length - 1; i >= 0; i--) {
                
                if (borrow == 1) {
                    number[i] -= 1;
                    borrow = 0;
                }
                
                if (number[i] < 0) { /* need to borrow */
                    number[i] += 10;
                    borrow = 1;
                }
                
                if (index < 2) {
                    
                    if (number[i] < ds[index]) {
                        number[i] += 10;
                        borrow = 1;
                    }
                    number[i] -= ds[index];
                    index++;
                }
            }
        }
        
        final = number[length - 1];
        multiply = 10;
            
        for (i = length - 2; i >= 0; i--) {
            final += ((number[i]) * multiply);
            multiply *= 10;
        }
        
        if (final % 17 == 0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Anagram
Constraints
1<=T<=100
length of input string i.e. 1<=a+b<=10000
Sample Input
5
aaabbb
ab
abc
mnop
xyyx
xulkowreuowzxgnhmiqekxhzistdocbnyozmnqthhpievvlj
Sample Output
3
1
-1
2
0
13
*/
int main() {

    int i, j, test_cases, length, sum, frequency[26];
    char s[10010];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%s", s);
        length = (int) strlen(s);
        memset(frequency, 0, sizeof(frequency));
        
        if (length % 2 == 0) {
            sum = 0;
            for (i = 0, j = length - 1; i < j; i++, j--) {
                frequency[s[i] - 'a']++;
                frequency[s[j] - 'a']--;
            }
            for (i = 0; i < 26; i++) {
                sum += abs(frequency[i]);
            }
            printf("%d\n", sum/2);
            
        } else {
            printf("-1\n");
        }
    }
    return 0;
}

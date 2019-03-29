#include <stdio.h>
#include <string.h>

/* Hackerrank: Palindrome Index O(n) 
 1
 hgygsvlfcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcwflvsgygh
 answer = 44
 */

int main() {

    int cases, n, i, j, position, firstIndexRemovedWorks;
    char str[100010];

    scanf("%d", &cases);

    while (cases--) {

        scanf("%s", str);
        n = (int) strlen(str);
        position = -1;
        i = 0;
        j = n - 1;
        firstIndexRemovedWorks = -1;

        while (i < j) {
            if (position == -1 && str[i] != str[j]) { // first time to see a no match
                // try skipping that position to see if it works
                position = i;
                i++;
            } else if (position != -1 && str[i] != str[j]) { // removing first position didn't work! it must be the other position then
                firstIndexRemovedWorks = n - position - 1;
                break; // no need to continue
            }
            else {
                i++;
                j--;
            }
        }

        if (position == -1) {
            printf("-1\n");
        }
        else if (firstIndexRemovedWorks == -1) {
            printf("%d\n", position);
        } else {
            printf("%d\n", n - position - 1);
        }
    }
    return 0;
}

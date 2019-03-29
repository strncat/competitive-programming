#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Gem Stones
Only "a" and "b" occur in each of the rocks compositions
Sample Input
3
abcdde
baccd
eeabg
Sample Output
 2
*/

int main() {
    
    int k, n, i, length, count[26], total = 0;
    char s[105], temp_count[26];
    
    memset(count, 0, sizeof(count));
    scanf("%d", &n);
    
    k = n;
    while (k--) {
        scanf("%s", s);
        memset(temp_count, 0, sizeof(temp_count));
        
        length = (int) strlen(s);
        for (i = 0; i < length; i++)
            temp_count[s[i] - 'a']++;
        
        for (i = 0; i < 26; i++)
            if (temp_count[i])
                count[i]++;
    }
    for (i = 0; i < 26; i++)
        if (count[i] >= n)
            total++;
    
    printf("%d\n", total);
    return 0;
}


#include <stdio.h>
#include <string.h>

/* Game Of Thrones - I
Sample Input
aaabbbb
cdefghmnopqrstuvw
cdcdcdcdeeeef
Sample Output
YES
NO
YES
*/

int main() {
    
    char s[1000010];
    int count[26], odd = 0, even = 0;
    
    scanf("%s", s);
    
    memset(count, 0, sizeof(count));
    
    int length = (int) strlen(s);
    
    for (int i = 0; i < length; i++)
        count[s[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (count[i] % 2)
            odd++;
        else
            even++;
    }
    
    if ((length % 2 && odd <= 1) || (odd == 0))
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}

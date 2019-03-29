#include <stdio.h>
#include <string.h>

/* UVa [11192 - Group Reverse]

It doesn't really need a reverse function, but for sake of practice, why not?
*/

void reverse(char *str, int begin, int end) {
    
    char *first=&str[begin], *last=&str[end], temp;
    
    while (first < last) {
        
        temp = *last;
        *last-- = *first;
        *first++ = temp;
    }
}

int main() {
    
    int n, i, length, size;
    char s[101];
    
    while (scanf("%d", &n) == 1 && n) {

        scanf("%s", s);
        
        length = (int) strlen(s);
        size = length/n;
        
        /* each bucket is of size is 1, no need to reverse */
        if (size == 1)
            ;
        /* only one group */
        else if (n == 1)
            reverse(s, 0, length-1);
        else
            for (i=0; i<length; i=i+size)
                reverse(s, i, i+size-1);
        
        printf("%s\n", s);
        
    }
    return 0;
}

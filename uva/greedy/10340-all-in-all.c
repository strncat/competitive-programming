#include <stdio.h>
#include <string.h>

/* 10340 - All in All
 
 TIP: I got a million TLE because I forgot the ==2 part here:
 while(scanf("%s %s", s, t) == 2)
 
 sequence subsequence => Yes
 person compression => No
 VERDI vivaVittorioEmanueleReDiItalia => Yes
 caseDoesMatter CaseDoesMatter => No
 abcc abcdddd => No
*/

int main()
{
    char s[1000000], t[1000000];
    int i, j;
    
    while(scanf("%s %s", s, t) == 2) {
        
        j = 0;
        for(i=0; s[j] != '\0' && t[i] != '\0' ;i++)
            if(s[j] == t[i])
                j++;
        
        if(s[j] == '\0')
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

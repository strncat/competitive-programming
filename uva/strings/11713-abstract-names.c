#include <stdio.h>
#include <string.h>

/* 11713 - Abstract Names
 Sample Input
 5
 pele
 polo
 pele
 pola
 ronaldo
 ronaldino
 pele
 pelet
 pele
 bele
 
 Output for Sample Input
 Yes
 Yes
 No
 No
 No
*/

int main() {

    int i, test_cases, length;
    char first[100], second[100];
    
    scanf("%d", &test_cases);

    while (test_cases--) {
        
        scanf("%s", first);
        scanf("%s", second);
        
        length = (int) strlen(first);
        
        if (length == strlen(second)) {
            for(i = 0; i <length; i++)
                if (((first[i]=='a' || first[i]=='e'|| first[i]=='i' || first[i]=='o' || first[i]=='u')
                   && (second[i]=='a' || second[i]=='e'|| second[i]=='i' ||second[i]=='o'|| second[i]=='u')
                    ) || (first[i] == second[i]))
                    continue;
                else
                    break;
        }
        
        if (i == length)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
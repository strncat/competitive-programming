#include <stdio.h>
#include <string.h>

/* 119 - Greedy Gift Givers
 Input:
 5
 dave laura owen vick amr
 dave 200 3 laura owen vick
 owen 500 1 dave
 amr 150 2 vick owen
 laura 0 2 amr vick
 vick 0 0
 3
 liz steve dave
 liz 30 1 steve
 steve 55 2 liz dave
 dave 0 2 steve liz
 
 Output
 dave 302
 laura 66
 owen -359
 vick 141
 amr -150
 
 liz -3
 steve -24
 dave 27
 */

char names[20][20];

int find_index(char *name, int n) {
    
    int i;
    
    for (i = 0; i < n; i++)
        if (strcmp(name, names[i]) == 0)
            return i;
    return -1;
}

int main() {

    int n, i, people, money, gift, balance[20], index, new_line = 0;
    char name[20];
    
    while (scanf("%d", &n) == 1) {
        
        /* Read Names */
        for (i = 0; i < n; i++) {
            scanf("%s", names[i]);
            balance[i] = 0;
        }
        /* Gifts */
        for (i = 0; i < n; i++) {
            scanf("%s %d %d", name, &money, &people);
            index = find_index(name, n);
            
            if (people) {
                gift = money / people;
                
                balance[index] -= (people * gift); /* exact money spent on gifts */
            
                while (people--) {
                    scanf("%s", name);
                    index = find_index(name, n);
                    balance[index] += gift;
                }
            }
        }
        
        /* Printing */
        if (new_line) /* print a new line on subsequent test cases */
			printf("\n");
        new_line = 1;
    
        for (i = 0; i < n; i++)
            printf("%s %d\n", names[i], balance[i]);
    }
    return 0;
}
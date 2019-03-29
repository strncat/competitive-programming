#include <stdio.h>

/* 10324 - Zeros and Ones 
 naive solution, could be done better. 
 */

int main() {

    char a[1000001];
    int i, j, N, counter=0, temp;
    
    while (scanf("%s", a) == 1) {
        
        scanf("%d", &N);
        
        printf("Case %d:\n", ++counter);
        
        while (N--) {
            
            scanf("%d %d", &i, &j);
                        
            if (j < i) {
                temp = i;
                i = j;
                j = temp;
            }
            
            while (i < j) {
                if (a[i+1] != a[i])
                    break;
                i++;
            }
                        
            if (i == j)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}


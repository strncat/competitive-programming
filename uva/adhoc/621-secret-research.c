#include <stdio.h>
#include <string.h>

/* UVa [621 - Secret Research] */

int main() {
    
    int cases, length;
    char str[10001];
    
    scanf("%d", &cases);
    
    while(cases--) {
        
        scanf("%s", str);
        length = (int) strlen(str);
      
        if (!strcmp(str, "1") || !strcmp(str, "4") || !strcmp(str, "78"))
            printf("+\n");
        else if ( str[length-1] == '5' && str[length-2] == '3')
            printf("-\n");
        else if( str[0] == '9' && str[length-1] == '4')
            printf("*\n");
        else
            printf("?\n");
    }
    return 0;
}

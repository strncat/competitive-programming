#include <stdio.h>
#include <string.h>

int main() {
    
    char str[100];
    int a, b;
    
    while ( (fgets(str,sizeof(str),stdin)) != NULL ) { /* fgets returns NULL on EOF */
        
        sscanf(str,"%d %d",&a,&b);
        printf("%d\n",2*a*b);
    }
    return 0;
}
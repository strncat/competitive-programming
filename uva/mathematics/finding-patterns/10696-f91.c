#include <stdio.h>

int main() {
    
    int n=0;
    
    while(1)
    {
        scanf("%d", &n);
        
        if (n == 0)
            break;
        
        if (n > 100)
            printf("f91(%d) = %d\n", n, n-10);
        else if (n <= 100)
            printf("f91(%d) = 91\n", n);
    }
    return 0;
}

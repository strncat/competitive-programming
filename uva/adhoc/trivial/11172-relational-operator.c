#include <stdio.h>
#include <math.h>

int main() {
    
    int test_cases=0;
    long long int a, b;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%lld %lld", &a, &b);
        
        if (a > b)
            printf(">\n");
        else if (a < b)
            printf("<\n");
        else
        printf("=\n");
    }
    return 0;
}

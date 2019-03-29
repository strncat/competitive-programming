#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char input[100];
    double x;
    int i, n;
    
    while(scanf("%s",input)==1) {
        if( input[0] == '0' && strlen(input) == 1)
            break;
        
        n=strlen(input);
        x=0;
        
        for(i=0;i<n;i++) {
            x += (input[i]-48) * (pow(2,n-i)-1);
        }
        printf("%.lf\n", x);
    }
    return 0;
}

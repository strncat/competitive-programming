#include <stdio.h>

/* Bitwise Exclusive-Or (XOR) */
/* 32bit unsigned int */

int main()
{
    unsigned int a,b;
    
    while(scanf("%u %u",&a,&b) == 2) {
        printf("%u\n",a^b);
    }
    return 0;
}
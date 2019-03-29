#include <stdio.h>
#include <string.h>

/* 10070 - Leap Year or Not Leap Year and ... 
 
   leap year: divisible by 4 and not divisible by 100 with the exception divisible by 400
   Huluculu festival: divisible by 15
   Bulukulu festival: divisible by 55 provided that is also a leap year
   printing order: leapyear-->huluculu-->bulukulu
 
   Divisibility Rules: http://en.wikipedia.org/wiki/Divisibility_rule#Divisibility_rules_for_numbers_1.E2.80.9320
   (4) last two digits is divisble by 4
   (100) ends in 00
   (15) divisible by 3 (sum of digits) and by 5 (ending in 0 or 5)
   (55) divisble by 11 (the alternating sum of the digits is divisible by 11) and ending in 0 or 5
   (400) 
 
    test cases: 
    3600 leap & huluculu
    22220 leap & bulukulu
*/

int main()
{
    char d[100000];
    int n, i, sum3, sum11, leap, newline=0, ordinary;
    int div3, div4, div5, div11, div100, div15, div55, div400;
    
    while (scanf("%s", d) == 1) {
        
        div3=0, div4=0, div5=0, div11=0, div100=0, div15=0, div55=0, div400=0;
        sum3=0, sum11=0, leap=0, ordinary=1;
        
        n = (int)strlen(d);
        
        /* switch to int instead? */
        for (i=0; i<n; i++)
            d[i] -= '0';
        
        for (i=0; i<n; i++) {
            sum3 += d[i];
            if (i%2 == 0)
                sum11 += d[i];
            else
                sum11 -= d[i];
        }
        
        if (sum3%3 == 0)
            div3 = 1;
        
        if (sum11%11 == 0)
            div11 = 1;
        
        if ((d[n-1]+(10*d[n-2]))%4 == 0) 
            div4 = 1;
        
        if (d[n-1] == 0 || d[n-1] == 5)
            div5 = 1;
        
        if (div3 && div5)
            div15 = 1;
        
        if (div11 && div5)
            div55 = 1;
        
        if (!d[n-1] && !d[n-2])
            div100 = 1;
            
        if (div100 && (d[n-3]+d[n-4]*10)%4 == 0)
            div400 = 1;
        
        if(newline==1)
            printf("\n");
        newline=1;
        
        if ((div4 && !div100) || div400) {
            printf("This is leap year.\n");
            leap = 1;
            ordinary = 0;
        }
        
        if (div15) {
            printf("This is huluculu festival year.\n");
            ordinary = 0;
        }
        
        if (leap && div55) {
            printf("This is bulukulu festival year.\n");
            ordinary = 0;
        }
                
        if (ordinary)
        printf("This is an ordinary year.\n");
                
    }
    
    return 0;
}


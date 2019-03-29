#include <stdio.h>

/* 10346 - Peter's Smokes
 
 Peter has n cigarettes. He smokes k of them.Every k, he rolls a new cigarette using those k.
 *** He can reuse the new ones to make more every k ***
  
 if n=100 and k=5, he smokes 100, rolls 100/5=20 new and then uses the 20 to roll 20/5=4 more.
 
 Looked up other answers after submission and came across the following very simple solution: 
 sum = n+(n-1)/(k-1) but I'm not sure how to prove it. 
 
 test cases:
 8492 142  => 8552
 15881 300 => 15934
 10677 119 => 10767
 3 2 => 5
 12 3 => 17
 1200 5 => 1499
 1200 1200 => 1201
 25326 3652 => 25332
 456987 326596 => 456988
 5 3 => 7

*/
int main() {

    long int n, k, sum;
        
    while(scanf("%ld %ld",&n, &k) == 2) {
        
        sum = n;
        while(n >= k)
        {
            sum += n/k;
            n = n/k + n%k;
        }
        printf("%ld\n", sum);
    }
    return 0;
}


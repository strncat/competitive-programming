//
//
//  Project Euler
//
//  Created by FB on 12/11/24.
//  21 Amicable Numbers https://projecteuler.net/problem=21
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 10001

bool amicable[N];
int amicable_sum[N];

void fill_amicable_sum(int n) {
    int max = sqrt(n);
    for (int i = 1; i <= max; i++) {
        if (n % i == 0) { // it's a divisor
            //printf("divisor = %d\n", i);
            amicable_sum[n] += i;
            if (n / i != i && i != 1) { // add the other divisor
                amicable_sum[n] += n/i;
                //printf("divisor = %d\n", n/i);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    //freopen("triangle.txt" , "r" , stdin);
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    memset(amicable_sum, 0, sizeof(amicable_sum[0])*N);
    memset(amicable, 0, sizeof(amicable[0])*N);

    // find the amicable_sum of each integer i
    for (int i = 1; i <= N; i++) {
        fill_amicable_sum(i);
    }
    
    // 220 and 284 are amicable numbers because
    // amicable_sum[220]=284 and amicable_sum[284]=220
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (amicable[i]) {
            continue;
        }
        int a = amicable_sum[i]; // in the example, this is 284
        // now we need to check, that amicable_sum[284] == i
        if (i == amicable_sum[a] && i != a) {
            printf("%d and %d are amicable because amicable[%d]=%d, amicable[%d]=%d\n", i, a, i, amicable_sum[i], a, amicable_sum[a]);
            sum += i + a;
            amicable[i] = true;
            amicable[a] = true;
        }
    }
    
    printf("%d\n", sum);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

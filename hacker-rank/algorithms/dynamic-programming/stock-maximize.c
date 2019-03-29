#include <stdio.h>
#include <string.h>
/* Stock Maximize
Constraints
1 <= T <= 10
1 <= N <= 50000
All share prices are between 1 and 100000
Sample Input
4
3
5 3 2
3
1 2 100
4
1 3 1 2
6
1 8 1 2 1 5
Sample Output
0
197
3
18
*/

/* so I submitted my solution and it worked, I passed all test cases
 I usually look at what others did after, I found the following solution
 which is brilliant, I was just over complicating my life
 I hope I can learn something from this!
 
 long int max_current_future_price = 0;
 long int profit = 0;
 for (i=N-1; i>=0; --i) {
 max_current_future_price = maximum(max_current_future_price, price[i]);
 profit += max_current_future_price - price[i];
 }
 printf("%ld\n", profit);
*/

long int maximum(long int a, long int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {

    int i, j, k, N, test_cases, index[50000];
    long int price[50000], sum[50000], profit[50000];

    scanf("%d", &test_cases);

    while (test_cases--) {
        
        scanf ("%d", &N);
        
        memset(sum, 0, sizeof(sum));
        memset(profit, 0, sizeof(profit));
        
        for (i = 0; i < N; i++) {
            scanf("%ld", &price[i]);
        }

        index[0] = 0;
        for (i = 1; i < N; i++) {
            index[i] = 0;
            for (j = i - 1; j >= 0; j--) {
                if (price[j] > price[i]) {
                    index[i] = j + 1;
                    break;
                }
            }
            for (k = index[i]; k < i; k++) {
                sum[i] += price[k];
            }
        }
        profit[0] = 0;
        for (i = 1; i < N; i++) {
            profit[i] = maximum(profit[index[i]] + (i - index[i])*price[i] - sum[i], profit[i - 1]);
        }
        printf("%ld\n", profit[N - 1]);
    }
    return 0;
}

#include <stdio.h>

/* Bus Station
1 ≤ n ≤ 10^5
1 ≤ a^i ≤ 104
Sample Input
8
1 2 1 1 1 2 1 3
Sample Output
3 4 6 12
*/

int main() {
    
    int bus, i, j, n, group[100000];
    long long int total_sum, total, sum[100000];

    scanf("%d", &n);
    
    total_sum = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &group[i]);
        total_sum += group[i];
    }
    
    j = 0;
    sum[0] = 0;
    for (bus = 1; bus < n; bus++) {
        sum[bus] += sum[bus - 1] + group[j++];
    }
    
    for (i = 1; i < n; i++) {
        
        if (total_sum % sum[i]) {
            continue;
        }

        total = 0;
        for (j = 0; j < n; j++) {
            total += group[j];
            if (total == sum[i]) {
                total = 0;
                continue;
            } else if (total > sum[i]) {
                break;
            }
        }
        if (j == n && (total == sum[i] || total == 0)) {
            printf("%lld ", sum[i]);
        }
    }
    
    printf("%lld\n", total_sum);
    
    return 0;
}


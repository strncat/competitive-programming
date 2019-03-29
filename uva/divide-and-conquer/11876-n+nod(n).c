#include <stdio.h>
#include <math.h>
#include <string.h>

/* 11876 - N + NOD (N) | n_0 = 1, n_i = n_(i-1) + nod(n_(i-1))
 Sample Input
 3
 1 18
 1 100
 3000 4000
 Sample Output
 Case 1: 7
 Case 2: 20
 Case 3: 87
*/

#define MAX 1000001 /* 1,000,001 */

int nod[MAX];

int binary_search(int number, int low, int high) {
    
    int mid;
    
    while (low < high) {
        
        mid = (low + high) / 2;
        
        if (number == nod[mid])
            return mid;
        else if (number < nod[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    /* printf("%d %d %d %d %d %d\n", low, nod[low], mid, nod[mid], high, nod[high]); */
    /* if failed to find an exact index, return the start of the last brack [low, high] */
    return low;
}

int divisors(int number) {
    
    int i, count = 0, st = sqrt(number);
    
    for (i = 1; i <= st; i++)
        if (number % i == 0)
            count += 2;
    
    if (st * st == number) { /* Exception */
        count--;
    }
    return count;
}

int pre_nod() {
    
    int i;
    
    nod[0] = 1;
    for (i = 1; nod[i - 1] <= MAX; i++) /* ONLY CALCULATE UP TO WHERE NOD[i] = 1,000,000 */
        nod[i] = nod[i - 1] + divisors(nod[i - 1]);
    
    return i; /* total elements */
}

int main() {
    
    int i, test_cases, a_index, b_index, N;
    int A, B; /* 1 ≤ A ≤ B ≤ 1,000,000 */
    
    scanf("%d", &test_cases);
    
    N = pre_nod();
    
    for (i = 1; i <= test_cases; i++) {
        
        scanf("%d %d", &A, &B);
        
        a_index = binary_search(A, 0, N);
        b_index = binary_search(B, 0, N);
        
        /* it case it is not an exact match */
        if(nod[a_index] < A)   a_index++;
        if(nod[b_index] > B)   b_index--;
        
        printf("Case %d: %d\n", i, b_index - a_index + 1);
    }
    return 0;
}
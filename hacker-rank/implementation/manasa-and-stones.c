#include <stdio.h>
int unique_sum = -1;

void rec(int step, int index, int sum, int a, int b) { /* times out */
    
    if (step == 0) {
        if (sum > unique_sum) {
            printf("%d ", sum);
            unique_sum = sum;
        }
        return;
    }
    rec(step - 1, 0, sum + a, a, b);
    rec(step - 1, 1, sum + b, a, b);
}

void count(int a, int b, int step) {
    
    int current = 0;
        int numAs = (step - 1) - numBs;
        if (temp > current) {
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int test_cases, step, a, b;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &step);
        scanf("%d %d", &a, &b);
        
        if (a > b) {
        }
        
        if (step <= 1) {
            printf("%d %d\n", a, b);
            continue;
        }
    
    return 0;
}
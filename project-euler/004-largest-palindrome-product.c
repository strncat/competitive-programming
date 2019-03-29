// Project Euler #4: Largest palindrome product
// Constraints
// 1 ≤ T < 100
// 101101 < N < 1000000
// Sample Input
// 2
// 101110
// 800000
// Sample Output
// 101101
// 793397
//

#include <stdio.h>

#define N 10000

int isPalindrome(int n) {
    int reminder, reverse = 0, number = n;
    while (n > 0) {
        reminder = n % 10;
        reverse = reverse * 10 + reminder;
        n = n / 10;
    }
    return (reverse == number);
}

int largestPalindrome(int n) {
    int palindrome, largestPalindrome = 0;
    for (int i = 999; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (i * j < largestPalindrome) { break; }
            palindrome = isPalindrome(i * j);
            if (palindrome && i * j > largestPalindrome && i * j <= n) {
                largestPalindrome = i * j;
            }
        }
    }
    return largestPalindrome;
}

void testCases() {
    int largest = largestPalindrome(800000);
    largestPalindrome(101110) == 101101 ?  printf("success\n") : printf("failed %d is incorrect\n", largest);
    largest = largestPalindrome(800000);
    largestPalindrome(800000) == 793397 ?  printf("success\n") : printf("failed %d is incorrect\n", largest);
}

int main() {
    int cases, n;
    testCases();
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        printf("%d\n", largestPalindrome(n));
    }
    return 0;
}

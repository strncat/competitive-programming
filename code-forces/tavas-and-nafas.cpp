//
//  299, A.Tavas and Nafas, codeforces
//

#include <iostream>
#include <vector>
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::string> tens = {"0", "0", "twenty", "thirty", "forty", "fifty",
        "sixty", "seventy", "eighty", "ninety"};
    std::vector<std::string> ones = {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
    std::vector<std::string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    if (n >= 0 && n <= 9) {
        printf("%s\n", ones[n%10].c_str());
    } else if (n >= 10 && n <= 19) {
        printf("%s\n", teens[n%10].c_str());
    } else {
        printf("%s", tens[n/10].c_str());
        if (n%10 != 0) {
            printf("-%s\n", ones[n%10].c_str());
        } else {
            printf("\n");
        }
    }
    return 0;
}

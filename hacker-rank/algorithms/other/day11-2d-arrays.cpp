#include <vector>
#include <iostream>
#include <limits.h>


int main() {
    std::vector<std::vector<int>> a(6,std::vector<int>(6));
    for (int i = 0; i < 6; i++) {
       for (int j = 0; j < 6; j++) {
          std::cin >> a[i][j];
       }
    }
    // possible start points for an hour glass
    int max_sum = INT_MIN;
    for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 4; j++) {
           int sum = a[i][j] + a[i][j+1] + a[i][j+2];
           sum += a[i+1][j+1];
           sum += a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
           if (sum > max_sum) {
               max_sum = sum;
           }
       }
    }
    std::cout << max_sum << std::endl;
    return 0;
}


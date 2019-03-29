//
//  299, B. Tavas and SaDDas, codeforces
//  n <= 10^9
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>

// (4 7) = 2
// (44 47 74 77) = 4
// (444 447 474 477) (744 747 774 777) = 8
// (4444 4447 4474 4477) (4744 4747 4774 4777) (7444 7447 7474 7477) (7744 7747 7774 7777) = 16

// my solution
int index(std::string n) { // I failed in the contest because I forgot to add 256 to the array :(
    int powers[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}; // 256 :((((
    int index = 0;

    for (int i = 1; i < n.size(); i++) { // base index
        index += powers[i];
    }

    for (int i = 0; i < n.size(); i++) { // now locate within the bracket
        if (n[i] == '7') {
            index += (powers[n.size() - i]/2);
        }
    }
    return index + 1;
}

// author's solution
int binary(std::string n) {
    int ans = 0;
    for (int i = 0; i < n.size(); i++) {
        ans  = 2*ans + n[i]-'0';
    }
    int p = 1;
    for (int i = 0; i < n.size(); i++) {
        p = p << 1;
    }
    ans += p - 1;
    return ans;
}
std:: string lu(std::string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = (char)(s[i]=='4'?'0':'1');
    }
    return s;
}

int main() {
    std::string n;
    std::cin >> n;
    printf("%d\n", index(n));
    //printf("%d\n", binary(lu(n))); author's solution
    return 0;
}

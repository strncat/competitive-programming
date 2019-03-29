//
//  Google Jam April 10th 2015
//  Problem A. Standing Ovation
//

#include <iostream>

int main() {
    freopen("in-large.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    
    int tests;
    std::cin >> tests;

    for (int t = 1; t <= tests; t++) {
        int n;
        std::string s;
        std::cin >> n >> s;

        int need = 0, total = 0;

        for (int i = 0; i <= n; i++) {
            int will_clap = s[i] - '0'; // those people want to clap

            if (will_clap > 0 && total < i) { // but they need other people to stand up first
                need += i - total; // add how many additional people I would need to invite
                total = i; // increment clapped with the same amount
            }
            total += will_clap; // after they clap, add those people to total clapped
        }
        printf("Case #%d: %d\n", t, need);
    }
    return 0;
}

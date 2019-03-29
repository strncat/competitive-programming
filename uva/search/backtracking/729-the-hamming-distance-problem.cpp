//
//  main.cpp
//  uhunt
//
//  729 - The Hamming Distance Problem
//  2017/03/03
//
//

#include <iostream>
#include <vector>

using std::vector;
using std::string;

void generate_binary_strings(vector<string>& a, string& s, int n, int h, int k) {
    if (s.size() == n) {
        a.push_back(s);
        return;
    }
    if (k < h) { // still need ones
        s.push_back('1');
        generate_binary_strings(a, s, n, h, k+1);
        s.pop_back();
    }

    if (n - s.size() > h - k) { // still enough space to push zeros
        s.push_back('0');
        generate_binary_strings(a, s, n, h, k);
        s.pop_back();
    }
}

int main() {
    //freopen("sample.in", "r", stdin);
    int t, n, h;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d %d\n", &n, &h);
        string s;
        vector<string> a;
        generate_binary_strings(a, s, n, h, 0);
        for (int i = (int)a.size()-1; i >= 0; i--) {
            for (int j = 0; j < a[i].size(); j++) {
                std::cout << a[i][j];
            }
            printf("\n");
        }
        if (t) { printf("\n"); }
    }
    return 0;
}
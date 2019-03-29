//
//  main.cpp
//  uhunt
//
//  444 - Encoder and Decoder
//  2017 02 02
//
// Input & Output ... make sure the reverse works as well!
// abcdefghijklmnopqrstuvwxyz! ,.:;?
// ABCDEFGHIJKLMNOPQRSTUVWXYZ! ,.:;?
// 36958564442333221121021911811711611511411311211111011901801701601501401301201101001998979
// 369585644423330998887868584838281808978777675747372717079686766656
//

#include <iostream>


bool is_valid_char(int n) {
    if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122)
        || n == 32 || n == 33 || n == 44 || n == 56
        || n == 46 || n == 58 || n == 59 || n == 63) {
        return true;
    }
    return false;
}

std::string decode(std::string line) {
    std::string s = "";
    for (int i = (int)line.length()-1; i >= 0;) {
        // first two digits
        int sum = (line[i] - '0')*10 + (line[i-1] - '0');
        if (is_valid_char(sum)) { // is this a valid sum?
            char c = sum;
            s += c;
            i -= 2;
        } else { // take a third digit
            sum = (sum*10) + line[i-2] - '0';
            char c = sum;
            s += c;
            i -= 3;
        }
    }
    return s;
}

std::string encode(std::string line) {
    std::string s = "";
    for (int i = (int)line.length()-1; i >= 0; i--) {
        int n = line[i];
        while (n > 0) { // reverse the ascii code and concat to s
            s += std::to_string(n%10);
            n /= 10;
        }
    }
    return s;
}

int main() {
    //freopen("sample.in", "r", stdin);
    std::string line;
    std::string s;
    while (getline(std::cin, line)) {
        if (line[0] >= '0' && line[0] <= '9') { // 798999 => cba
            std::cout << decode(line) << std::endl;
        } else { // abc => 998979
            std::cout << encode(line) << std::endl;
        }
    }
    return 0;
}

//
//  10226 - Hardwood Species
//
 
#include <iostream>
#include <string>
#include <unordered_map>

std::string possible_palindrome(std::string s) {
    std::unordered_map<char, int> hash;
    int n = (int) s.length();
    for (int i = 0; i < n; i++) {
        if (hash.count(s[i]) == 0) {
            hash[s[i]] = 1;
        } else {
            hash[s[i]]++;
        }
    }

    std::unordered_map<char, int>::iterator i;
    int odd = 0;
    for(i = hash.begin(); i != hash.end(); i++) {
        if (i->second & 1) { // odd value
            odd++;
        }
    }

    // ababa: one odd count / odd length = ok
    // abaaba: no odd count / even length = ok
    //if (((n & 1) && odd > 1) || (!(n & 1) && odd > 0)) {
    //    return "NO";
    //} else {
    //    return "YES";
    //}

    // hmmm okay so it is impossible to have a single odd
    // count in an even length string so ...

    if (odd > 1) {
        return "NO";
    } else {
        return "YES";
    }

}

void tests() {
    std::string s[4] = {"ababa", "abaaba", "aaabbbb", "cdcdcdcdeeeef"};
    std::string correct[4] = {"YES", "YES", "YES", "YES"};
    for (int i = 0; i < 4; i++) {
        if (possible_palindrome(s[i]).compare(correct[i]) != 0) {
            printf("test failed %s \n", s[i].c_str());
        }
    }
}

int main() {
    //tests();
    std::string s;
    std::cin >> s;
    std::string answer = possible_palindrome(s);
    std::cout << answer;
    return 0;
}

//
//  main.cpp
//  uhunt
//
//  11988 - Broken Keyboard (a.k.a. Beiju Text)
//  2017/02/06
//
//  After finishing this problem I looked at other accepted solutions
//  and I guess I didn't (think of using / didn't know) about begin() and end()
//  on strings to move the iterator back and forth :)
//  Definitely makes the solution way easier ... although it is an easy problem anyway

#include <iostream>

int main() {
    //freopen("sample.in", "r", stdin);

    std::string line;
    while (getline(std::cin, line)) {
        std::string result = "";
        int i = 0;
        while (i < line.size()) {
            if (line[i] != '[' && line[i] != ']') {
                result += line[i];
                i++;
            } else if (line[i] == '[') {
                while (i < line.size() && line[i] == '[') {
                    i++; // skip all the openning brackets
                }
                std::string sub = "";
                while (i < line.size() && line[i] != '[' && line[i] != ']') {
                    sub += line[i];
                    i++;
                }
                result = sub + result;
            } else { // ']' just skip it
                i++;
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}

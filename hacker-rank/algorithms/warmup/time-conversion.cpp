//
//  Time Conversion
//  You are given time in AM/PM format. Convert this into a 24 hour format
//  07:05:45PM => 19:05:45
//

#include <iostream>
#include <cstring>

int main() {
    int h;
    char datetime[20];
    std::string s = "";

    scanf("%d%s", &h, datetime);
    int index = (int) strlen(datetime)-2;

    if (datetime[index] == 'P') {
        if (h < 12) { h += 12; }
    }

    if (datetime[index] == 'A') {
        if (h == 12) { h = 0; }
    }

    s += (char) h/10 + '0';
    s += (char) h%10 + '0';

    for (int i = 0; i < index; i++) {
        s += datetime[i];
    }

    printf("%s\n", s.c_str());
    return 0;
}

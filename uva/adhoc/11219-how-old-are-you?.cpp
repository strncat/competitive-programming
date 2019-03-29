//
//  main.cpp
//  uhunt
//
//  11219 - How old are you?
//  2017/02/07
//

#include <iostream>

int main() {
    //freopen("sample.in", "r", stdin);
    int test_cases;
    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        int day1, month1, year1, day2, month2, year2;
        scanf("%d/%d/%d", &day2, &month2, &year2);
        scanf("%d/%d/%d", &day1, &month1, &year1);

        int y = year2-year1;
        int m = month2-month1;
        int d = day2-day1;

        if ((m < 0) || (m == 0 && d < 0)) {
            y--;
        }

        if (y < 0) {
            printf("Case #%d: Invalid birth date\n", t);
        } else if (y > 130) {
            printf("Case #%d: Check birth date\n", t);
        } else {
            printf("Case #%d: %d\n", t, y);
        }
    }
    return 0;
}
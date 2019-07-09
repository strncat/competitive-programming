//
//  Library Fine
//  aghhh
//

#include <iostream>

int main() {
    int d1, d2, m1, m2, y1, y2, fine = 0;
    scanf("%d %d %d", &d1, &m1, &y1);
    scanf("%d %d %d", &d2, &m2, &y2);

    // (1) If the book is returned in the same month as the expected return date, Fine = 15 Hackos × Number of late days
    if (m1 == m2 && d1 > d2) {
        fine += 15 * (d1 - d2);
    }

    // (2) If the book is not returned in the same month but in the same year as the expected return date, Fine = 500 Hackos × Number of late months
    else if (y1 == y2 && m1 > m2) {
        fine += 500 * (m1 - m2);
    }

    // (3) If the book is not returned in the same year, the fine is fixed at 10000 Hackos.
    else if (y1 > y2) {
        fine += 10000 * (y1 - y2);
    }

    printf("%d\n", fine);
    return 0;
}

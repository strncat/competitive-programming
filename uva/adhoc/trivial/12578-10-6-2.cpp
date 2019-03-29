//
//  UVa
//  12578 - 10:6:2
//

#include <iostream>
#include <math.h>

int main() {
    //freopen("sample.in", "r", stdin);

    int t, length;
    double width, radius, circle_area, remaining_area;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &length);
        width = (length * 6.0)/10.0;
        radius = length/5.0;
        circle_area = acos(-1) * radius * radius;
        remaining_area = width * length - circle_area;
        printf("%.2f %.2f\n", circle_area, remaining_area);
    }
    return 0;
}

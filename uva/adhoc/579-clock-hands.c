#include <stdio.h>
#include <math.h>

/* UVa [579 - ClockHands]
 Sample Input
 12:00
 9:00
 8:10
 0:00
 Sample Output
 0.000
 90.000
 175.000 */

int main() {
    
    int hour, minute;
    double angle, m_angle, a_angle;
    
    while (scanf("%d:%d", &hour, &minute) == 2) {
        
        if (!hour && !minute)
            break;
        
        m_angle = minute/5.0*30.0;
        a_angle = hour*30.0 + minute*30.0/60.0; /* hour * 30 (each hour is 30 degrees) + minute/2 for the little extra */
        angle = fabs(a_angle-m_angle);
        
        if (angle > 180.0)
            angle = 360.0 - angle;
        
        printf("%.3f\n", angle);
    }
    return 0;
}

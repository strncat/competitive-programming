#include <stdio.h>

/* UVa [10281 - Average Speed]
 Sample Input
 00:00:01 100
 00:15:01
 00:30:01
 01:00:01 50
 03:00:01
 03:00:05 140
 Output for Sample Output
 00:15:01 25.00 km
 00:30:01 50.00 km
 03:00:01 200.00 km
 */

int main() {
    int n, hour, minute, second, speed, new_speed, total_seconds, previous_seconds;
    char line[100];
    double distance = 0;
    
    speed = 0; /* intial speed is 0 */
    previous_seconds = 0; /* previous seconds is 0 */
    
    while(fgets(line, 100, stdin)) {
        n = sscanf(line,"%d:%d:%d %d", &hour, &minute, &second, &new_speed);
        
        total_seconds = hour * 3600 + minute * 60 + second;
        distance += (total_seconds - previous_seconds) / 3600.0 * speed;
        previous_seconds = total_seconds;
        
        if(n == 3)
            printf("%02d:%02d:%02d %.2f km\n",hour, minute, second, distance);
        else
            speed = new_speed;
    }
    return 0;
}

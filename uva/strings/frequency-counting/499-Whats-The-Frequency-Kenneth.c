#include <stdio.h>

/* 499 - What's The Frequency, Kenneth?
 
 When riding your bicycle backwards down a one-way street, if the      => e 6
 wheel falls of a canoe, how many ball bearings does it take to fill   => al 7
 up a water buffalo?                                                   => a 3
 Hello Howard.                                                         => Hlo 2
*/

#define N 26 

int main() {
    
    char line[100000];
    int lower[N], upper[N];
    int i, max;
        
    while (fgets(line, sizeof(line), stdin) != NULL) { /* NULL on EOF */
        
        for (i=0; i<N; i++) {
            lower[i] = 0;
            upper[i] = 0;
        }
        
        for (i=0; line[i] != '\0'; i++) {
            
            if (line[i] >= 'a' && line[i] <= 'z')
                lower[line[i]-'a']++;
            
            if (line[i] >= 'A' && line[i] <= 'Z')
                upper[line[i]-'A']++;
        }
        
        max=0;
        for (i=0; i<N; i++) {
                        
            if (upper[i] > max)
                max = upper[i];
            
            if (lower[i] > max)
                max = lower[i];
        }
                
        for (i=0; i<N; i++) 
            if (upper[i] == max)
                printf("%c", i+'A');
        
        for (i=0; i<N; i++) 
            if (lower[i] == max)
                printf("%c", i+'a');
        
        printf(" %d\n", max);
    }
    return 0;
}


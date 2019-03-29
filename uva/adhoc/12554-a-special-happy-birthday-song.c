#include <stdio.h>

/* 12554 - A Special "Happy Birthday" Song!!!
 Sample Input
 3
 Mom
 Dad
 Girlfriend
 Output for the Sample Input
 Mom: Happy
 Dad: birthday
 Girlfriend: to
 Mom: you
 Dad: Happy
 Girlfriend: birthday
 Mom: to
 Dad: you
 Girlfriend: Happy
 Mom: birthday
 Dad: to
 Girlfriend: Rujia
 Mom: Happy
 Dad: birthday
 Girlfriend: to
 Mom: you
*/

int main() {

    int N, i, k = 0, repeat;
    char names[100][101];
    char song[20][20] = {"Happy", "birthday", "to", "you",
                         "Happy", "birthday", "to", "you",
                         "Happy", "birthday", "to", "Rujia",
                         "Happy", "birthday", "to", "you"};
    
    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%s", names[i]);
    
    repeat = N / 16;
    if (N % 16 != 0)
        repeat++;
    
    while(repeat--) {
        for (i = 0; i < 16; i++)
            printf("%s: %s\n", names[k++ % N], song[i]);
    }
    
    
    return 0;
}
#include <stdio.h>
#include <string.h>

/* 11278 - One-Handed Typist
 Sample Input
 Hg66t Mty6k!
 Jhg 4ibl; pytmn 8tc 5i79urrr
 t,gy jhg 6fxo kt.r
 
 Output for the Sample Input
 Hello World!
 The quick brown fox jumps...
 over the lazy dog.
*/

int main() {
    
    char line[2000];
    char qwerty[50] = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char dvoark[50] = "123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
    char shift_qwerty[50] = "!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    char shift_dvoark[50] = "!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
    int i, j, print;
    
    
    while(fgets(line, 2000, stdin)) {
        
        for(i = 0; line[i]; i++) {
            
            print = 0;
            
            for (j = 0; qwerty[j]; j++)
                if (qwerty[j] == line[i]) {
                    putchar(dvoark[j]);
                    print = 1;
                }
            
            for (j = 0; shift_qwerty[j]; j++)
                if(shift_qwerty[j] == line[i]) {
                    putchar(shift_dvoark[j]);
                    print = 1;
                }
            
            if(!print)
                putchar(line[i]);
        }
    }
    return 0;
}
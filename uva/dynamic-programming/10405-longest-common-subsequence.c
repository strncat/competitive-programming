#include <stdio.h>
#include <string.h>

/* 10405 - Longest Common Subsequence
Sample input
a1b2c3d4e
zz1yy2xx3ww4vv
abcdgh
aedfhr
abcdefghijklmnopqrstuvwxyz
a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0
abcdefghijklmnzyxwvutsrqpo
opqrstuvwxyzabcdefghijklmn
 
Output for the sample input
4
3
26
14
*/

char line1[1010], line2[1010];
int LCS[1010][1010];

int max(int num1,int num2) {
    if(num1 > num2)
        return num1;
    return num2;
}

int longest_common_subsequece(int len1,int len2) {
    
    int i, j;
    
    if(len1 <= 0 || len2 <= 0)
        return 0;
    
    for (i = 0; i <= len1; i++)
        LCS[i][0] = 0;
    
    for (j = 0; j <= len2; j++)
        LCS[0][j] = 0;
    
    for (i = 1; i <= len1; i++)
        for (j = 1; j <= len2; j++) {
           
            if (line1[i - 1] == line2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    
    return LCS[len1][len2];
}

int main() {
    
    int len1, len2;
    
    while (gets(line1)) { /* fgets includes extra characters ... */
        
        gets(line2);
        
        len1 = (int) strlen(line1);
        len2 = (int) strlen(line2);
        
        printf("%d\n", longest_common_subsequece(len1,len2));
    }
    return 0;
}

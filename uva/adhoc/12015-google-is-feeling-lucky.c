#include <stdio.h>

/*  12015 - Google is Feeling Lucky

 Sample Input
 2
 www.youtube.com 1
 www.google.com 2
 www.google.com.hk 3
 www.alibaba.com 10
 www.taobao.com 5
 www.bad.com 10
 www.good.com 7
 www.fudan.edu.cn 8
 www.university.edu.cn 9
 acm.university.edu.cn 10
 www.youtube.com 1
 www.google.com 2
 www.google.com.hk 3
 www.alibaba.com 11
 www.taobao.com 5
 www.bad.com 10
 www.good.com 7
 www.fudan.edu.cn 8
 acm.university.edu.cn 9
 acm.university.edu.cn 10
 
 Sample Output
 
 Case #1:
 www.alibaba.com
 www.bad.com
 acm.university.edu.cn
 Case #2:
 www.alibaba.com
*/

int main() {
    
    int i=0, j=0, cases, counter;
    char urls[10][100]; /* 10 urls for every case */
    int value[10];
    int max=0;
    
    scanf("%d", &cases);
    
    for (counter=1; counter<=cases; counter++) {
        
        max = 0;
        for (i=0; i<10; i++) {
            scanf("%s %d", urls[i], &value[i]);
            
            if (value[i] > max)
                max = value[i];
        }
        printf("Case #%d:\n", counter);
        
        for (j=0; j<10; j++)
            if (value[j] == max)
                printf("%s\n", urls[j]);
    }
    return 0;
}
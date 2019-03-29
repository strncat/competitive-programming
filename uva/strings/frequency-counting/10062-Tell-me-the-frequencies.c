#include <stdio.h>
#include <string.h>
/* could be done in a much easier way */

/* 10062 - Tell me the frequencies!
   
 Count 32 <= ASCII <= 127, 127-33+1 = 96
 
 test cases:
 AAABBC
 122333
 
 67 1
 66 2
 65 3
 
 49 1
 50 2
 51 3
 */

#define N 96

struct letter {
    char c;
    int frequency;
};

void swap(struct letter *a, struct letter *b) {
    int temp;
    char ch;
    
    ch = a->c;
    a->c = b->c;
    b->c = ch;
    
    temp = a->frequency;
    a->frequency = b->frequency;
    b->frequency = temp;
}

void bubble_sort(struct letter x[]) {
    
    int i=0, j=1;
    
    for (i=0; i<N; i++)
        for (j=i+1; j<N; j++) {
            if (x[j].frequency < x[i].frequency)
                swap(&x[j],&x[i]);
            else if ((x[j].frequency == x[i].frequency) && (x[j].c > x[i].c))  /* OR */
                swap(&x[j],&x[i]);
        }
}

int main() {
    
    int i=0, n=0, flag=1;
    char line[1005];
    struct letter a[N];
    
    while(fgets(line, sizeof(line), stdin) != NULL) { /* NULL on EOF */
                
        n = (int)strlen(line);
        
        for(i=0;i<N;i++) {
            a[i].c= i + ' '; /* Space is 32 */
            a[i].frequency=0;
        }
        
        for (i=0; i<n; i++)
            if (line[i] >= 32 && line[i] <= 127) 
                a[line[i] - ' '].frequency++;
        
        /* Sort */
        bubble_sort(a);
        
        if (flag)
            flag=0;
        else printf("\n");
    
        for(i=0;i<N;i++)
            if (a[i].frequency > 0)
                printf("%d %d\n", a[i].c, a[i].frequency);
    }
    return 0;
}
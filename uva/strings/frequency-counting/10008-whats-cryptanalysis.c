#include <stdio.h>
#include <string.h>

/* Count letters only
   ASCII: A is 65 and Z is 90 
          a is 97 and z is 122 */
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
    
    for (i=0; i<26; i++)
        for (j=i+1; j<26; j++) {
            if (x[j].frequency > x[i].frequency) 
                swap(&x[j],&x[i]);
            else if ((x[j].frequency == x[i].frequency) && (x[j].c < x[i].c))  /* OR */
                swap(&x[j],&x[i]);
        }
}

int main() {
    
    int i=0, n=0, lines=0;
    char line[10000];
    struct letter a[26];
    
    for(i=0;i<26;i++)
    {
        a[i].c= i + 'A';
        a[i].frequency=0;
    }
    
    scanf("%d\n",&lines);
    
    /* Count */
    while(lines--) {
 
        fgets(line, sizeof(line), stdin);
    
        n = (int)strlen(line);
        
        for (i=0; i<n; i++) 
            if (line[i] >= 65 && line[i] <= 90)
                a[line[i] - 65].frequency++;
            else if (line[i] >= 97 && line[i] <= 122)
                a[line[i] - 97].frequency++;
    }
    
    /* Sort */
    bubble_sort(a);
    
    for(i=0;i<26;i++)
        if (a[i].frequency > 0)
            printf("%c %d\n", a[i].c, a[i].frequency);
    
    
    return 0;
}


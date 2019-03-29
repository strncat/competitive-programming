#include <stdio.h>

int lower=0, upper=0, mid=0;
int a[50000];

int binary_search_boundries(int u, int n) {
    
    int first=0, last=n-1;
    
    while(first <= last) {
        mid=(first+last)/2;
        
        if(a[mid] == u) { /* because array contain unique elements, */
            lower = mid-1;
            upper = mid+1;
            return 1;
        }
        else if(u > a[mid])
            first=mid+1;
        else
            last=mid-1;
    }
    /* if u was not foud, first and last would be the boundaries */
    lower = last;
    upper = first;
    return -1;
}

int main()
{
    int N, Q, u, n, temp, result, i;
    
    scanf("%d",&N);
    
    n=0;
    if (N > 0)
        scanf("%d", &a[0]);
    n++;
    
    for (i=1; i<N; i++) {
        scanf("%d", &temp);
        
        if (temp != a[n-1])
            a[n++] = temp;
    }
    
    scanf("%d",&Q);
    
    for(i=0;i<Q;i++) {
        
        scanf("%d",&u);
        
        lower=0, upper=0;
                
        result = binary_search_boundries(u, n);
        
        if(result != -1) {
            if(a[mid] == a[0] && n == 1)
                printf("X X\n");
            
            else if(a[mid] == a[0])
                printf("X %d\n", a[upper]);
            
            else if(a[mid] == a[n-1]) 
                printf("%d X\n", a[lower]);
            
            else
                printf("%d %d\n", a[lower], a[upper]);
        }
        else {
            if(u < a[0])
                printf("X %d\n", a[0]);
            
            else if(u > a[n-1]) {
                printf("%d X\n", a[n-1]);
            }
            else
                printf("%d %d\n", a[lower], a[upper]);
        }
    }
    
    return 0;
}
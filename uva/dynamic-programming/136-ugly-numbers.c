#include <stdio.h>

#define N 10000

int ugly_number(int index);

int main() {
    
    printf("The 1500'th ugly number is %d.\n",ugly_number(1500));
        
    return 0;
}

int ugly_number(int index) {
    
    int ugly[N];
    int index2=0, index3=0, index5=0;
    int next_ugly_index=1;
    int minimum;
    
    if (index <= 0)
        return 0;
    
    ugly[0]=1;
    
    while (next_ugly_index < index)
    {
        /* Find Min */
        minimum = ugly[index2]*2;
        
        if (ugly[index3]*3 < minimum)
            minimum = ugly[index3]*3;
        
        if (ugly[index5]*5 < minimum)
            minimum = ugly[index5]*5;
        
        ugly[next_ugly_index] = minimum;
        
        /* Update indices */
        
        while (ugly[index2]*2 <= ugly[next_ugly_index])
            index2++;
        
        while (ugly[index3]*3 <= ugly[next_ugly_index])
            index3++;
        
        while (ugly[index5]*5 <= ugly[next_ugly_index])
            index5++;
            
        next_ugly_index++;
    }
    
    return ugly[next_ugly_index-1];
    
}
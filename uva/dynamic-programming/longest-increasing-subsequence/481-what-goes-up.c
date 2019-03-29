#include <stdio.h>
#include <string.h>

/* this was a hard problem, it took me a while to do it. you have to use the O(nlgn) algorithm otherwise you're going to get a TLE */

/* 481 - What Goes Up
 INPUT
 1825198813
 703574781
 1357013548
 882614101
 91123810
 693635462
 509962994
 13091984
 476503935
 692987701
 845877457
 484660669
 2118992354
 1583536068
 1830890927
 125909470
 389054618
 61633602
 1167630334
 1245222478
 1653407157
 1539092241
 1260848996
 1092105640
 1343321214
 1337792438
 743752911
 895144236
 644021011
 306984050
 206209071
 1968038758
 694647582
 627044827
 1228453736
 923849393
 994690063
 1935458528
 351391203
 1747161030
 1759120300
 1040627854
 1076069512
 1110842238
 2104791827
 326007565
 159295061
 522217290
 1564248899
 459709341
 368308305
 510183713
 1141726537
 2069288597
 94198657
 557718943
 1355469954
 1075065596
 1830809408
 660014489
 1515539776
 750393546
 518211796
 692879112
 1918631132
 533634230
 1974805736
 1999632389
 616397282
 1170189545
 315109278
 834252002
 1161967889
 103216749
 1534876392
 998665307
 1795057301
 1251226459
 900157290
 1509113371
 1092226810
 1988172767
 2128641328
 1107418067
 48984604
 1391219046
 1763691983
 435334167
 1137289136
 78170531
 1100176263
 795618180
 2087635596
 893474920
 1313562613
 1238129761
 314970551
 566882611
 2043820790
 1354652240
 
 Output
 17
 -
 1825198813
 13091984
 125909470
 389054618
 644021011
 694647582
 923849393
 994690063
 1040627854
 1076069512
 1110842238
 1141726537
 1355469954
 1515539776
 1534876392
 1795057301
 1988172767
 2043820790
 */

#define N 200000

int binary_search(int *s, int *a, int first, int last, int x) {
    
    int mid;
 
    while (first < last) {
        
        mid = (first + last) / 2;
        
        if (a[s[mid]] == x)
            return mid;
        
        else if (a[s[mid]] > x)
            last =  mid;
        
        else
            first = mid + 1;
    }
    
    return first; /* or last */
}

int longest_increasing_sequence(int *a, int *p, int *s, int n) {
    
    int i, index, k;
    
    index = 1;
    s[1] = 0; /* s[i] is the smallest (index of) integer that ends an increasing sequence of length i */
    p[0] = -1; /* parent of first element */
    
    for (i = 1; i < n; i++) {
        
        if (a[i] > a[s[index]]) { /* a new larger element is found, extend the sequence */
            s[index + 1] = i;
            p[i] = s[index]; /* parent of s[index + 1] = i is s[index] */
            index++;
        }
        
        /* else find the smallest element in s >= a[i] using binary search since s is sorted */
        /* basically insert a[i] in s such that s stays sorted */
        
        else {
            k = binary_search(s, a, 1, index, a[i]);
            
            if (a[s[k]] > a[i]) /* if truly greater than, otherwise no */
                s[k] = i;
            
            p[i] = s[k - 1]; /* parent of s[k] = i is s[k - 1] */
        }
        
    }
    return index;
}

void construct_subsequence(int *a, int *p, int *s, int n, int index) {
    
    if (p[index] >= 0)
        construct_subsequence(a, p, s, n, p[index]); /* print the parent of value first */
    
    printf("%d\n", a[index]);
}

int main() {
    
    int n = 0, length, a[N], s[N], p[N];
    
    while(scanf("%d", &a[n++]) != EOF)
        continue;
    
    length = longest_increasing_sequence(a, p, s, n - 1);
    
    printf("%d\n-\n", length);
    
    construct_subsequence(a, p, s, n - 1, s[length]);
    
    return 0;
}
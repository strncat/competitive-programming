#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 10776 - Determine The Combination
 Sample Input
 abcde 2
 abcd 3
 aba 2
 aabb 2
 aaa 2
 Sample Output
 ab
 ac
 ad
 ae
 bc
 bd
 be
 cd
 ce
 de
 abc
 abd
 acd
 bcd
 aa
 ab
 aa
 ab
 bb
 aa
 */

#define N 2000

/* ------------------ MERGE SORT ----------------------- */

void merge(char a[], int begin, int end, int mid) {
    
    int b[N], c[N];
    int i, j, k, m, index;
    
    for (i = 0; begin + i <= mid; i++)
        b[i] = a[begin + i];
    
    for (j = 0; mid + 1 + j <= end; j++)
        c[j] = a[mid + 1 + j];
    
    k = 0, m = 0, index = begin;
    while (k < i && m < j) {
        if (b[k] < c[m])
            a[index++] = b[k++];
        else
            a[index++] = c[m++];
    }
    
    /* left overs */
    while (k < i)
        a[index++] = b[k++];
    while (m < j)
        a[index++] = c[m++];
    
}

void merge_sort(char a[], int begin, int end) {
    
    int mid = (end + begin) / 2;
    
    if (end - begin > 0) {
        merge_sort(a, begin, mid);
        merge_sort(a, mid + 1, end);
        merge(a, begin, end, mid);
    }
    return;
}

/* ------------------ STACK ----------------------- */

#define M 40

typedef struct stack {
    char s[N];
    int top;
} stack;

void push(stack *s, char item) {
    
    if (s->top == N)
        return;
    
    s->s[s->top++] = item;
}

char pop(stack *s) {
    
    if (s->top == 0)
        return -1; /* ERROR */
    
    return s->s[--s->top];
}

void init(stack *s) {
    s->top = 0;
}

int empty(stack *s) {
    return (s->top == 0);
}

/* ------------------ COMBINATIONS ----------------------- */

void combination_core(char *s, int length, int index, int number, stack *result) {
    
    char combination[M];
    int i;
    
    if (number == 0) { /* print */
        
        /* prepare combination from stack */
        memset(combination, 0, sizeof(combination));
        for (i = 0; i < result->top; i++)
            combination[i] = result->s[i];
        combination[i] = '\0';
        
        printf("%s\n", combination);
        return;
    }
    
    if (index == length)
        return;
    
    push(result, s[index]);
    combination_core(s, length, index + 1, number - 1, result);
    pop(result);
    
    /* CHOOSE THE NEXT DIFFERENT CHARACTER? */
    while (index < length - 1 && s[index] == s[index + 1])
        index++;
        
    combination_core(s, length, index + 1, number, result);
}

void combination(char *s, int length, int size) {
    
    stack *result = malloc(sizeof(stack));
    init(result);
    
    combination_core(s, length, 0, size, result);
}

int main() {
    
    char s[M];
    int size, length;
    
    while (scanf("%s %d", s, &size) == 2) {
        
        length = (int) strlen(s);
        merge_sort(s, 0, length - 1);
        combination(s, length, size);
    }
    return 0;
}
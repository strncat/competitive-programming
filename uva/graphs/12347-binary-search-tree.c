#include <stdio.h>

/*
 12347 - Binary Search Tree
 Sample input
 50
 30
 24
 5
 28
 45
 98
 52
 60
 Sample output
 5
 28
 24
 45
 30
 60
 52
 98
 50
*/
# define N 10000

void merge(int a[], int begin, int end, int mid) {
    
    int i, j, k, m, b[N], c[N], index;
    
    for (i = 0; begin + i <= mid; i++)
        b[i] = a[begin + i];
    
    for (j = 0; mid + 1 + j <= end; j++)
        c[j] = a[mid + 1 + j];
    
    k = 0;
    m = 0;
    index = begin;
    
    while (k < i && m < j)
        if (b[k] < c[m])
            a[index++] = b[k++];
        else
            a[index++] = c[m++];
    
    while (k < i) /* left overs */
        a[index++] = b[k++];
    while (m < j)
        a[index++] = c[m++];
    
}

void merge_sort(int a[], int begin, int end) {
    
    int mid = (begin + end) / 2;
    
    if (begin < end) {
        merge_sort(a, begin, mid);
        merge_sort(a, mid + 1, end);
        merge(a, begin, end, mid);
    }
    
}

/* http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/ */
int search(int arr[], int x, int n) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void print_post_order(int in[], int pre[], int n) {
    /* The first element in pre[] is always root, search it
     in in[] to find left and right subtrees */
    int root = search(in, pre[0], n);
    
    /* If left subtree is not empty, print left subtree */
    if (root != 0)
        print_post_order(in, pre+1, root);
    
    /* If right subtree is not empty, print right subtree */
    if (root != n-1)
        print_post_order(in+root+1, pre+root+1, n-root-1);
    
    /* Print root */
    printf("%d\n", pre[0]);
}

int main() {
    
    int n = 0, t, pre[N] = {4, 3, 2, 0, -1}, in[N];
    
    while (scanf("%d", &t) == 1) {
        pre[n] = t;
        in[n++] = t;
    }
    
    merge_sort(in, 0, n - 1);
    print_post_order(in, pre, n);
    
    
    return 0;
}
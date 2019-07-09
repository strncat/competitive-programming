#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *s, int *a, int first, int last, int x) {

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

int longestIncreasingSubsequence(int *a, int n) {

    int *s = (int *) malloc(sizeof(int) * n);
    int i, index, k;

    index = 1;
    s[1] = 0; /* s[i] is the "smallest" (index of) element that ends an increasing sequence of length i = 1 */

    for (i = 1; i < n; i++) {

        if (a[i] > a[s[index]]) { /* a new larger element is found, extend the sequence */
            s[index + 1] = i;
            index++;
        }

        /* else find the smallest element in s >= a[i] using binary search since s is sorted */
        /* basically insert a[i] in s such that s stays sorted */

        else {
            k = binarySearch(s, a, 1, index, a[i]);

            if (a[s[k]] > a[i]) /* if truly greater than then replace otherwise no */
                s[k] = i;
        }

    }
    return index;
}

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {

    int n;

    scanf("%d", &n);

    int *a = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d\n", longestIncreasingSubsequence(a, n));

    return 0;
}

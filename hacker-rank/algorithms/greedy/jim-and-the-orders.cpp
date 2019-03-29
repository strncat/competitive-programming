//
//  Grid Challenge
//  2015 / 09 / 25
//
//
/* simple problem but ....
   using quick sort won't give a correct answer since it's not a stable sort!
   I replaced it with merge sort and it worked!
   I could've made the solution simpler by using a comparator with c++ pairs
   but I just wanted to write merge sort yet again
*/

#include <iostream>

void print(int *a, int first, int last) {
    for (int i = first; i <= last; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *a, int *b, int first, int mid, int last) {
    int c[1001], d[1001], i, j;
    int e[1001], f[1001];

    for (i = 0; first + i <= mid; i++) {
        c[i] = a[first + i];
        e[i] = b[first + i];
    }

    for (j = 0; mid + 1 + j <= last; j++) {
        d[j] = a[mid + 1 + j];
        f[j] = b[mid + 1 + j];
    }

    int index = first, k = 0, m = 0;
    while (k < i && m < j) {
        if (c[k] < d[m] || (c[k] == d[m] && e[k] < f[m])) {
            a[index] = c[k];
            b[index] = e[k];
            index++;
            k++;
        } else {
            a[index] = d[m];
            b[index] = f[m];
            index++;
            m++;
        }
    }

    while (k < i) {
        a[index] = c[k];
        b[index] = e[k];
        index++;
        k++;
    }

    while (m < j) {
        a[index] = d[m];
        b[index] = f[m];
        index++;
        m++;
    }
}

void mergesort(int *a, int *b, int first, int last) {
    int mid = (first + last) / 2;
    if (first < last) {
        mergesort(a, b, first, mid);
        mergesort(a, b, mid + 1, last);
        merge(a, b, first, mid, last);
    }
}

void order_times(int *t, int *f, int n) {
    mergesort(t, f, 0, n-1);
}

void tests() {
    int t[5] = {8+1, 4+2, 5+6, 3+1, 4+3};
    int f[5] = {1, 2, 3, 4, 5};
    int correct[5] = {4, 2, 5, 1, 3};

    order_times(t, f, 5);
    for (int i = 0; i < 5; i++) {
        if (correct[i] != f[i]) {
            printf("test failed\n");
            break;
        }
    }
    //print(f, 0, 4);
}

int main() {
    tests();
    int n, order_time, time_to_finish, f[1001], t[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &order_time, &time_to_finish);
        t[i] = order_time + time_to_finish;
        f[i] = i + 1;
    }
    order_times(t, f, n);
    print(f, 0, n-1);
    return 0;
}

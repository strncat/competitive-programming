//
//  Grid Challenge
//
//

#include <iostream>

void print(char *a, int first, int last) {
    for (int i = first; i <= last; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *a, int first, int last) {
    int index = first;
    int pivot = last;
    for (int i = first; i < last; i++) {
        if (a[i] < a[pivot]) {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[index], &a[pivot]);
    return index;
}

void quicksort(char *a, int first, int last) {
    if (first < last) {
        int mid = partition(a, first, last);
        quicksort(a, first, mid - 1);
        quicksort(a, mid + 1, last);
    }
}

bool can_be_sorted(char *a, int n) {
    // sort every row
    for (int i = 0; i < n*n; i+=n) {
        quicksort(a, i, i+n-1);
        //print(a, i, i+n-1);
    }
    // check if every column is sorted
    for (int i = 0; i < n*n; i++) {
        if (i+n < n*n && a[i] > a[i+n]) {
            return false;
        }
    }
    return true;
}

void tests() {
    // test1
    char a[25] = {'e','b','a','c','d',
                  'f','g','h','i','j',
                  'o','l','m','k','n',
                  't','r','p','q','s',
                  'x','y','w','u','v'};
    bool sorted = can_be_sorted(a, 5);
    if (sorted == false) { printf("failed test\n"); }
    // test2
    char b[1] = {'p'};
    sorted = can_be_sorted(b, 1);
    if (sorted == false) { printf("failed test\n"); }
}

int main() {
    //tests();
    int cases, n;
    char a[101*101];
    std::string line;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        int index = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> line;
            for (int j = 0; j < line.length(); j++) {
                a[index++] = line[j];
            }
        }
        bool sorted = can_be_sorted(a, n);
        if (sorted) { printf("YES\n"); } else { printf("NO\n"); }
    }
    return 0;
}

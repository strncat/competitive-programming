//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/29/19.
//  497 - Strategic Defense Initiative
//

#include <iostream>
#include <vector>
#include <stack>

#define MAX 10000
#define INF (1<<30)

void longest_increasing_subsequence_fast(std::vector<int> &a) { // O(nlogn)
    int m[MAX], p[MAX];
    long n = a.size();
    for (int i = 0; i < n; i++) {
        m[i] = INF;
        p[i] = -1;
    }
    m[0] = -1; m[1] = 0;
    int k = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[m[k]]) { // extend the largest subsequence
            k++;
            m[k] = i;
            p[m[k]] = m[k-1];
        } else { // update a previous subsequence, binary search case
            int first = 0, last = k;
            while (last > first + 1) {
                int mid = (first + last) / 2;
                if (a[m[mid]] < a[i]) {
                    first = mid;
                } else {
                    last = mid;
                }
            }
            m[last] = i;
            p[m[last]] = m[last-1];
        }
    }

    // print sequence
    std::stack<int> s;
    printf("Max hits: %d\n", k);
    int index = m[k];
    while (index != -1) {
        s.push(a[index]);
        index = p[index];
    }

    while (!s.empty()) {
        printf("%d\n", s.top());
        s.pop();
    }
    return;
}

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    int tests;
    scanf("%d", &tests);
    getchar(); // extra new line
    getchar(); // extra new line

    while (tests--) {
        std::vector<int> a;
        int x;
        char s[100];

        while (fgets(s, 100, stdin)) {
            if (s[0] == '\n') {
                break;
            }
            // otherwise
            sscanf(s, "%d\n", &x);
            a.push_back(x);
        }

        longest_increasing_subsequence_fast(a);

        if (tests) {
            printf("\n");
        }
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}

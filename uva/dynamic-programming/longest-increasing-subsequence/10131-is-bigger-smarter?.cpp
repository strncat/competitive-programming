//
//  main.cpp
//  uhunt
//
//  10131 - Is Bigger Smarter?
//  2017/03/30
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <math.h>
#include <queue>

using std::pair;
using std::string;
using std::vector;
using std::unordered_map;

typedef struct elephant {
    int weight;
    int iq;
    int index;
    elephant(int w, int iq, int index) {
        weight = w;
        this->iq = iq;
        this->index = index;
    }
} elephant;

void print(vector<elephant>& a, int *parent, int index) {
    if (index == -1) {
        return;
    }
    print(a, parent, parent[index]);
    printf("%d\n", a[index].index);
    //printf("%d %d\n", a[index].weight, a[index].iq);
}

void longest_increasing_subsequence(vector<elephant>& a) {
    int c[20000], parent[20000], max = 0, maxIndex = 0;

    // maximum subsequence ending at a[i] is initialy 1
    for (int i = 0; i < a.size(); i++) {
        c[i] = 1;
        parent[i] = -1; // parent array
    }

    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[i].weight > a[j].weight
                && a[i].iq < a[j].iq
                && c[i] < c[j] + 1) { // can extend
                c[i] = c[j] + 1;
                parent[i] = j;
            }
        }
        if (c[i] > max) { // maximum subsequence so far
            max = c[i];
            maxIndex = i;
        }
    }
    printf("%d\n", max);
    print(a, parent, maxIndex);
}

int compare(const elephant &a, const elephant &b) {
    return (a.weight < b.weight || (a.weight == b.weight && a.iq < b.iq));
}

int main() {
    //freopen("sample.in", "r", stdin);

    vector<elephant> a;
    int w, iq, n = 0;

    while (scanf("%d %d", &w, &iq) != EOF) {
        a.push_back(elephant(w, iq, n+1));
        n++;
    }
    std::sort(a.begin(), a.end(), compare);
    longest_increasing_subsequence(a);
    return 0;
}

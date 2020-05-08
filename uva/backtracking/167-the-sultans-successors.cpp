//
//  main.cpp
//  uhunt
//
//  167 - The Sultan's Successors
//  2017/02/28
//
//

#include <iostream>
#include <vector>

using std::vector;

const int N = 8;
int max = 0;

int is_a_solution(int *a, int k, int n) {
    return (k == n);
}

void construct_candidate(int *a, int k, int n, int *c, int *ncandidates) {
    for (int i = 1; i <= n; i++) {
        bool legal_move = true;
        for (int j = 1; j < k; j++) {
            if (a[j] == i) { // column threat
                legal_move = false;
            }
            if (abs(a[j] - i) == abs(j - k)) { // diagonal threat
                legal_move = false;
                break;
            }
        }
        if (legal_move == true) {
            c[(*ncandidates)++] = i;
        }
    }
}

int process_solution(int *a, int k, vector<vector<int>>& numbers) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += numbers[i-1][a[i]-1];
    }
    return sum;
}

void backtrack(int *a, int k, int size, vector<vector<int>>& numbers) {
    int c[N];
    int ncandidates = 0;

    if (is_a_solution(a, k, size)) {
        int sum = process_solution(a, k, numbers);
        if (sum > max) { max = sum; }
        return;
    }
    k = k + 1;
    construct_candidate(a, k, size, c, &ncandidates);
    for (int i = 0; i < ncandidates; i++) {
        a[k] = c[i];
        backtrack(a, k, size, numbers);
    }
}

void nqueens(int n, vector<vector<int>>& numbers) {
    int a[N+1];
    backtrack(a, 0, n, numbers);
    printf("%5d\n", max);
}

int main() {
    //freopen("sample.in", "r", stdin);
    int t, s;
    vector<vector<int>> numbers;
    scanf("%d", &t);
    while (t--) {
        max = 0;
        numbers.clear();
        for (int i = 0; i < N; i++) {
            numbers.push_back(vector<int>());
            for (int j = 0; j < N; j++) {
                scanf("%d", &s);
                numbers[i].push_back(s);
            }
        }
        nqueens(8, numbers);
    }
    return 0;
}
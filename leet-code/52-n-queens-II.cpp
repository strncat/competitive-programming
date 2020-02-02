class Solution {
public:
    int solutions = 0;

    bool is_valid(vector<int>& queens, int n, int x) {
        // only check up to queen x / row x
        // (1) not the same column placement
        for (int i = 0; i < x; i++) {
            if (queens[i] == queens[x]) {
                return false;
            }
        }
        // (2) diagonal check
        for (int i = 0; i < x; i++) {
            if (abs(queens[i] - queens[x]) == abs(i - x)) {
                return false;
            }
        }
        return true;
    }

    void place_queens(vector<int>& queens, int n, int x) {
        if (x == n) { // we placed all queens, valid solution
            solutions++;
            return;
        }
        // otherwise place queens
        for (int j = 0; j < n; j++) {
            // try placing the current queen in col i
            queens[x] = j;
            if (is_valid(queens, n, x)) {
                // place next queen;
                place_queens(queens, n, x+1);
            }
        }
        // no possible placement
        return;
    }
    int totalNQueens(int n) {
        vector<int> queens = std::vector<int>(n);
        place_queens(queens, n, 0);
        return solutions;
    }
};
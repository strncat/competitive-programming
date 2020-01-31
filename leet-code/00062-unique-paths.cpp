#define MAX 101
class Solution {
public:
    int uniquePaths(int m, int n) {
        int grid[101+1][101+1] = {0};
        for (int i = 0; i < 101; i++) {
            grid[1][i] = 1;
            grid[i][1] = 1;
        }
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m][n];
    }
    // recursive but TLE obviously
    //int uniquePaths(int m, int n) {
        //if (m == 1 || n == 1) { return 1; }
        //return uniquePaths(m-1,n) + uniquePaths(m,n-1);
    //}
};
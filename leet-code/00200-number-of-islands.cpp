class Solution {
public:
   
void bfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        std::queue<int> qi, qj;
        qi.push(i);
        qj.push(j);
        while (!qi.empty()) {
            int x = qi.front(); qi.pop();
            int y = qj.front(); qj.pop();
            
            if (x > 0 && grid[x-1][y] == '1') {
                grid[x-1][y] = '0';
                qi.push(x-1); qj.push(y);
            }
            
            if (x < n-1 && grid[x+1][y] == '1') {
                grid[x+1][y] = '0';
                qi.push(x+1); qj.push(y);
            }
            
            if (y > 0 && grid[x][y-1] == '1') {
                grid[x][y-1] = '0';
                qi.push(x); qj.push(y-1);
            }
            
            if (y < m-1 && grid[x][y+1] == '1') {
                grid[x][y+1] = '0';
                qi.push(x); qj.push(y+1);
            }
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.size() == 0) { return 0; }
        int n = grid.size();
        int m = grid[0].size();
        // find connected components
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    c++;
                    bfs(grid, i, j, n, m);
                }
            }
        }
        return c;
    }
};
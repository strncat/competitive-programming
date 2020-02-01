class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // m = n
        int layers = n/2;
        
        for (int layer = 0; layer < layers; layer++) {
            // in each layer we have n - 2*layer - 1 cells
            for (int i = 0; i < n - 2*layer - 1; i++) {
                int x = layer;
                int y = n - layer - 1;
                
                // rotate each cell / 4 corners
                int temp = matrix[x][x + i];
                matrix[x][x + i] = matrix[y - i][x];
                matrix[y - i][x] = matrix[y][y - i];
                matrix[y][y - i] = matrix[x + i][y];
                matrix[x + i][y] = temp;
            }
        }
    }
};

class Solution {
public:
// https://leetcode.com/problems/spiral-matrix/discuss/20599/Super-Simple-and-Easy-to-Understand-Solution
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
        return vector<int>();
    }

    vector<int> result;
    int start_row = 0;
    int end_row = matrix.size()-1;
    int start_col = 0;
    int end_col = matrix[0].size()-1;
    int direction = 0;

    while(start_row <= end_row && start_col <= end_col) {
        switch(direction) {
            case 0: // top row
                for (int col = start_col; col <= end_col; col++) {
                    result.push_back(matrix[start_row][col]);
                }
                start_row++;
                break;
            case 1: // right column
                for (int row = start_row; row <=end_row; row++) {
                    result.push_back(matrix[row][end_col]);
                }
                end_col--;
                break;
            case 2: // bottom row
                for (int col = end_col; col >= start_col; col--) {
                    result.push_back(matrix[end_row][col]);
                }
                end_row--;
                break;
            case 3: // left column
                for(int row = end_row; row >= start_row; row--) {
                    result.push_back(matrix[row][start_col]);
                }
                start_col++;
                break;
        }
        direction = (direction + 1) % 4;
    }
    return result;
}
};



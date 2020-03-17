class Solution {
public:
    void recursive(string s, int left, int right, vector<string>& solutions) {
        if (left == 0 && right == 0) {
            solutions.push_back(s);
            return;
        }
        if (left < right && right > 0) {
            recursive(s + ')', left, right-1, solutions);
        }
        if (left > 0) {
            recursive(s + '(', left-1, right, solutions);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> solutions;
        recursive(s, n, n, solutions);
        return solutions;
    }
};
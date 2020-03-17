class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void permute(vector<vector<int>>& solutions, vector<int>& nums, int index, int n) {
        if (index == n) {
            solutions.push_back(nums);
        }
        for (int i = index; i < n; i++) {
            swap(nums, i, index);
            permute(solutions, nums, index+1, n);
            swap(nums, i, index);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solutions;
        permute(solutions, nums, 0, nums.size());
        return solutions;
    }
};
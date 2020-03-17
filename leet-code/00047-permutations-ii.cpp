class Solution {
public:
    void permute(vector<vector<int>>& solutions, vector<int> nums, int index) {
        if (index == nums.size()-1) {
            solutions.push_back(nums);
            return;
        }
        int n = nums.size();
        for (int i = index; i < n; i++) {
            // (1) why allow i == index?
            // becase you want to pass down the original permutation
            // down ... suppose you're permuting {1,2,3} then the first
            // branch will continue passing {1,2,3} all the way to a leaf
            // you don't want to discard this one
            // (2) nums[i] != nums[i-1] to avoid actual dups
            if (i == index || nums[i] != nums[index]) {
                std::swap(nums[i], nums[index]);
                permute(solutions, nums, index+1);
                //swap(nums, i, index);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> solutions;
        permute(solutions, nums, 0);
        return solutions;
    }
};
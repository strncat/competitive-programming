class Solution {
public:
    vector<vector<int>> solutions;
    void twoSum(vector<int>& nums, int target, int index) {
        int left = index, right = nums.size()-1;
        while (left < right) {
            if (nums[left]+nums[right] == target) {
                vector<int> indices;
                indices.push_back(-target);
                indices.push_back(nums[left]);
                indices.push_back(nums[right]);
                solutions.push_back(indices);
                
                left++;
                right--;
                
                // ensure no dups!
                while (left < right && nums[left-1] == nums[left]) {
                    left++;
                }
                
            } else if (nums[left]+nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue; // dup
            }
            // we will check if we can find two elements
            // that sum to -nums[i]. To do so, we will
            // start the lookup at index i+1 (proof?)
            twoSum(nums, -nums[i], i+1);
        }
        return solutions;
    }
};
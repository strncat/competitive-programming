// just like partition from quicksort!
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                std::swap(nums[write_index++], nums[i]);
            }
        }
    }
};
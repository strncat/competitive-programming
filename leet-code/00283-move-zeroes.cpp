class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int write_index = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[write_index++] = nums[i];
            }
        }
        for (int j = write_index; j < n; j++) {
            nums[j] = 0;
        }
    }
};
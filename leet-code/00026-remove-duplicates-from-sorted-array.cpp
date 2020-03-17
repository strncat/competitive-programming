class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        int n = nums.size();
        int i = 0;
        // ughhh this idea of keeping a pointer pointing
        // at the so far "good" array without dups and then
        // just iterating and only taking unique elements
        for (int j = 0; j < n; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
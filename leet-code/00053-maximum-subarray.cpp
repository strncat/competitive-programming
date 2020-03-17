class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) { return 0; }

        int sum = 0;
        int best_sum = INT_MIN;
        int max = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum > best_sum) {
                best_sum = sum;
            }

            // whenever the sum drops below zero, reset it
            if (sum < 0) {
                sum = 0;
            }
            
            // handle negative numbers, for negative numbers, it's just the max
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        
        // no positive numbers, return highest negative
        if (max < 0) {
            return max;
        }
        
        return best_sum;
    }
};
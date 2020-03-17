class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue <int, vector<int>, greater<int>> q; // min heap
        // insert k elements from nums
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        
        // we keep only k elements at all times in the heap
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }
        
        return q.top();
    }
};
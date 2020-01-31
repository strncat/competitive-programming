class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // key observation: nums[i] != nums[i+1]
        // also: nums[i-1]=nums[n]=-infty
        // this means WE MUST have a local maxima if not global
        // forexample suppose we have -infty -1 2 -3 -5 ... -infty 
        // then 2 is a peak!
        // therefore, just follow the upward direction, since again
        // nums[i]!=num[-i] so we're either going up or down!
        // we check the right neighbor in a binary search
        // if we're going downard, we go left, if we're going upward we go right
        
        int first = 0;
        int last = nums.size()-1;
        
        while (first < last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] > nums[mid+1]) {
                last = mid;
            } else {
                first = mid + 1;
            }
        }
        return first;
    }
};
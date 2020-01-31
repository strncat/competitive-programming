class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // no duplicates so we're guaranteed to have 
            // mid less than or greater than both ends
            
            // case 1: right half is sorted
            if (nums[mid] < nums[left]) {
                // target is in the sorted half
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                // target is in the broken left half
                } else {
                    right = mid - 1;
                }
            } else {
                // target is in the sorted half
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                // target is in the broken right half
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
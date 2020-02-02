// longer solution but pretty easy to understand
class Solution {
public:
    int find_first(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int first = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // if we arrive at target, then we record that position
            // and go left to see if we can find an earlier match
            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return first;
    }

    int find_last(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // if we arrive at target, then we record that position
            // and go right to see if we can find a later match
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> positions;
        positions.push_back(find_first(nums, target));
        positions.push_back(find_last(nums, target));
        return positions;        
    }
};
class Solution {
public:
    /* Pointers Approach */
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) { return 0; }
        
        // at any point during the scan, the amount of water
        // trapped depends either on the left wall or the right
        // wall, in fact it dopends on the minimum of both
    
        int total_rain = 0;
        int left = 0, left_max = 0;
        int right = n-1, right_max = 0;
        
        while (left < right) {
            // the left wall is lower
            if (height[left] < height[right]) {
                // if this wall is higher than the current left max
                // then we just update the left_max
                if (height[left] > left_max) {
                    left_max = height[left];
                } else {
                    // we have trapped water
                    total_rain += left_max - height[left];
                }
                left++;
            // the right wall is lower
            } else {
                if (height[right] > right_max) {
                    right_max = height[right];
                } else {
                    // we have trapped water
                    total_rain += right_max - height[right]; 
                }
                right--;
            }
        }
        return total_rain;
    }
    /* DP Approach */
    /*
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) { return 0; }
        
        // find the max height coming from the left up to index i
        vector<int> left_max = vector<int>(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = std::max(left_max[i-1], height[i]);
        }
        
        // find the max height coming from the right up to index i
        vector<int> right_max = vector<int>(n);
        right_max[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            right_max[i] = std::max(right_max[i+1], height[i]);
        }
        
        // the trapped water is the min of both heights 
        // minus the current height
        int total_trapped_water = 0;
        for (int i = 0; i < n; i++) {
            total_trapped_water += std::min(right_max[i], left_max[i]) - height[i];
        }
        
        return total_trapped_water;
    }
    */
};
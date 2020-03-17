class Solution {
public:
    // bit vector method, just generate all binary numbers 0 to 2^size
    // each binary number represents a set
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> s;
        int total_subsets = 1 << nums.size();
        for (int i = 0; i < total_subsets; i++) {
            // we generate a subset based on the turned on bits in i
            int index = 0; // index in nums
            vector<int> subset;
            for (int j = i; j > 0; j = j >> 1) {
                if (j & 1) {
                    subset.push_back(nums[index]);
                }
                index++;
            }
            s.push_back(subset);
        }
        return s;
    }
    /*
    void helper(vector<int>& nums, int index, vector<vector<int>>& s) {
        if (index == nums.size()) {
            return;
        }
        // for each subset in s, we clone it and add s to it and add the clone to s.
        // This simulates the idea of either adding the element at index or we're not.
        // two choices for each element
        // (1) include this element in ->
        // (2) don't include this element in ->
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // we clone each subset
            vector<int> copy = s[i];
            copy.push_back(nums[index]);
            s.push_back(copy);
        }
        return helper(nums, index+1, s);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> s;
        // add the empry set;
        vector<int> empty = {};
        s.push_back(empty);
        helper(nums, 0, s);
        return s;
    }
    */
};

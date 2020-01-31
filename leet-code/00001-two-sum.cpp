class Solution {
public:
    std::unordered_map<int,int> m;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                indices.push_back(i);
                indices.push_back(m[target-nums[i]]);
                return indices;
            }
            m[nums[i]] = i;
        }
        return indices;
    }
};
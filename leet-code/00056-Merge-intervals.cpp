class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) { return vector<vector<int>>(); }
        
        std::sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
          });
        
        std::vector<vector<int>> merged;
        merged.push_back(intervals[0]);
                
        // merge intervals
        // 
        int cur = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= merged[cur][1]) {
                merged[cur][1] = std::max(merged[cur][1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
                cur++;
            }
        }
        
        return merged;
        
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            // sort the string
            string s = strs[i];
            std::sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        }
        
        for (auto i = map.begin(); i != map.end(); i++) {
            result.push_back(i->second);
        }
        
        return result;
    }
};
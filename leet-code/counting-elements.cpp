class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_map<int,bool> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]] = true;
        } 
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (m.find(arr[i]+1) != m.end()) {
                count++;
            }
        }
        return count;
    }
};
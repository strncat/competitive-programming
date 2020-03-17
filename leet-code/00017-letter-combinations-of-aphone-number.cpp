class Solution {
public:
    std::unordered_map<char, string> m;

    void place(string& digits, string s, vector<string>& solutions, int index) {
        if (index == digits.length()) { // done
            solutions.push_back(s);
            return;
        }
        // otherwise continue placing possible letters
        string cur_digits = m[digits[index]];
        for (int i = 0; i < cur_digits.size(); i++) {
            s[index] = cur_digits[i];
            place(digits, s, solutions, index+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) { return vector<string>(); }
        m['2'] = "abc"; m['3'] = "def"; m['4'] = "ghi"; m['5'] = "jkl";
        m['6'] = "mno"; m['7'] = "pqrs"; m['8'] = "tuv"; m['9'] = "wxyz";
        
        int index = 0;
        vector<string> solutions;
        string s(digits.size(),0);
        place(digits, s, solutions, 0);
        return solutions;
    }
};
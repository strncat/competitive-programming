// stupid problem, what's the point?
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.",
            "--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
            "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        std::unordered_set<string> s;
        for (int w = 0; w < words.size(); w++) {
            string r;
            for (int i = 0; i < words[w].length(); i++) {
                r += morse[words[w][i]-'a'];
            }
            s.insert(r);
        }
        return s.size();
    }
};
class Solution {
public:
    bool isHappy(int n) {
        int squares[11] = {0,1,4,9,16,25,36,49,64,81,100};
        std::unordered_map<int,bool> m;

        while (1) {
            int t = 0;
            while (n) {
                t += squares[n%10];
                n /= 10;
            }
            // happy number
            if (t == 1) { return 1; }
            // cycle test
            if (m[t] == true) { return false; }
            
            // repeat
            m[t] = true;
            n = t;
        }
        return false;
    }
};
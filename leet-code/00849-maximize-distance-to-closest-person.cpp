// 849. Maximize Distance to Closest Person
// google mock 

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int counter = 0;
        int max_mid = 0;
        int max_begin = 0;
        int max_end = 0;
        int i = 0;
        
        // case 1: empty seats at the beginning of the row
        // this will just be the number of empty seats
        while (i < seats.size() && seats[i] == 0) {
            max_begin++;
            i++;
        }
        
        // case 2: longest stretch is in the middle 
        for (; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (counter > max_mid) {
                    max_mid = counter;
                }
                counter = 0;
            } else {
                counter++;
            }
        }
        
        if (max_mid & 1) { // odd
            max_mid = max_mid/2 + 1;
        } else {
            max_mid = max_mid/2;
        }

        // case 3: last seat is empty
        if (seats[i-1] == 0) {
            max_end = counter;
        }
        
        
        return std::max(std::max(max_begin, max_end), max_mid);     
    }
};
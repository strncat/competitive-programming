// really bad problem
class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        if (n == 0) { return 0; }
        bool negative = false;
        int index = 0;

        // skip whitespaces and handle the negative sign
        // if we see a non-number at this point, we return false
        while (index < n) {
            if (str[index] == '-') {
                index++;
                negative = true;
                break;
            } else if (str[index] == '+') {
                index++;
                break;
            } else if (str[index] == ' ') {
                index++;
            } else if (str[index] < '0' || str[index] > '9') {
                return false;
            } else {
                break;
            }
        }
        
        // otherwise we conitnue parsing
        long total = 0;
        while (index < n) {
            if (str[index] < '0' || str[index] > '9') {
                break; // done
            }
            
            // above limits, exit
            if (total > INT_MAX) {
                return negative ? INT_MIN : INT_MAX;
            }
            
            // otherwise, continue parsing
            total *= 10;
            total += (str[index] - '0');
            index++;
        }
        
                    if (total > INT_MAX) {
                return negative ? INT_MIN : INT_MAX;
            }

        return negative ? -1*total : total;
    }
};
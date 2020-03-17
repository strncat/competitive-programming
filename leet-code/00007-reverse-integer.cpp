class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        while (x) {
            // overflow check
            if (INT_MAX/10 < reversed || INT_MIN/10 > reversed) { 
                return 0; 
            }
    
            reversed = 10*reversed + x%10;
            x = x/10;
        }
        return reversed;
    }
};
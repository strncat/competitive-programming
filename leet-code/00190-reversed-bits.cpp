class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        for (int i = 0; i < 32; i++) {
            reversed <<= 1; // reversed = reversed*2
            //reversed |= n & 1;
            if (n & 1) {
                reversed = reversed | 1;
            }
            n >>= 1; // n=n/2
        }
        return reversed;
    }
    /* naive
    uint32_t reverseBits(uint32_t n) {
        int bits[32] = {0};
        int i = 0;
        while (n) {
            bits[i++] = n & 1;
            n = n >> 1;
        }
        
        uint32_t reversed = 0;
        uint32_t m = 1;
        for (int i = 31; i >= 0; i--) {
            reversed += bits[i]*m;
            m *= 2;
        }
        return reversed;
    }
    */
};
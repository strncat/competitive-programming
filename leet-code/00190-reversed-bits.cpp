class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++) { // need to iterate over ALL bits
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }
        return result;
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

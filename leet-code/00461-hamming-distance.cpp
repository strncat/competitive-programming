class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int counter = 0;
        while (res) {
            counter++;
            res = res & (res - 1);
        }
        return counter;
    }
};
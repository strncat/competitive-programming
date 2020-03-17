class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) { return 0; }
        vector<bool> prime = vector<bool>(n, true);
        prime[0] = false;
        prime[1] = false;
        int limit = sqrt(n) + 1;
        int count = 0;

        for (int i = 2; i < limit; i++) {
            if (prime[i]) {
                for (int j = i+i; j < n; j+=i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (prime[i]) { count++; }
        }

        return count;
    }
};
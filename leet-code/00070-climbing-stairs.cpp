// Suppose we know the number of ways to climb 1...n-1 stairs
// What does this tell us about the number of ways to climb n stairs?
// We know we can either climb 1 or 2 steps
// If we take dp[n-1] and climb 1 step, this will contribute to the number of ways to climb n stairs
// Similarly, if we take dp[n-2] and climb 2 steps, this will contribute to the number of ways to climb n stairs
// We can then add them together and return that number
// Notice here that the problem isn't asking for the "minimum" or "maximum" number of steps so we're not choosing between the two paths
// Notice here that we are count duplicate ways to reach n steps and that's okay
// for this problem. Climbing 1 then 2 steps is different from climbing 2 then 1 steps.
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        dp.push_back(2);
        for (int i = 3; i <= n; i++) {
            dp.push_back(dp[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};
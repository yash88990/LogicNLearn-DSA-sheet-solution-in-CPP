class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        int countB = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                // Either delete this 'a' (dp[i-1] + 1) or keep it (countB)
                dp[i] = (i == 0 ? 0 : min(dp[i-1] + 1, countB));
            } else {
                // 'b' character, no need to delete it, just carry forward the previous deletions
                dp[i] = (i == 0 ? 0 : dp[i-1]);
                countB++;
            }
        }
        
        return dp[n-1];
    }
};
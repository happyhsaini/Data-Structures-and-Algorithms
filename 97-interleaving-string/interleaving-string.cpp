
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (n + m != s3.size()) return false;

        vector<bool> dp(m + 1, false);
        dp[0] = true;

        for (int j = 1; j <= m; j++) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];

            for (int j = 1; j <= m; j++) {
                char c = s3[i + j - 1];

                dp[j] = (dp[j] && s1[i - 1] == c) ||
                         (dp[j - 1] && s2[j - 1] == c);
            }
        }

        return dp[m];
    }
};

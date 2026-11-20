#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSelectedElements(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        // dp[v] = max length of a consecutive sequence ending at value v
        int max_val = nums.back();
        std::vector<int> dp(max_val + 2, 0);
        int ans = 0;

        for (int x : nums) {
            // Update x + 1 BEFORE x so the current element isn't used twice
            dp[x + 1] = std::max(dp[x + 1], dp[x] + 1);
            dp[x] = std::max(dp[x], dp[x - 1] + 1);
            
            ans = std::max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};
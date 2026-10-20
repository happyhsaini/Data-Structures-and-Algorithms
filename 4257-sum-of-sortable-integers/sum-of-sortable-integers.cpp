#include <vector>
using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int prev_max = -1; // Tracks the maximum element of the previous block

            for (int start = 0; start < n; start += k) {
                int drops = 0;
                int drop_idx = -1;

                // Count internal drops within the current subarray of length k
                for (int i = start; i < start + k - 1; i++) {
                    if (nums[i] > nums[i + 1]) {
                        drops++;
                        drop_idx = i;
                    }
                }

                int cur_min, cur_max;

                if (drops == 0) {
                    // Already sorted
                    cur_min = nums[start];
                    cur_max = nums[start + k - 1];
                } else if (drops == 1 && nums[start + k - 1] <= nums[start]) {
                    // Can be sorted by cyclic rotation
                    cur_min = nums[drop_idx + 1];
                    cur_max = nums[drop_idx];
                } else {
                    // Cannot be sorted by cyclic rotation
                    ok = false;
                    break;
                }

                // Current block's minimum must be >= previous block's maximum
                if (cur_min < prev_max) {
                    ok = false;
                    break;
                }
                prev_max = cur_max;
            }

            if (ok) ans += k;
        }

        return ans;
    }
};
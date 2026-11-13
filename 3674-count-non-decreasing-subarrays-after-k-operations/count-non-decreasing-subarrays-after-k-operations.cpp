#include <vector>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Prefix sums to quickly calculate the sum of original elements in O(1)
        vector<long long> pref_nums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref_nums[i + 1] = pref_nums[i] + nums[i];
        }
        
        // st_idx stores the starting index of each prefix maximum block
        vector<int> st_idx;
        // st_area stores the cumulative sum of the "prefix max areas" from the bottom of the stack
        vector<long long> st_area;
        
        // Helper lambda to calculate the minimum operations to make nums[L...R] non-decreasing
        auto get_cost = [&](int L, int R) -> long long {
            int low = 0, high = (int)st_idx.size() - 1;
            int j = -1;
            
            // Binary search to find which prefix-max block R falls into
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (st_idx[mid] <= R) {
                    j = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            long long prefix_max_sum = 0;
            int m = st_idx.size();
            
            // Add full blocks extending up to block j
            if (j < m - 1) {
                prefix_max_sum += st_area[m - 1] - st_area[j];
            }
            // Add the partial area within block j up to R
            prefix_max_sum += 1LL * nums[st_idx[j]] * (R - st_idx[j] + 1);
            
            long long original_sum = pref_nums[R + 1] - pref_nums[L];
            
            return prefix_max_sum - original_sum;
        };
        
        long long ans = 0;
        int R = n - 1;
        
        // Process L from right to left
        for (int L = n - 1; L >= 0; --L) {
            // Maintain a strictly descending monotonic stack
            while (!st_idx.empty() && nums[st_idx.back()] <= nums[L]) {
                st_idx.pop_back();
                st_area.pop_back();
            }
            
            int m = st_idx.size();
            // Length of the block that nums[L] will dominate
            long long block_len = (m == 0 ? n : st_idx.back()) - L;
            long long area = 1LL * nums[L] * block_len;
            
            st_idx.push_back(L);
            st_area.push_back((m == 0 ? 0 : st_area.back()) + area);
            
            // Shrink the right boundary until the required operations are <= k
            while (R >= L && get_cost(L, R) > k) {
                R--;
            }
            
            // All subarrays starting at L and ending between L and R are valid
            ans += (R - L + 1);
        }
        
        return ans;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr, long long val) -> void {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                sq[node] = (sq[node] + 2 * val * sum[node] % MOD
                            + (r - l + 1LL) * val % MOD * val) % MOD;
                sum[node] = (sum[node] + (r - l + 1LL) * val) % MOD;
                lazy[node] = (lazy[node] + val) % MOD;
                return;
            }

            int mid = (l + r) / 2;

            if (lazy[node]) {
                long long v = lazy[node];

                sq[node * 2] = (sq[node * 2]
                    + 2 * v * sum[node * 2] % MOD
                    + (mid - l + 1LL) * v % MOD * v) % MOD;
                sum[node * 2] = (sum[node * 2]
                    + (mid - l + 1LL) * v) % MOD;
                lazy[node * 2] = (lazy[node * 2] + v) % MOD;

                sq[node * 2 + 1] = (sq[node * 2 + 1]
                    + 2 * v * sum[node * 2 + 1] % MOD
                    + (r - mid) * v % MOD * v) % MOD;
                sum[node * 2 + 1] = (sum[node * 2 + 1]
                    + (r - mid) * v) % MOD;
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + v) % MOD;

                lazy[node] = 0;
            }

            self(self, node * 2, l, mid, ql, qr, val);
            self(self, node * 2 + 1, mid + 1, r, ql, qr, val);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            update(update, 1, 0, n - 1, last[x] + 1, i, 1);

            ans = (ans + sq[1]) % MOD;
            last[x] = i;
        }

        return ans;
    }
};

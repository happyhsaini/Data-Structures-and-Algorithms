#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findSubtreeSizes(std::vector<int>& parent, std::string s) {
        int n = parent.size();
        std::vector<std::vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        std::vector<int> ans(n, 1);
        std::vector<int> last_seen(26, -1);

        auto dfs = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev_ancestor = last_seen[c];
            
            // Determine the new parent of u based on the closest matching ancestor
            int new_parent = (prev_ancestor != -1) ? prev_ancestor : parent[u];

            // Mark u as the closest ancestor for character s[u] for its descendants
            last_seen[c] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            // Backtrack: restore the previous closest ancestor
            last_seen[c] = prev_ancestor;

            // Add u's finalized subtree size to its new parent
            if (new_parent != -1) {
                ans[new_parent] += ans[u];
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};
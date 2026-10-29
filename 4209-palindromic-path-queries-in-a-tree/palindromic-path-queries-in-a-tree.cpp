
class Solution {
public:
    vector<vector<int>> adj, up;
    vector<int> tin, tout, bit, mask, depth;
    int timer, LOG;

    void update(int i, int val, int n) {
        while (i <= n) {
            bit[i] ^= val;
            i += i & -i;
        }
    }

    int queryBIT(int i) {
        int ans = 0;
        while (i > 0) {
            ans ^= bit[i];
            i -= i & -i;
        }
        return ans;
    }

    void rangeUpdate(int l, int r, int val, int n) {
        update(l, val, n);
        if (r + 1 <= n)
            update(r + 1, val, n);
    }

    void dfs(int u, int p, string &s) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++) {
            int prev = up[u][j - 1];
            up[u][j] = (prev == -1 ? -1 : up[prev][j - 1]);
        }

        mask[u] = 1 << (s[u] - 'a');

        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, s);
            }
        }

        tout[u] = timer;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int j = LOG - 1; j >= 0; j--) {
            int a = up[u][j];
            if (a != -1 && !isAncestor(a, v))
                u = a;
        }

        return up[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        adj.assign(n, {});

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, -1));
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        mask.resize(n);
        bit.assign(n + 2, 0);
        timer = 0;

        dfs(0, -1, s);

        // Store root-to-node XOR using subtree range updates.
        for (int u = 0; u < n; u++) {
            rangeUpdate(tin[u], tout[u], mask[u], n);
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                rangeUpdate(tin[u], tout[u], delta, n);

                mask[u] = newMask;
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int pathMask = queryBIT(tin[u])
                             ^ queryBIT(tin[v])
                             ^ mask[w];

                ans.push_back(
                    __builtin_popcount((unsigned int)pathMask) <= 1
                );
            }
        }

        return ans;
    }
};

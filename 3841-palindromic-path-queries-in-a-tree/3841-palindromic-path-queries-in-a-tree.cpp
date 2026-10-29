
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        
        void add(int idx, int val) {
            for (; idx <= n; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        }

        
        int query(int idx) {
            int result = 0;
            for (; idx > 0; idx -= idx & -idx) {
                result ^= bit[idx];
            }
            return result;
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n), euler(n);

        int timer = 0;

        
        vector<tuple<int, int, int>> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = timer;
                euler[timer++] = u;

                up[0][u] = p;

                st.push_back({u, p, 1});

                for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];

                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
               
                tout[u] = timer;
            }
        }

       
        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }

        auto charMask = [&](char c) -> int {
            return 1 << (c - 'a');
        };

        
        vector<int> pref(n, 0);

        for (int i = 0; i < n; i++) {
            int u = euler[i];

            if (u == 0) {
                pref[u] = charMask(s[u]);
            } else {
                pref[u] = pref[up[0][u]] ^ charMask(s[u]);
            }
        }

        
        Fenwick fw(n);

        for (int i = 0; i < n; i++) {
            int u = euler[i];
            int prev = (i == 0 ? 0 : pref[euler[i - 1]]);
            fw.add(i + 1, pref[u] ^ prev);
        }

        auto getPrefix = [&](int u) -> int {
            return fw.query(tin[u] + 1);
        };

        auto lca = [&](int u, int v) -> int {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    u = up[j][u];
                }
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (const string& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            char c;

            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int delta = charMask(s[u]) ^ charMask(c);

                if (delta != 0) {
                   
                    fw.add(tin[u] + 1, delta);

                    if (tout[u] < n) {
                        fw.add(tout[u] + 1, delta);
                    }

                    s[u] = c;
                }
            } else {
                ss >> v;

                int w = lca(u, v);

                int mask = getPrefix(u)
                         ^ getPrefix(v)
                         ^ charMask(s[w]);

                
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};

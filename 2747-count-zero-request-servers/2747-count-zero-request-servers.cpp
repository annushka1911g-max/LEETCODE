class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                            int x, vector<int>& queries) {

        int m = queries.size();

        
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        
        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m, 0);

       
        unordered_map<int, int> freq;

        int left = 0, right = 0;
        int inactive = n;

        for (auto &[time, idx] : q) {

            
            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];

                if (freq[server] == 0) {
                    inactive--;
                }

                freq[server]++;
                right++;
            }

            
            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    inactive++;
                }

                left++;
            }

            ans[idx] = inactive;
        }

        return ans;
    }
};
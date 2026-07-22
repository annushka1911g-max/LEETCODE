class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, int target,
             vector<int>& path, int start) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            if (candidates[i] > target)
                continue;

            path.push_back(candidates[i]);

            dfs(candidates, target - candidates[i], path, i);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, target, path, 0);
        return ans;
    }
};
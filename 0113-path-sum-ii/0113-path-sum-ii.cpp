class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int remaining, vector<int>& path) {

        if (root == nullptr)
            return;

        // Add current node
        path.push_back(root->val);

        remaining -= root->val;

        // Check if leaf and required sum is achieved
        if (root->left == nullptr &&
            root->right == nullptr &&
            remaining == 0) {

            ans.push_back(path);
        }

        // Explore left subtree
        dfs(root->left, remaining, path);

        // Explore right subtree
        dfs(root->right, remaining, path);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> path;

        dfs(root, targetSum, path);

        return ans;
    }
};
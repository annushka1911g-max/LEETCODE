class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* root, string path) {
        if (root == nullptr)
            return;

        path += to_string(root->val);

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        path += "->";

        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
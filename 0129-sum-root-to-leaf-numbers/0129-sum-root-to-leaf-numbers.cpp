class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (root == nullptr)
            return 0;

        current = current * 10 + root->val;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr)
            return current;

        return dfs(root->left, current) +
               dfs(root->right, current);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
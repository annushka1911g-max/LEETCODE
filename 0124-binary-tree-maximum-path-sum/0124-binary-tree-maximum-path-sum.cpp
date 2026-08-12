class Solution {
public:
    int ans = INT_MIN;

    int solve(TreeNode* root) {
        // Base case
        if (root == NULL)
            return 0;

        // Bottom-up: first solve children
        int left = solve(root->left);
        int right = solve(root->right);

        // Ignore negative paths
        left = max(0, left);
        right = max(0, right);

        // Maximum path passing through current node
        int current = root->val + left + right;

        // Update overall answer
        ans = max(ans, current);

        // Return best single path to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
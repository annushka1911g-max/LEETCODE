class Solution {
public:

    bool isMirror(TreeNode* left, TreeNode* right) {

        // Both nodes are NULL
        if (left == nullptr && right == nullptr) {
            return true;
        }

        // Only one node is NULL
        if (left == nullptr || right == nullptr) {
            return false;
        }

        // Values are different
        if (left->val != right->val) {
            return false;
        }

        // Check mirror subtrees
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};
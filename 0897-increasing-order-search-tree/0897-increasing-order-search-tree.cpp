class Solution {
public:
    TreeNode* curr;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);

        root->left = nullptr;
        curr->right = root;
        curr = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        curr = dummy;

        inorder(root);

        return dummy->right;
    }
};
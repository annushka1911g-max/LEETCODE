class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});

        while (!que.empty()) {

            auto [a, b] = que.front();
            que.pop();

            if (a == nullptr && b == nullptr)
                continue;

            if (a == nullptr || b == nullptr)
                return false;

            if (a->val != b->val)
                return false;

            que.push({a->left, b->left});
            que.push({a->right, b->right});
        }

        return true;
    }
};
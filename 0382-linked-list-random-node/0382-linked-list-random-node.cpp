class Solution {
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int ans = head->val;
        ListNode* curr = head->next;

        int i = 2;

        while (curr != nullptr) {
            // Probability = 1/i
            if (rand() % i == 0) {
                ans = curr->val;
            }

            curr = curr->next;
            i++;
        }

        return ans;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>vals;
        ListNode* temp=list1;
        while(temp !=nullptr)
        {
            vals.push_back(temp->val);
            temp=temp->next;
        }
        temp=list2;
        while(temp!=nullptr)
        {
            vals.push_back(temp->val);
            temp= temp->next;
        }
        sort(vals.begin(),vals.end());
        ListNode* dummy= new ListNode(-1);
        ListNode* tail=dummy;
        for(int v : vals){
            tail->next=new ListNode(v);
            tail=tail->next;
        }
        return dummy->next;
        
    }
};
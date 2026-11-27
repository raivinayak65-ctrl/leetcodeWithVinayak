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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        ListNode * curr = head;
        ListNode * prev = head;
        while(curr)
        {
            if(head->val==val)
            {
                head=head->next;
            }
            if(curr->val == val)
            {
                prev->next = curr->next;
                curr=prev->next;
                continue;
            }
            prev=curr;
            curr=curr->next;
        }
        return head;

    }
};
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
    ListNode* swapPairs(ListNode* head) {
        if(head != nullptr && head->next == nullptr) return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;

        // to maintain the contineuty of the linked list we took prev 
        ListNode * prev = dummy;
    
        while (prev->next && prev->next->next){

            ListNode * first = prev->next;
            ListNode * sec = prev->next->next;

            first->next = sec->next;
            sec->next = first;
            prev->next = sec;

            prev = first; //connecting to the first to move on the next iteration

        }
        ListNode * curr = dummy;
        while (curr)
        {
            cout<<curr->val<<" ";
            curr= curr->next;
        }
        return dummy->next;
    }
};
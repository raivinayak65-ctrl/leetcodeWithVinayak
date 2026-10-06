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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * curr = head;
        int count = 0;
        while(curr)
        {
            count++;
            curr= curr->next;
        }
        if (count == n)
        {
            return head->next;
        }
        int pos = count-n+1 , i = 0;
        curr = head;
        ListNode *prev = nullptr;
        while (curr && i<pos-1 )
        {
            i++;
            prev = curr;
            curr = curr->next;
        }
        ListNode * temp = curr->next;
        delete curr;
        prev->next = temp;
        ListNode * head1 = head;
        
        return  head;
    }
};
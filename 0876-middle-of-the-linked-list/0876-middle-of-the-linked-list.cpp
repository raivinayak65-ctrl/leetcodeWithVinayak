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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;

        int count =0 ;
        ListNode * curr = head;
        while(curr)
        {
            curr = curr->next;
            count++;
        }
        curr = head;
        int n = 0;
        (count % 2 == 0) ? n = (count / 2) + 1 : n = (count/2)+1;
        count = 1;
        while(curr)
        {
            if (count == n)
            {
                break;
            }
            curr = curr->next;
            count++;
        }
        return curr;
    }
};
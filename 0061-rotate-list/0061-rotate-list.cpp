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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head-> next == nullptr){
            return head;
        }
        ListNode * curr = head;
        ListNode * newHead = nullptr;
        int count = 1;

        while(curr ->next !=nullptr)
        {
            count++;
            curr = curr->next;
        }

        // to handle if the given pos == first or the last one 
        k = k % count;
        if (k == 0) return head;

        curr->next = head;
        
        ListNode * newTail = head;
        for(int i =0;i<count-k-1;i++)
        {
            newTail = newTail->next;
        }
        newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
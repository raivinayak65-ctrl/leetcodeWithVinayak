/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
        return nullptr;

        ListNode * lista = headA;
        ListNode * listb = headB;

        while(lista != listb)
        {
            if(lista != nullptr)
            {
                lista = lista->next;
            }
            else
            lista = headB;

            if(listb != nullptr)
            {
                listb = listb->next;
            }
            else
            listb = headA;
        }
        return listb;
    }
};
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode *vOddHead = new ListNode(0);
        ListNode *vEvenHead = new ListNode(0);
        
        ListNode* oddTail = vOddHead;
        ListNode* evenTail = vEvenHead;
        
        ListNode* itr = head;
        while (itr != NULL) {
            oddTail->next = itr; // odd
            oddTail = itr;
            itr = itr->next;
            
            if (itr != NULL) { // even
                evenTail->next = itr;
                evenTail = itr;
                itr = itr->next;
            }
        }
        
        evenTail->next = NULL;
        
        oddTail->next = vEvenHead->next;
        ListNode *rHead = vOddHead->next;
        delete vOddHead;
        delete vEvenHead;
        
        return rHead;
    }
};
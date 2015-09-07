#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if (headA == NULL || headB == NULL)
    		return NULL;

        ListNode* aPtr = headA;
        ListNode* bPtr = headB;

        while (aPtr != NULL && bPtr != NULL) {
        	aPtr = aPtr->next;
        	bPtr = bPtr->next;
        }

        ListNode* lPtr;
        ListNode* lHead;
        ListNode* sHead;

        if (aPtr != NULL) {
        	lPtr = aPtr;
        	lHead = headA;
        	sHead = headB;
        } else {
        	lPtr = bPtr;
        	lHead = headB;
        	sHead = headA;
        }

        while (lPtr != NULL) {
        	lPtr = lPtr->next;
        	lHead = lHead->next;
        }

        while (sHead != NULL && sHead != lHead) {
        	sHead = sHead->next;
        	lHead = lHead->next;
        }

        return sHead;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(3);

	ln1.next = &ln2;
	ln2.next = &ln3;

	ListNode* rel = solution.getIntersectionNode(&ln1, &ln1);

	cout << rel->val << endl;
	return 0;
}
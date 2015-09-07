#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptrL1 = l1;
        ListNode* ptrL2 = l2;

        ListNode aux(0);
        ListNode* tail = &aux;

        while (ptrL1 != NULL && ptrL2 != NULL) {
        	ListNode** small = &ptrL1;

        	if (ptrL1->val > ptrL2->val) {
        		small = &ptrL2;
        	}

    		tail->next = *small;
    		tail = *small;
    		*small = (*small)->next;
        }

    	if (ptrL1 != NULL) {
    		tail->next = ptrL1;
    	} else {
    		tail->next = ptrL2;
    	}

        return aux.next;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode ln1_1(1);
	ListNode ln1_2(4);
	ListNode ln1_3(8);

	ln1_1.next = &ln1_2;
	ln1_2.next = &ln1_3;

	ListNode ln2_1(2);
	ListNode ln2_2(4);
	ListNode ln2_3(7);

	ln2_1.next = &ln2_2;
	ln2_2.next = &ln2_3;

	ListNode* head = solution.mergeTwoLists(&ln1_1, &ln2_1);

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	
	return 0;
}
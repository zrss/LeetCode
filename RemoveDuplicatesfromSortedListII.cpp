#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;

        while (cur != NULL) {
        	if (cur->next != NULL && cur->val == cur->next->val) {
        		do {
        			cur->next = cur->next->next;
        		} while (cur->next != NULL && cur->val == cur->next->val);

        		if (pre != NULL) {
        			pre->next = cur->next;
        		} else {
        			head = cur->next;
        		}
        	} else {
        		pre = cur;
        	}

        	cur = cur->next;
        }

        return head;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	ListNode ln1(1);
	ListNode ln2(1);
	ListNode ln3(1);
	ListNode ln4(2);
	ListNode ln5(3);

	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ln4.next = &ln5;

	ListNode* head = solution.deleteDuplicates(&ln1);

	while (head != NULL) {
		cout << head->val << " ";
        head = head->next;
	}
	cout << endl;

	return 0;
}
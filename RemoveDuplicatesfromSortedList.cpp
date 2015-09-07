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
    	while (cur != NULL) {
    		if (cur->next != NULL && cur->val == cur->next->val) {
    			cur->next = cur->next->next;
    		} else {
    			cur = cur->next;
    		}
    	}
    	return head;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode ln1(1);
	ListNode ln2(1);
	ListNode ln3(1);

	ln1.next = &ln2;
	ln2.next = &ln3;

	ListNode* head = solution.deleteDuplicates(&ln1);

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
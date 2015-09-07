#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n - 1; ++i) {
        	fast = fast->next;
        }

        ListNode* pre = NULL;

        while (fast->next != NULL) {
        	fast = fast->next;
        	pre = slow;
        	slow = slow->next;
        }

        if (pre != NULL) { // head
        	pre->next = pre->next->next;
        } else {
        	return head->next;
        }

        return head;
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

	ListNode* head = solution.removeNthFromEnd(&ln1, 3);

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
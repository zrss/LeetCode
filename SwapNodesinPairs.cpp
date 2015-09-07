#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
        	return head;
        }

        ListNode* cur = head;
        ListNode* newHead = head->next;

        ListNode* tmp = newHead->next;
        newHead->next = cur;
        cur->next = tmp;

        while (tmp != NULL) {
        	ListNode* next = tmp->next;
        	if (next != NULL) {
        		tmp->next = next->next;
        		next->next = tmp;
        		cur->next = next;
        	} else {
        		tmp->next = NULL;
        	}
        	cur = tmp;
        	tmp = cur->next;
        }

        return newHead;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(4);

	ln1.next = &ln2;
	ln2.next = &ln3;

	ListNode* newHead = solution.swapPairs(&ln1);

	while (newHead != NULL) {
		cout << newHead->val << " ";
		newHead = newHead->next;
	}
	cout << endl;

	return 0;
}
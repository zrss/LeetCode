#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	ListNode* fast = head;
    	ListNode* slow = head;

    	while (fast != NULL && fast->next != NULL) {
    		fast = fast->next->next;
    		slow = slow->next;

    		if (fast == slow) {
    			break;
    		}
    	}

        if (fast == NULL || fast->next == NULL) {
        	return NULL;
        }

        while (head != slow) {
        	head = head->next;
        	slow = slow->next;
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
	ln3.next = &ln3;

	ListNode* rel = solution.detectCycle(&ln1);
	cout << rel->val << endl;

	return 0;
}
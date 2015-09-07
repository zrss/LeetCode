#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* tmp;

        while (cur != NULL) {
        	tmp = cur->next;
        	cur->next = pre;
        	pre = cur;
        	cur = tmp;
        }

        return pre;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;

	ListNode ln1(1);

	ListNode* root = solution.reverseList(&ln1);

	while (root != NULL) {
		cout << root->val << " ";
        root = root->next;
	}
	cout << endl;
	return 0;
}
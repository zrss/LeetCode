#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
    	ListNode* pre = node;

        while (node->next != NULL) {
        	node->val = node->next->val;
        	pre = node;
        	node = node->next;
        }

        pre->next = NULL;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);

	l1.next = &l2;
	l2.next = &l3;

	solution.deleteNode(&l2);

	return 0;
}
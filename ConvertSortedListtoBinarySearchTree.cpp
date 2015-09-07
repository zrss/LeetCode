#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if (head == NULL) {
    		return NULL;
    	}

    	return buildTree(head, NULL);
    }

    TreeNode* buildTree(ListNode* head, ListNode* tail) {
    	if (head == tail)
    		return NULL;

        ListNode* fast = head;
        ListNode* slow = head;

        // locate middle
        while (fast != tail && fast->next != tail) {
        	fast = fast->next->next;
        	slow = slow->next;
        }

        TreeNode* treeNode = new TreeNode(slow->val);
        treeNode->left = buildTree(head, slow);
        treeNode->right = buildTree(slow->next, tail);

        return treeNode;
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
	ln3.next = &ln4;

	TreeNode* root = solution.sortedListToBST(&ln1);

	cout << root->left->left->val << endl;

	return 0;
}
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if (head == NULL)
    		return NULL;

        // cal listnode number
        int num = 1;
        ListNode* cur = head;
        ListNode* pre = NULL;

        while (cur->next != NULL) {
        	pre = cur;
        	cur = cur->next;
        	++num;
        }

        k %= num;

    	if (k == 0) {
    		return head;
    	}

    	int prePart = num - k - 1;
    	ListNode* preTail = head;

    	for (int i = 0; i < prePart; ++i) {
    		preTail = preTail->next;
    	}

    	ListNode* secondPart = preTail->next;
    	preTail->next = NULL;

    	ListNode* preNewHead = reverseList(head);
    	ListNode* secondNewHead = reverseList(secondPart);

    	head->next = secondNewHead;

    	return reverseList(preNewHead);
    }

    ListNode* reverseList(ListNode* head) {
    	if (head == NULL)
    		return NULL;

    	ListNode* cur = head;
    	ListNode* next = head->next;

    	head->next = NULL;

    	while (next != NULL) {
	    	ListNode* tmp = next->next;
	    	next->next = cur;
	    	cur = next;
	    	next = tmp;
    	}

    	return cur;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode ln1(1);
	//ListNode ln2(2);
	//ListNode ln3(3);
	//ListNode ln4(4);
	//ListNode ln5(5);

	//ln1.next = &ln2;
	//ln2.next = &ln3;
	//ln3.next = &ln4;
	//ln4.next = &ln5;

	ListNode* head = solution.rotateRight(&ln1, 5);

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
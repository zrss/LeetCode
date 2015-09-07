#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if (k == 0 || k == 1) {
    		return head;
    	}

        ListNode* curHead = head;
        ListNode* curTail = head;

        ListNode aux(0);
        ListNode* preTail = &aux;

        bool cont = true;

        while (cont) {
	        int cnt = 0;
	        while (curTail != NULL && cnt < k) {
	        	curTail = curTail->next;
	        	++cnt;
	        }
	        if (cnt == k) { // k group
	        	preTail->next = reverseList(curHead, curTail);
	        	preTail = curHead;
	        	curHead = curTail;
	        } else {
	        	preTail->next = curHead;
	        	cont = false;
	        }
        }

        return aux.next;
    }

    ListNode* reverseList(ListNode* head, ListNode* tail) {
    	if (head == NULL || head == tail) {
    		return head;
    	}

    	ListNode* cur = head;
    	ListNode* pre = NULL;

    	while (cur != tail) {
    		ListNode* tmp = cur->next;
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
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(4);
	ListNode ln5(5);

	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ln4.next = &ln5;

	ListNode* head = solution.reverseKGroup(&ln1, 3);

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
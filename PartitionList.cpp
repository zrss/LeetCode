#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode p1Aux(0);
        ListNode p2Aux(0);

        ListNode* p1Tail = &p1Aux;
        ListNode* p2Tail = &p2Aux;

        while (head != NULL) {
        	if (head->val < x) {
        		p1Tail->next = head;
        		p1Tail = head;
        	} else {
        		p2Tail->next = head;
        		p2Tail = head;
        	}
        	head = head->next;
        }

        p1Tail->next = p2Aux.next;
        p2Tail->next = NULL;

        return p1Aux.next;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode ln1(1);
	ListNode ln2(4);
	ListNode ln3(3);
	ListNode ln4(2);
	ListNode ln5(5);
	ListNode ln6(2);

	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ln4.next = &ln5;
	ln5.next = &ln6;

	ListNode* head = solution.partition(&ln1, 1);

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
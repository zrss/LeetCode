#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(ListNode* &l1, ListNode* &l2) {
	return l1->val > l2->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> maxHeap;

    	for (auto itr = lists.begin(); itr != lists.end(); ++itr) {
    		if (*itr != NULL) {
    			maxHeap.push_back(*itr);
    		}
    	}

        ListNode aux(0);
        ListNode* tail = &aux;

        if (!maxHeap.empty()) {
        	make_heap(maxHeap.begin(), maxHeap.end(), cmp);
        }

        while (!maxHeap.empty()) {
        	tail->next = maxHeap.front();
        	tail = maxHeap.front();

        	pop_heap(maxHeap.begin(), maxHeap.end(), cmp);
        	maxHeap.pop_back();

        	if (tail->next != NULL) {
        		maxHeap.push_back(tail->next);
        		push_heap(maxHeap.begin(), maxHeap.end(), cmp);
        	}
        }

        return aux.next;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode ln1(-5);
	ListNode ln2(4);

	vector<ListNode*> lists = {&ln1, &ln2};

	ListNode* rel = solution.mergeKLists(lists);

	while (rel != NULL) {
		cout << rel->val << " ";
		rel = rel->next;
	}
	cout << endl;

	return 0;
}
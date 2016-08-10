#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
    	int i = 0;
    	ListNode* chosen = _head;
    	ListNode* cur = _head;
    	
    	while (cur != NULL) {
	    	if ((rand() % (++i)) == 0) { // 1 / i set to chosen
	    		chosen = cur;
	    	}
    		cur = cur->next;
    	}

    	return chosen->val;
    }

private:
	ListNode* _head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
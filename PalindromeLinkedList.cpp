#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;

        while (head != NULL) {
        	vals.push_back(head->val);
        	head = head->next;
        }

        //
        int n = vals.size();
        bool cont = true;

        for (int i = 0; cont && i < (n >> 1); ++i) {
        	if (vals[i] != vals[n - i - 1]) {
        		cont = false;
        	}
        }

        return cont;
    }
};
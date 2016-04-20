#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 模拟题
// 使用虚拟头结点可以简化代码
// 注意移动新链表的当前节点

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode vHead(0);
        ListNode* cur = &vHead;

        int in = 0;
        while (l1 != NULL && l2 != NULL) {
        	int tmp = in + l1->val + l2->val;
        	in = tmp / 10;
        	l1->val = tmp % 10;
        	cur->next = l1;
        	cur = l1;
        	l1 = l1->next;
        	l2 = l2->next;
        }

        // 直接判断剩余
    	ListNode* remain = l1 == NULL ? l2 : l1;
    	while (remain != NULL) {
    		int tmp = in + remain->val;
    		in = tmp / 10;
    		remain->val = tmp % 10;
    		cur->next = remain;
    		cur = remain;
    		remain = remain->next;
    	}

    	// 最高位有进位
    	if (in != 0) {
    		cur->next = new ListNode(in);
    		cur = cur->next;
    	}

        cur->next = NULL;
    	return vHead.next;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}
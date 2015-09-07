#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode aux(0);
        RandomListNode* tail = &aux;

        RandomListNode* cur = head;
        unordered_map<RandomListNode*, RandomListNode*> map;

        while (cur != NULL) {
        	RandomListNode* rln = new RandomListNode(cur->label);

        	map.insert(pair<RandomListNode*, RandomListNode*>(cur, rln));

        	rln->random = cur->random;
        	
        	cur = cur->next;
        	tail->next = rln;
        	tail = rln;
        }

        cur = aux.next;

        while (cur != NULL) {
        	if (cur->random != NULL) {
        		cur->random = (map.find(cur->random))->second;
        	}
        	cur = cur->next;
        }

        return aux.next;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	return 0;
}
#ifndef _BINARY_TREE_LEVEL_ORDER_TRAVERSALII_H
#define _BINARY_TREE_LEVEL_ORDER_TRAVERSALII_H

#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<std::vector<int> > levelOrderBottom(TreeNode *root) {
		std::queue<TreeNode*> nodes; // traversal nodes in breadth first style
		std::vector<int> countlevelNodes; // each level nodes count
		std::vector<int> levelNodes; // each level nodes val

		int count = 0; // record each level nodes count
		int haveVisited = 0; // record current level visited nodes number

		if (root != NULL) {
			nodes.push(root);
			countlevelNodes.push_back(1);
		}

		while (!nodes.empty()) {
			TreeNode *itr = nodes.front();
			if (itr->left != NULL) {
				nodes.push(itr->left);
				++count;
			}
			if (itr->right != NULL) {
				nodes.push(itr->right);
				++count;
			}
			
			levelNodes.push_back(itr->val);
			nodes.pop();
			++haveVisited;

			if (haveVisited == countlevelNodes.back()) { // current level have visited all
				haveVisited ^= haveVisited;
				if (count != 0) {
					countlevelNodes.push_back(count);
					count ^= count;
				}
			}
		}

		std::vector<std::vector<int> > rel;
		rel.reserve(countlevelNodes.size());

		int startIndex = levelNodes.size();

		for (auto itr = countlevelNodes.rbegin(); itr != countlevelNodes.rend(); ++itr) {
			std::vector<int> level;
			level.reserve(*itr);

			startIndex -= *itr;

			for (int i = 0; i < *itr; ++i) {
				level.push_back(levelNodes[startIndex + i]);
			}

			rel.push_back(level);
		}

		return rel;
	}
};

#endif
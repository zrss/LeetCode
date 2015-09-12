#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	Solution():lack(0) {}

    int countNodes(TreeNode* root) {
    	if (root == NULL)
    		return 0;

    	lack = 0;
    	level = 0;

    	// cal level
    	TreeNode *itr = root;

    	while (itr->left != NULL) {
    		++level;
    		itr = itr->left;
    	}

    	if (level == 0)
    		return 1;

    	traverse(root, -1);

    	return (1 << (level + 1)) - 1 + lack;
    }

    bool traverse(TreeNode* ptr, int cur) {
    	++cur;
    	if (cur == level - 1) {
    		if (ptr->left == NULL) {
    			lack -= 2;
    			return false;
    		}
    		if (ptr->right == NULL) {
    			--lack;
    		}
    		return true;
    	}

    	if (traverse(ptr->right, cur))
    		return true;

    	if (traverse(ptr->left, cur))
    		return true;

    	return false;
    }

private:
	int lack;
	int level;
};

int main(int argc, char const *argv[]) {
	TreeNode root(0);
	// TreeNode a1(0),a2(0),a3(0),a4(0);

	// root.left = &a1;
	// root.right = &a2;
	// a1.left = &a3;
	// a1.right = &a4;

	Solution solution;
	std::cout << solution.countNodes(&root) << std::endl;
	return 0;
}

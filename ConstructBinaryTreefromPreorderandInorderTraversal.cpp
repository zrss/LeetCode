#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	// index
    	dict = new unordered_map<int, int>();

    	// inorder index
    	for (int i = 0; i < preorder.size(); ++i) {
    		dict->insert(pair<int, int>(inorder[i], i));
    	}

        TreeNode* root = helper(0, preorder.size(), preorder, 0, inorder.size());

        delete dict;

        return root;
    }

    TreeNode* helper(int preLeft, int preRight, vector<int>& preorder, int inLeft, int inRight) {
    	if (preLeft >= preRight)
    		return NULL;

    	// locate root node in inorder
    	int rootPos = dict->find(preorder[preLeft])->second;

    	TreeNode* root = new TreeNode(preorder[preLeft]);
    	int gap = rootPos - inLeft;
    	root->left = helper(preLeft + 1, preLeft + 1 + gap, preorder, inLeft, rootPos - 1);
    	root->right = helper(preLeft + 1 + gap, preRight, preorder, rootPos + 1, inRight);

    	return root;
    }

private:
	unordered_map<int, int>* dict;
};

int main(int argc, char const *argv[])
{
	vector<int> preorder = {1, 2, 3, 4};
	vector<int> inorder = {2, 1, 3, 4};

	Solution solution;
	TreeNode* root = solution.buildTree(preorder, inorder);


	solution.test(root);

	return 0;
}
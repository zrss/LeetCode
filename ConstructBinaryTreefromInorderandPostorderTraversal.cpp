#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> dict;

        int i = 0;
        for (auto itr = inorder.begin(); itr != inorder.end(); ++itr) {
        	dict.insert(pair<int, int>(*itr, i++));
        }

        return helper(0, inorder.size(), 0, postorder.size(), postorder, dict);
    }

    TreeNode* helper(int inLeft, int inRight, int postLeft, int postRight, vector<int>& postorder, unordered_map<int, int>& dict) {
    	if (inLeft >= inRight)
    		return NULL;

    	TreeNode* root = new TreeNode(postorder[postRight - 1]);

    	int rootPos = dict.find(postorder[postRight - 1])->second;
    	int gap = rootPos - inLeft;
    	root->left = helper(inLeft, rootPos, postLeft, postLeft + gap, postorder, dict);
    	root->right = helper(rootPos + 1, inRight, postLeft + gap, postRight - 1, postorder, dict);

    	return root;
    }

    void test(TreeNode* root) {
    	if (root == NULL)
    		return;

    	cout << root->val << " ";

    	test(root->left);

    	test(root->right);
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	vector<int> inorder = {2, 1, 3};
	vector<int> postorder = {2, 3, 1};

	TreeNode* root = solution.buildTree(inorder, postorder);

	solution.test(root);
	return 0;
}
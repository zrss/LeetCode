#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> tmp;

        dfs(root, result, tmp);

        return result;
    }

    void dfs(TreeNode* root, vector<string>& result, vector<int>& tmp) {
    	if (root == NULL)
    		return;

    	tmp.push_back(root->val);

    	if (root->left == NULL && root->right == NULL) { // leaf node
			// convert to string
	    	string str;
	    	str += to_string(tmp[0]); // c++11 std::to_string()

	    	for (int i = 1; i < tmp.size(); ++i) {
	    		str += "->";
	    		str += to_string(tmp[i]);
	    	}

    		result.push_back(str);
    	}

    	dfs(root->left, result, tmp);

    	dfs(root->right, result, tmp);

    	tmp.pop_back();
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	TreeNode root(1);

	vector<string> rel = solution.binaryTreePaths(&root);

	for (auto itr = rel.begin(); itr != rel.end(); ++itr) { // c++11 auto
		cout << *itr << " ";
	}

	cout << endl;

	return 0;
}
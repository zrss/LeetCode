// 自顶向下
// 记忆化搜索

class Solution {
public:
	int rob(TreeNode* root) {
		return max(solve(root, true), solve(root, false));
	}

	int solve(TreeNode* root, bool rob) {
		if (root == NULL)
			return 0;

		if (rob) {
			unordered_map<TreeNode*, int>::iterator itr = robValue.find(root);
			if (itr != robValue.end()) {
				return itr->second;
			}
			int value = root->val + solve(root->left, false) + solve(root->right, false);
			robValue[root] = value;
			return value;
		}

		unordered_map<TreeNode*, int>::iterator itr = unRobValue.find(root);
		if (itr != robValue.end()) {
			return itr->second;
		}

		int t1 = max(solve(root->left, true), solve(root->left, false));
		int t2 = max(solve(root->right, true), solve(root->right, false));
		unRobValue[root] = t1 + t2;
		return t1 + t2;
	}

private:
	unordered_map<TreeNode*, int> robValue;
	unordered_map<TreeNode*, int> unRobValue;
};
// 自底向上

class Solution {
public:
	int rob(TreeNode* root) {
		pair<int, int> p = solve(root);
		return max(p.first, p.second);
	}

	// <robMaxValue, unRobMaxValue>
	pair<int, int> solve(TreeNode* root) {
		if (root == NULL)
			return make_pair(0, 0);

		pair<int, int> left = solve(root->left);
		pair<int, int> right = solve(root->right);

		// rob
		int robValue = root->val + left.second + right.second;

		// unrob
		int unRobValue = max(left.first, left.second) + max(right.first, right.second);

		return make_pair(robValue, unRobValue);
	}
};
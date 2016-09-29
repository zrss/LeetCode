class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        return sumOfLeftLeaves(root, NULL);
    }
    
    int sumOfLeftLeaves(TreeNode* root, TreeNode* parent) {
        int sum = 0;
        if (root->left != NULL) {
            sum += sumOfLeftLeaves(root->left, root);
        }
        if (root->right != NULL) {
            sum += sumOfLeftLeaves(root->right, root);
        }
        
        if (parent != NULL && root->left == NULL && root->right == NULL && root == parent->left) {
            return sum + (root->val);
        }
        
        return sum;
    }
};
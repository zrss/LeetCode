#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rel;
        
        if (root == NULL)
            return rel;
        
        TreeNode* itr = root;
        
        bool flag = true;
        
        stack<TreeNode*> stack;
        stack.push(itr);
        
        while (!stack.empty()) {
            itr = stack.top();
            
            if (flag) {
                while (itr->left != NULL) {
                    stack.push(itr->left);
                    itr = itr->left;
                }
            }

            rel.push_back(itr->val);
            stack.pop();
            
            if (itr->right != NULL) {
                stack.push(itr->right);
                flag = true;
            }
            else
                flag = false;
        }
        
        return rel;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;

    TreeNode node3(3);
    TreeNode node2(2);
    TreeNode node1(1);

    node3.left = &node2;
    node2.left = &node1;

    vector<int> rel = solution.inorderTraversal(&node3);

    for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
        printf("%d ", *itr);
    }

    return 0;
}
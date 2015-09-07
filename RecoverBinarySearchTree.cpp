#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Solution():prev(NULL), revStart(NULL), revEnd(NULL) {}

    void recoverTree(TreeNode* root) {
        inorder(root);

        int temp = revStart->val;
        revStart->val = revEnd->val;
        revEnd->val = temp;
    }

    void inorder(TreeNode* itr) {
        if (itr == NULL)
            return;

        inorder(itr->left);

        if (prev != NULL && prev->val > itr->val) {
            if (revStart == NULL) {
                revStart = prev;
            }

            revEnd = itr;
        }

        prev = itr;

        inorder(itr->right);
    }

private:
    TreeNode* prev;
    TreeNode* revStart;
    TreeNode* revEnd;
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode n1(1);
    TreeNode n2(4);
    TreeNode n3(5);
    TreeNode n4(2);

    n2.left = &n1;
    n2.right = &n3;
    n3.left = &n4;

    solution.recoverTree(&n2);

    return 0;
}
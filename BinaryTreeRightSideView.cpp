/* Leetcode 199 one try AC 10MS */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct node {
  node(TreeNode* treeNode, int level):treeNode(treeNode), level(level) {}

  TreeNode* treeNode;
  int level;
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
      if (root == NULL) {
        return vector<int>();
      }

      vector<int> rel;

      queue<node> queue;

      queue.push(node(root, 0));

      while (!queue.empty()) {
        node cur = queue.front();
        queue.pop();

        TreeNode* curNode = cur.treeNode;

        int curLevel = cur.level + 1;

        TreeNode* leftNode = curNode->left;

        if (queue.empty() || cur.level != queue.front().level) {
          rel.push_back(curNode->val);
        }

        if (leftNode != NULL) {
          queue.push(node(leftNode, curLevel));
        }

        TreeNode* rightNode = curNode->right;

        if (rightNode != NULL) {
          queue.push(node(rightNode, curLevel));
        }
      }

      return rel;
    }
};

int main(int argc, char const *argv[]) {
    TreeNode root(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n5(5);
    TreeNode n4(4);

    root.left = &n2;
    root.right = &n3;

    n2.right = &n5;
    n3.right = &n4;


    Solution solution;
    vector<int> rel = solution.rightSideView(&root);

    for (auto itr = rel.begin(); itr != rel.end(); ++itr) {
        cout << *itr << endl;
    }

    return 0;
}

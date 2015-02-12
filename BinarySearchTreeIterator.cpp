/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Stack {
public:
	Stack():pos(0),capacity(100) { array = new TreeNode*[capacity]; };
	
	int size() { return pos; }
	
	TreeNode* top() { return array[pos - 1]; }

	void push_back(TreeNode* t) { array[pos++] = t; };

	void pop_back() { --pos; }

	~Stack() { delete [] array; }

private:
	int pos;
	int capacity;
	TreeNode* array;
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
    	while (root != NULL) {
			stack.push_back(root);
			root = root->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stack.size() ? true : false;
    }

    /** @return the next smallest number */
    int next() {
        int tmp = stack.top()->val;
        if (stack.top()->right != NULL) {
        	TreeNode* cpy = stack.top()->right;
        	stack.pop_back();
        	stack.push_back(cpy);
        	while (cpy->left != NULL) {
        		stack.push_back(cpy->left);
        		cpy = cpy->left;
        	}
        } else {
        	stack.pop_back();
        }
        return tmp;
    }

private:
	Stack stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
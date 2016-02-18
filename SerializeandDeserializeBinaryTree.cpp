/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) { // 空用.表示
            return ".";
        }   
        
        string cur = to_string(root->val); // 整形转字符串
        
        string lstr = serialize(root->left);
        string rstr = serialize(root->right);
        
        return cur + " " + lstr + rstr; // 注意数字分界
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 1) {
            return NULL;
        }
        
        int pos = 0;
        return helper(data, pos);
    }
    
    TreeNode* helper(string& data, int& pos) {
        if (data[pos] == '.') {
            return NULL;
        }
        
        // find gap ' '
        int end = pos;
        while (data[end] != ' ') {
            ++end;
        }
        
        string strValue = data.substr(pos, end - pos); // 字符串转整形
        TreeNode* cur = new TreeNode(stoi(strValue));
        pos = end;
        
        cur->left = helper(data, ++pos);
        cur->right = helper(data, ++pos);
        
        return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
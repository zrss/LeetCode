#include <iostream>
#include <vector>

using namespace std;

struct SegNode {
    int _s;
    int _e;

    int _v;

    SegNode* left;
    SegNode* right;

    SegNode(int s, int e) : _s(s), _e(e), left(NULL), right(NULL) {}
    SegNode(int s, int e, int v) : _s(s), _e(e), _v(v), left(NULL), right(NULL) {}
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.size() != 0) {
            root = buildTree(nums, 0, nums.size() - 1);
        }
        else {
            root = NULL;
        }
    }

    SegNode* buildTree(vector<int>& nums, int s, int e) {
        if (s == e) {
            return new SegNode(s, e, nums[s]);
        }

        int m = (s + e) >> 1;
        SegNode* cur = new SegNode(s, e);
        cur->left = buildTree(nums, s, m);
        cur->right = buildTree(nums, m + 1, e);
        cur->_v = cur->left->_v + cur->right->_v;
        return cur;
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    int update(SegNode* ptr, int i, int val) {
        if (ptr == NULL) {
            return 0;
        }

        int s = ptr->_s;
        int e = ptr->_e;
        if (s == e && s == i) {
            int diff = val - ptr->_v;
            ptr->_v = val;
            return diff;
        }

        int m = (s + e) >> 1;
        int diff = 0;
        if (i <= m) {
            diff = update(ptr->left, i, val);
        }
        else {
            diff = update(ptr->right, i, val);
        }

        ptr->_v += diff;
        return diff;
    }

    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }

    int sumRange(SegNode* ptr, int i, int j) {
        if (ptr == NULL) {
            return 0;
        }

        int s = ptr->_s;
        int e = ptr->_e;

        if (j < s || i > e) {
            return 0;
        }

        if (s == i && e == j) {
            return ptr->_v;
        }
            
        int m = (s + e) >> 1;
        if (j <= m) {
            return sumRange(ptr->left, i, j);
        }
        else if (i > m) {
            return sumRange(ptr->right, i, j);
        }
        else {
            // spend more then four days
            // sumRange(ptr->left, i, j) + sumRange(ptr->right, i, j)
            // that will get TLE error
            return sumRange(ptr->left, i, m) + sumRange(ptr->right, m + 1, j);
        }
    }

private:
    SegNode* root;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main() {
    vector<int> nums = { 1,3,5 };
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(1, 10);
    cout << numArray.sumRange(1, 2) << endl;
    return 0;
}
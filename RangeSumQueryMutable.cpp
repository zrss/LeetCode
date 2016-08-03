#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct SegNode {
    int start;
    int end;

    int value;

    SegNode* left_region;
    SegNode* right_region;

    SegNode(): start(0), end(0), value(0), left_region(NULL), right_region(NULL) {}
    SegNode(int s, int e, int v): start(s), end(e), value(v), left_region(NULL), right_region(NULL) {}
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        root = buildSegTree(nums, 0, nums.size());
    }

    SegNode* buildSegTree(vector<int>& nums, int r_s, int r_e) {
        if (r_s >= r_e) {
            return NULL;
        }

        // unit
        if (r_s + 1 == r_e) {
            return new SegNode(r_s, r_e, nums[r_s]);
        }

        //
        int r_m = (r_s + r_e) >> 1;
        SegNode* left_region = buildSegTree(nums, r_s, r_m);
        SegNode* right_region = buildSegTree(nums, r_m, r_e);

        int left_sum = left_region != NULL ? left_region->value : 0;
        int right_sum = right_region != NULL ? right_region->value : 0;

        SegNode* cur_region = new SegNode(r_s, r_e, left_sum + right_sum);
        cur_region->left_region = left_region;
        cur_region->right_region = right_region;

        return cur_region;
    }

    void update(int i, int val) {
        updateRegion(root, i, val);
    }

    int updateRegion(SegNode* cur_region, int i, int val) {
        int r_s = cur_region->start;
        int r_e = cur_region->end;

        if (i < r_s || i >= r_e) {
            return 0;
        }

        if (r_s == i && r_s + 1 == r_e) {
            int diff = val - cur_region->value;
            cur_region->value = val;
            return diff;
        }

        int r_m = (r_s + r_e) >> 1;
        int diff = 0;
        if (i < r_m) {
            diff = updateRegion(cur_region->left_region, i, val);
        } else {
            diff = updateRegion(cur_region->right_region, i, val);
        }

        cur_region->value += diff;
        return diff;
    }

    int sumRange(int i, int j) {
        return queryRegion(root, i, j + 1);
    }

    int queryRegion(SegNode* cur_region, int q_s, int q_e) {
        if (cur_region == NULL) {
            return 0;
        }

        int r_s = cur_region->start;
        int r_e = cur_region->end;

        if (q_s >= r_e || q_e <= r_s) {
            return 0;
        }

        if ((q_s == r_s && q_e == r_e) || (r_s + 1 == r_e)) {
            return cur_region->value;
        }

        int r_m = (r_s + r_e) >> 1;
        if (q_e <= r_m) {
            return queryRegion(cur_region->left_region, q_s, q_e);
        } else if (q_s >= r_m) {
            return queryRegion(cur_region->right_region, q_s, q_e);
        } else {
            return queryRegion(cur_region->left_region, q_s, q_e) + queryRegion(cur_region->right_region, q_s, q_e);
        }
    }

private:
    SegNode* root;
};

int main(int argc, char const *argv[]) {
	vector<int> nums = {1, 3, 5};
	NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << endl;

    numArray.update(1, 2);

    cout << numArray.sumRange(0, 50) << endl;

	return 0;
}
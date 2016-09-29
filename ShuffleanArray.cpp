// 洗牌算法
// 随机挑一张牌，交换至当前末位
// 当牌挑完时即洗牌结束

class Solution {
public:
    Solution(vector<int> nums) {
        origin = nums;
        shuf = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int size = shuf.size();
        while (size) {
            int idx = rand() % size;
            swap(shuf[idx], shuf[--size]);
        }
        return shuf;
    }
    
private:
    vector<int> origin;
    vector<int> shuf;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

 int main(int argc, char const *argv[]) {
 	Solution obj = new Solution(nums);
 	vector<int> param_1 = obj.reset();
	vector<int> param_2 = obj.shuffle();
 	return 0;
 }
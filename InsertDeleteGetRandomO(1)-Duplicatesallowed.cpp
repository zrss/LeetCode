class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool rel = false;
        unordered_map<int, vector<int>>::iterator itr = m.find(val);
        if (itr == m.end()) {
            rel = true;
        }
        
        m[val].push_back(nums.size());
        nums.push_back(make_pair(val, m[val].size() - 1));
        
        return rel;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        unordered_map<int, vector<int>>::iterator itr = m.find(val);
        if (itr == m.end()) {
            return false;
        }
        
        pair<int, int> last = nums.back();
        m[last.first][last.second] = m[val].back();
        nums[m[val].back()] = last;
        
        m[val].pop_back();
        
        if (m[val].size() == 0)
            m.erase(val);
            
        nums.pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
    
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
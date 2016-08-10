#include <iostream>
#include <cstdlib>
#include <unordered_set>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        pair<unordered_set<int>::iterator,bool> rel = set.insert(val);
        return rel.second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int rel = set.erase(val);
        return rel;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (set.size() == 0) {
            return 0;
        }

        int r = rand() % set.size();
        int cnt = 0;
        auto itr = set.begin();
        while (cnt < r) {
            ++cnt;
            ++itr;
        }

        return *itr;
    }

private:
    unordered_set<int> set;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

 int main(int argc, char const *argv[]) {
     RandomizedSet randomizedSet;
     randomizedSet.insert(1);
     randomizedSet.remove(2);
     randomizedSet.insert(2);
     randomizedSet.remove(1);
     randomizedSet.insert(2);
     cout << randomizedSet.getRandom() << endl;
     return 0;
 }
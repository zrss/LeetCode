#include <iostream>
#include <multiset>

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool rel = false
        if (set.find(val) != set.end()) {
            rel = true;
        }
        set.insert(val);
        return rel;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        multiset<int>::iterator itr = set.find(val);
        if (itr == set.end()) {
            return false;
        }

        multiset<int>::iterator last = itr;
        ++last;

        multiset.erase(itr, last);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int r = rand() % set.size();
        auto itr = set.begin();
        for (int c = 0; c < r; ++c) {
            ++itr;
        }
        return *itr;
    }

private:
    multiset<int> set;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
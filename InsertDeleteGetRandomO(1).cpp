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
        map<int, int>::iterator itr = indexMap.find(val);
        if (itr != indexMap.end()) {
            return false;
        }

        indexMap.insert(make_pair(val, arrays.size()));
        arrays.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        map<int, int>::iterator itr = indexMap.find(val);
        if (itr == indexMap.end())
            return false;

        indexMap[arrays.back()] = itr->second;
        arrays[itr->second] = arrays.back();
        arrays.pop_back();

        indexMap.erase(itr);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return arrays[rand() % arrays.size()];
    }

private:
    map<int, int> indexMap;
    vector<int> arrays;
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
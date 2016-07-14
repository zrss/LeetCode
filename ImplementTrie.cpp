// trie tree it is a very useful data structure for searching word
// just for practice

// r
// a
// b b
// c

// i.e. insert abc, and ab, how to deal with this case
// add a field in TrieNode indicate that is a word end

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char c) {
        _c = c;
        wordEnd = false;
    }

    bool equals(char c) {
        return _c == c;
    }

    bool isWordEnd() {
        return wordEnd;
    }

    void setWordEnd() {
        wordEnd = true;
    }

    TrieNode* addNode(char c) {
        TrieNode* trieNode = locateCh(c);
        if (trieNode == NULL) {
            trieNode = new TrieNode(c);
            children.push_back(trieNode);
        }
        return trieNode;
    }

    TrieNode* locateCh(char c) {
        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->equals(c)) {
                return children[i];
            }
        }
        return NULL;
    }

private:
    char _c;
    vector<TrieNode*> children;
    bool wordEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode('r');
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* itr = root;
        for (int i = 0; i < word.length(); ++i) {
            itr = itr->addNode(word[i]);
        }
        if (itr != root) {
            itr->setWordEnd();
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* itr = root;
        for (int i = 0; itr != NULL && i < word.length(); ++i) {
            itr = itr->locateCh(word[i]);
        }
        return (itr != NULL && itr->isWordEnd());
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* itr = root;
        for (int i = 0; itr != NULL && i < prefix.length(); ++i) {
            itr = itr->locateCh(prefix[i]);
        }
        return (itr != NULL);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(int argc, char const *argv[])
{
    Trie trie;
    trie.insert("abc");
    trie.insert("ab");
    cout << trie.search("hel") << endl;
    cout << trie.search("ab") << endl;
    return 0;
}
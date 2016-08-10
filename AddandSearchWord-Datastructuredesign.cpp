#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// Trie树
// 遇到.得遍历剩余的节点

class TrieNode {
public:
	TrieNode(): word(false) {
		memset(children, NULL, sizeof(children));
	}

	TrieNode* addCh(char ch) {
		if (children[ch - 'a'] == NULL) {
			children[ch - 'a'] = new TrieNode();
		}
		return children[ch - 'a'];
	}

	bool hasCh(char ch) {
		return children[ch - 'a'] != NULL;
	}

	TrieNode* getChildren(int i) {
		return children[i];
	}

	TrieNode* getChildren(char ch) {
		return children[ch - 'a'];
	}

	void setWord() {
		word = true;
	}

	bool isWord() {
		return word;
	}

private:
	TrieNode* children[26];
	bool word;
};

class WordDictionary {
public:

	WordDictionary() {
		root = new TrieNode();
	}

    // Adds a word into the data structure.
    void addWord(string word) {
    	if (word.length() == 0) {
    		return;
    	}

    	TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
        	cur = cur->addCh(word[i]);
        }
        cur->setWord();
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, root);
    }

    bool search(string word, int cur, TrieNode* trieNode) {
    	if (cur == word.length()) {
    		return trieNode->isWord();
    	}

    	if (word[cur] == '.') {
    		for (int i = 0; i < 26; ++i) {
    			TrieNode* c = trieNode->getChildren(i);
    			if (c != NULL) {
    				if (search(word, cur + 1, c)) {
    					return true;
    				}
    			}
    		}
    	} else {
    		if (trieNode->hasCh(word[cur])) {
    			return search(word, cur + 1, trieNode->getChildren(word[cur]));
    		} else {
    			return false;
    		}
    	}

    	return false;
    }

private:
	TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(int argc, char const *argv[]) {
	WordDictionary wordDictionary;
	wordDictionary.addWord("word");
	cout << wordDictionary.search("w") << endl;
	return 0;
}
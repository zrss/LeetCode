#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord.length() != endWord.length()) {
            return 0;
        }

        unordered_set<string> activeWord[3];
        int startSet = 0, nextSet = 1, endSet = 2;

        activeWord[startSet].insert(beginWord);
        activeWord[endSet].insert(endWord);

        wordList.erase(beginWord);
        wordList.erase(endWord);

        int len = beginWord.length();

        int step = 1;

        // 所有单词都是一个长度
        while (!activeWord[startSet].empty()) {
            for (auto it : activeWord[startSet]) { // 遍历候选集
                for (int i = 0; i < len; ++i) { // 遍历单词每个字母
                    char tmp = it[i];
                    for (char j = 'a'; j <= 'z'; ++j) { // 尝试替换字母
                        if (it[i] != j) {
                            it[i] = j;

                            // 判断是否在结尾集中
                            if (activeWord[endSet].count(it) > 0) {
                                return step + 1;
                            }

                            // 判断是否在字典集中
                            auto word = wordList.find(it);
                            if (word != wordList.end()) { // 加入下一集中
                                activeWord[nextSet].insert(it);
                                wordList.erase(word); // 从字典集中去除
                            }
                        }
                    }
                    it[i] = tmp;
                }
            }

            ++step;

            swap(activeWord[startSet], activeWord[nextSet]);
            activeWord[nextSet].clear(); // 设置nextSet为空
            if (activeWord[startSet].size() > activeWord[endSet].size()) {
                swap(activeWord[startSet], activeWord[endSet]);
            }
        }

        return 0;
    }
};

int main(int argc, char const *argv[]) {
	Solution solution;
	unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log"};
	cout << solution.ladderLength("hit", "cog", wordList) << endl;
	return 0;
}
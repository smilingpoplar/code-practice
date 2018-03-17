//
//  word-ladder-ii
//  https://leetcode.com/problems/word-ladder-ii/
//
//  Created by smilingpoplar on 15/4/29.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto &word : wordList) {
            dict.insert(word);
        }
        
        unordered_set<string> currLevel;
        currLevel.insert(beginWord);
        unordered_set<string> visited;

        unordered_map<string, unordered_set<string>> prevs;
        bool found = false;
        while (!currLevel.empty()) {
            // 将同层词的visited[]全部设置，避免向同层词扩展
            for (auto &word : currLevel) {
                visited.insert(word);
            }
            unordered_set<string> nextLevel;
            for (auto &word : currLevel) {
                auto nextWords = getNextWords(word, endWord, dict);
                for (auto &nextWord : nextWords) {
                    if (!visited.count(nextWord)) {
                        nextLevel.insert(nextWord);
                        prevs[nextWord].insert(word);
                        if (nextWord == endWord) found = true;
                    }
                }
            }
            swap(nextLevel, currLevel);
            // BFS时如果找到一条最短路径，那么所有最短路径一定都在这一层，不再考虑下一层
            if (found) break;
        }
        
        return genPaths(endWord, beginWord, prevs);
    }
    
private:
    unordered_set<string> getNextWords(const string &word, 
                const string &endWord, const unordered_set<string> &dict) {
        unordered_set<string> ans;
        for (size_t i = 0; i < word.size(); i++) {
            string newWord(word);
            for (char c = 'a'; c <= 'z'; c++) {
                if (newWord[i] == c) continue;

                swap(c, newWord[i]);                    
                if (dict.count(newWord)) ans.insert(newWord);
                swap(c, newWord[i]);
            }
        }
        return ans;
    }
    
    vector<vector<string>> genPaths(const string &word, const string &beginWord, 
                                    unordered_map<string, unordered_set<string>> &prevs) {
        vector<vector<string>> ans;
        vector<string> path;
        rGenPaths(word, beginWord, prevs, path, ans);
        return ans;
    }
    
    void rGenPaths(const string &word, const string &beginWord, 
                unordered_map<string, unordered_set<string>> &prevs,
                vector<string> &path, vector<vector<string>> &ans) {
        path.push_back(word); // 先反向存，最后reverse
        if (word == beginWord) {
            ans.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            for (auto &p : prevs[word]) {
                rGenPaths(p, beginWord, prevs, path, ans);
            }
        }
        path.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}

// 127. Word Ladder
/*
 * Given two words (beginWord and endWord), and a dictionary's word list,
 * find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// 单向BFS, 依次从第一个字符开始尝试修改'a' - 'z'判断是否存在于字典里, 有则以此为基础
// 开始尝试修改第2个字符'a' - 'z' 最后如果能到达target则表示有解
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;

    queue<string> q;      // BFS常用queue来辅助
    q.push(beginWord);

    int l = beginWord.size();
    int step = 0;

    while (!q.empty()) {
        ++step;
        for (int size = q.size(); size > 0; size--) {
            string w = q.front();
            q.pop();
            for (int i = 0; i < l; ++i) {
                char ch = w[i];                          // record the char needs to be replaced
                for (int j = 'a'; j <= 'z'; j++) {
                    w[i] = j;
                    if (w == endWord) return step + 1;   // Found solution
                    if (!dict.count(w)) continue;        // Not in dict, skip it
                    dict.erase(w);                       // Already used, remove from dict
                    q.push(w);
                }
                w[i] = ch;                               // put it back
            }
        }
    }
    return 0;
}


// 692. Top K Frequent Words
/*
 * Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency,
then the word with the lower alphabetical order comes first.

Example 1:

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Input words contain only lowercase letters.

*/

class Solution {
public:
    vector<string> topKFrequentWord(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto& w : words) ++m[w];

        auto cmp = [&](string& lhs, string& rhs) {
            if (m[lhs] == m[rhs])
                return lhs > rhs;
            return m[lhs] < m[rhs];
        };

        std::priority_queue<string, std::vector<string>, decltype(cmp)> q(cmp);
        for (auto& item : m) {
            q.push(item.first);
        }

        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};


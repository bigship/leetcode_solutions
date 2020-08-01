// 648. Replace Words
/*
 * In English, we have a concept called root, which can be followed by some other
 * words to form another longer word - let's call this word successor.
 * For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence.
You need to replace all the successor in the sentence with the root forming it.
If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:

Input: dict = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"



Constraints:

    The input will only have lower-case letters.
    1 <= dict.length <= 1000
    1 <= dict[i].length <= 100
    1 <= sentence words number <= 1000
    1 <= sentence words length <= 1000
*/

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode();
        for (auto& word : dict) {
            TrieNode *cur = root;
            for (auto& ch : word) {
                if (cur->children[ch-'a'] == nullptr) {
                    cur->children[ch-'a'] = new TrieNode();
                }
                cur = cur->children[ch-'a'];
            }
            cur->word = word;
        }

        string ans = "";
        for (int i = 0; i < sentence.length(); i++) {
            int j = i;
            while (j < sentence.length()) {
                if (sentence[j] == ' ')
                    break;
                j++;
            }
            string sbstr = sentence.substr(i, j - i);
            i = j;

            TrieNode *cur = root;
            for (auto& letter : sbstr) {
                if (cur->children[letter-'a'] == nullptr || cur->word != "") {
                    break;
                }
                cur = cur->children[letter-'a'];
            }
            ans += ((cur->word != "" ? cur->word : sbstr) + " ");
        }
        ans.pop_back();  // get rid of the last " "
        return ans;
    }

    class TrieNode {
        vector<TrieNode *> children;
        string word = "";
        TrieNode() {
            children = vector<TrieNode *>(26, nullptr);
        }
    }
};



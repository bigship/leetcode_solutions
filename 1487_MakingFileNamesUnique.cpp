// 1487. Making File Names Unique
/*
 * Given an array of strings names of size n. You will create n folders in your
 * file system such that, at the ith minute, you will create a folder with the name names[i].

Since two files cannot have the same name, if you enter a folder name which is
previously used, the system will have a suffix addition to its name in the form of (k),
where, k is the smallest positive integer such that the obtained name remains unique.

Return an array of strings of length n where ans[i] is the actual name the system
will assign to the ith folder when you create it.



Example 1:

Input: names = ["pes","fifa","gta","pes(2019)"]
Output: ["pes","fifa","gta","pes(2019)"]
Explanation: Let's see how the file system creates folder names:
"pes" --> not assigned before, remains "pes"
"fifa" --> not assigned before, remains "fifa"
"gta" --> not assigned before, remains "gta"
"pes(2019)" --> not assigned before, remains "pes(2019)"

Example 2:

Input: names = ["gta","gta(1)","gta","avalon"]
Output: ["gta","gta(1)","gta(2)","avalon"]
Explanation: Let's see how the file system creates folder names:
"gta" --> not assigned before, remains "gta"
"gta(1)" --> not assigned before, remains "gta(1)"
"gta" --> the name is reserved, system adds (k), since "gta(1)" is also reserved, systems put k = 2. it becomes "gta(2)"
"avalon" --> not assigned before, remains "avalon"

Example 3:

Input: names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
Output: ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
Explanation: When the last folder is created, the smallest positive valid k is 4, and it becomes "onepiece(4)".

Example 4:

Input: names = ["wano","wano","wano","wano"]
Output: ["wano","wano(1)","wano(2)","wano(3)"]
Explanation: Just increase the value of k each time you create folder "wano".

Example 5:

Input: names = ["kaido","kaido(1)","kaido","kaido(1)"]
Output: ["kaido","kaido(1)","kaido(2)","kaido(1)(1)"]
Explanation: Please note that system adds the suffix (k) to current name even it contained the same suffix before.



Constraints:

    1 <= names.length <= 5 * 10^4
    1 <= names[i].length <= 20
    names[i] consists of lower case English letters, digits and/or round brackets.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        if (names.size() == 0) return ans;

        unordered_map<string, int> used;
        used[names[0]] = 0;
        ans.push_back(names[0]);
        for (int i = 1; i < names.size(); ++i) {
            if (used.count(names[i]) == 0) {
                used[names[i]] = 0;
                ans.push_back(names[i]);
            } else {
                ++used[names[i]];
                while (true) {
                    string ns = names[i] + '(' + std::to_string(used[names[i]]) + ')';
                    if (used.count(ns) == 0) {
                        used[ns] = 0;
                        ans.push_back(ns);
                        break;
                    } else {
                        ++used[names[i]];
                    }
                }
            }
        }
        return ans;
    }

    // Use Recursion to get next number, TLE !
    vector<string> getFolderNames_recursion(vector<string>& names) {
        vector<string> ans;
        if (names.size() == 0) return ans;

        unordered_set<string> used;
        used.insert(names[0]);
        ans.push_back(names[0]);
        for (int i = 1; i < names.size(); ++i) {
            if (used.count(names[i]) == 0) {
                used.insert(names[i]);
                ans.push_back(names[i]);
            } else {
                int n = findNext(used, names[i], 1);
                //cout << "we get n = " << n << endl;
                string news = names[i] + '(' + to_string(n) + ')';
                used.insert(news);
                ans.push_back(news);
            }
        }
        return ans;
    }

private:
    int findNext(unordered_set<string>& used, string& name, int next) {
        int n = next;
        string s = name + '(' + to_string(n) + ')';
        if (used.count(s) == 0) return n;
        else {
            return findNext(used, name, n+1);
        }
    }
};




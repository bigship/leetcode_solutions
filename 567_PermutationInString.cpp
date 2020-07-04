// 567. Permutation in String
/*
 * Given two strings s1 and s2, write a function to return true if s2 contains the
 * permutation of s1. In other words, one of the first string's permutations is the
 * substring of the second string.



Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False



Constraints:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool checkInclusion(string s1, string s2) {
    int start = 0, end = 0;
    int len1 = s1.size();
    vector<int> check(26, 0);
    vector<int> check2(26, 0);
    int found = -1;
    for (auto& s : s1) check[s - 'a']++;

    for (; end < s2.size(); end++) {
        if (end - start != len1 - 1) continue;
        for (int i = start; i <= end; i++) {
            check2[s2[i] - 'a']++;
        }
        if (check == check2) return true;
        vector<int>(26, 0).swap(check2);
        start++;
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaoro";
    std:: cout << checkInclusion(s1, s2) << std::endl;
}



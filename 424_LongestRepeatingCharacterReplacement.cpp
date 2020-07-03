// 424. Longest Repeating Character Replacement
/* Given a string s that consists of only uppercase English letters,
 * you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to
any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you
can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.



Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

#include <iostream>
#include <string>
using namespace std;

// Sliding window
// add from right, pop from left, slide from left to right
int characterReplacement(string s, int k) {
    int ans = 0;
    int maxcnt = 0;
    int tb[26] = {0};
    int start = 0, end = 0;
    int len = s.size();

    for (; end < len; end++) {
        tb[s[end] - 'A']++;
        int curcnt = tb[s[end] - 'A'];
        maxcnt = std::max(curcnt, maxcnt);

        // out of options, we can't replace anymore characters
        // pop the leftmost element from window
        while (end - start + 1 - maxcnt > k) {
            tb[s[start] - 'A']--;
            start++;
        }
        // keep track of the max value for ans
        ans = std::max(ans, end - start + 1);
    }
    return ans;
}

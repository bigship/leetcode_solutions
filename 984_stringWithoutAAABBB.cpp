// 984. String without AAA or BBB
/*
 * Given two integers A and B, return any string S such that:

    S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
    The substring 'aaa' does not occur in S;
    The substring 'bbb' does not occur in S.
*/

#include <iostream>
#include <string>

using namespace std;

string strWithout3a3b(int A, int B) {
    char a = 'a';
    char b = 'b';
    if (B > A) {
        swap(A, B);
        swap(a, b);
    }

    string ans;
    while (A || B) {
        if (A > 0) { ans += a; A--; }
        if (A > B) { ans += a; A--; }
        if (B > 0) { ans += b; B--; }
    }
    return ans;
}

int main() {
    int A = 4, B = 1;
    string ans = strWithout3a3b(A, B);
    cout << ans << endl;
    A = 1, B = 2;
    ans = strWithout3a3b(A, B);
    cout << ans << endl;
    A = 10, B = 5;
    ans = strWithout3a3b(A, B);
    cout << ans << endl;
    A = 12, B = 7;
    ans = strWithout3a3b(A, B);
    cout << ans << endl;
    return 0;
}

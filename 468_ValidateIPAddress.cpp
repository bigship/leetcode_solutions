// 468. Validate IP Address
/*
 * Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
i
IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers,
each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits.
The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one.
Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address
to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::)
to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.



Example 1:

Input: IP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:

Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:

Input: IP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if (std::count(IP.begin(), IP.end(), '.') == 3) {
            if (isValidIPv4(IP)) return "IPv4";
        }
        if (std::count(IP.begin(), IP.end(), ':') == 7) {
            if (isValidIPv6(IP)) return "IPv6";
        }
        return "Neither";
    }
private:
    bool isValidIPv4(string& ip) {
        if (ip[ip.size() - 1] == '.') return false;
        vector<string> s;
        string iip = ip + '.';
        int n = iip.size();
        for (int i = 0, j = 0; i < n; ) {
            while (iip[j] != '.') j++;
            s.push_back(iip.substr(i, j - i));
            i = j + 1;
            j = i;
            while (iip[j] == '.') {
                j++;
                i++;
            }
        }
        if (s.size() != 4) return false;
        for (auto& str : s) {
            if (str.size() > 3) return false;
            for (auto& ch : str) {
                if (!isdigit(ch)) return false;
            }
            if (std::stoi(str) > 255) return false;
            if (str.size() > 1 && str[0] == '0') return false;
        }
        return true;
    }

    bool isValidIPv6(string& ip) {
        if (ip[ip.size() - 1] == ':') return false;

        string iip = ip + ":";
        vector<string> s;
        int n = iip.size();
        for (int i = 0, j = 0; i < n; ) {
            while (iip[j] != ':') j++;
            s.push_back(iip.substr(i, j - i));
            i = j + 1;
            j = i;
            while (iip[j] == ':') {
                j++;
                i++;
            }
        }
        if (s.size() != 8) return false;
        for (auto& str : s) {
            for (auto& ch : str) {
                if (isalpha(ch) && !(ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F'))
                    return false;
            }
            if (str.size() > 4) return false;
        }
        return true;
    }
};



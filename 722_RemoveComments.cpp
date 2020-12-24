// 722. Remove Comments
/*
 * 将源码中的注释去除掉. 注释可以是行注释 - //
 // 也可以是块注释 '/* */ */
 */

 class Solution {
 public:
   vector<string> removeComments(vector<string>& source) {
     bool inBlock = false;
     string newline;
     vector<string> ans;
     for (string& str : source) {
       int i = 0;
       if (!inBlock)
         newline = "";

       while (i < str.length()) {
         if (!inBlock && i + 1 < str.length() && str[i] == '/' && str[i+1] == '*') {
           inBlock = true;
           i++;
         } else if (inBlock && i + 1 < str.length() && str[i] == '*' && str[i+1] == '/') {
           inBlock = false;
           i++;
         } else if (!inBlock && i + 1 < str.length() && str[i] == '/' && str[i+1] == '/') {
           break;
         } else if (!inBlock) {
           newline.push_back(str[i]);
         }
         i++;
       }
       if (!inBlock && newline.length() > 0) {
         ans.push_back(newline);
       }
     }
     return ans;
   }
 };


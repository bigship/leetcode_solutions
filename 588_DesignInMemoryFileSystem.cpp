// 588. Design In-Memory File System
/*
 * Design an in-memory file system to simulate the following functions:

ls: Given a path in string format. If it is a file path, return a list that only contains this file's name.
If it is a directory path, return the list of file and directory names in this directory.
Your output (file and directory names together) should in lexicographic order.

mkdir: Given a directory path that does not exist, you should make a new directory according to the path.
If the middle directories in the path don't exist either, you should create them as well.
This function has void return type.

addContentToFile: Given a file path and file content in string format.
If the file doesn't exist, you need to create that file containing given content.
If the file already exists, you need to append given content to original content.
This function has void return type.

readContentFromFile: Given a file path, return its content in string format.
*/

class FileSystem {
public:
  FileSystem() {
    dTable["/"];
  }

  vector<string> ls(string path) {
    vector<string> res;
    if (fTable.find(path) != fTable.end()) {
      int i = path.length() - 1;
      while (i >= 0 && path[i] != '/')
        --i;
      res.push_back(path.substr(i+1));
      return res;
    }

    if (dTable.find(path) != dTable.end()) {
      for (auto& s : dTable[path])
        res.push_back(s);
    }
    return res;
  }

  void mkdir(string path) {
    string prev = "/";
    int prevpos = 1;
    for (int i = 1; i <= path.size(); ++i) {
      if (path[i] == '/' || path[i] == 0) {
        dTable[prev].insert(path.substr(prevpos, i - prevpos));
        prevpos = i + 1;
        prev = path.substr(0, i);
      }
    }
  }

  void addContentToFile(string filePath, string content) {
    int i = filePath.length() - 1;
    while (i >= 0 && filePath[i] != '/')
      --i;
    string path = filePath.substr(0, i);
    string file = filePath.substr(i + 1);
    if (path.empty()) path = "/";
    if (dTable.find(path) == dTable.end())
      mkdir(path);
    fTable[filePath].append(content);
  }

  string readContentFromFile(string filePath) {
    if (fTable.find(filePath) != fTable.end())
      return fTable[filePath];
    return "";
  }
private:
  unordered_map<string, set<string>> dTable;  // dir name to contents
  unordered_map<string, string> fTable;       // file name to contents
};

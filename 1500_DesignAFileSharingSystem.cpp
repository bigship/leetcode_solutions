// 1500. Design a File Sharing System
/*
 * We will use a file-sharing system to share a very large file which consists of m small chunks with IDs from 1 to m.

When users join the system, the system should assign a unique ID to them. The unique ID should be used once for each user, but when a user leaves the system, the ID can be reused again.

Users can request a certain chunk of the file, the system should return a list of IDs of all the users who own this chunk. If the user receive a non-empty list of IDs, they receive the requested chunk successfully.


Implement the FileSharing class:

FileSharing(int m) Initializes the object with a file of m chunks.
int join(int[] ownedChunks): A new user joined the system owning some chunks of the file, the system should assign an id to the user which is the smallest positive integer not taken by any other user. Return the assigned id.
void leave(int userID): The user with userID will leave the system, you cannot take file chunks from them anymore.
int[] request(int userID, int chunkID): The user userID requested the file chunk with chunkID.
Return a list of the IDs of all users that own this chunk sorted in ascending order.


Follow-ups:

What happens if the system identifies the user by their IP address instead of their unique ID and users disconnect and connect from the system with the same IP?
If the users in the system join and leave the system frequently without requesting any chunks, will your solution still be efficient?
If all each user join the system one time, request all files and then leave, will your solution still be efficient?
If the system will be used to share n files where the ith file consists of m[i], what are the changes you have to do?
*/

class FileSharing {
public:
  FileSharing(int m) {

  }

  int join(vector<int> ownedChunks) {
    if (userIDMgr.empty()) {
      userIDMgr[1] = true;
      for (int chunk : ownedChunks) {
        userStoredChunks[1].insert(chunk);
      }
      return 1;
    }

    int usrId = 0;
    auto it = userIDMgr.begin();
    while (it != userIDMgr.end()) {
      if (it->second == false) {
        usrId = it->first;
        it->second = true;
        break;
      }
      it++;
    }

    if (usrId == 0) {
      usrId = std::prev(userIDMgr.end())->first + 1;
      userIDMgr[usrId] = true;
    }

    for (int chunk : ownedChunks) {
      userStoredChunks[usrId].insert(chunk);
    }
    return usrId;
  }

  void leave(int userID) {
    userStoredChunks.erase(userID);
    userIDMgr[userID] = false;
  }

  vector<int> request(int userID, int chunkID) {
    if (userIDMgr.find(userID) == userIDMgr.end())
      return {};
    vector<int> ans;
    for (auto it = userStoredChunks.begin(); it != userStoredChunks.end(); it++) {
      if (it->second.count(chunkID) != 0) {
        ans.push_back(it->first);
      }
    }
    if (!ans.empty()) {
      userStoredChunks[userID].insert(chunkID);
    }

    return ans;
  }
private:
  std::map<int, bool> userIDMgr;
  std::map<int, unordered_set<int>> userStoredChunks;
};


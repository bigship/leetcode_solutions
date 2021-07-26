// 1797. Design Authentication Manager
/*
 * There is an authentication system that works with authentication tokens.
 * For each session, the user will receive a new authentication token that will expire timeToLive seconds after the currentTime.
 * If the token is renewed, the expiry time will be extended to expire timeToLive seconds after the (potentially different) currentTime.

Implement the AuthenticationManager class:

AuthenticationManager(int timeToLive) constructs the AuthenticationManager and sets the timeToLive.
generate(string tokenId, int currentTime) generates a new token with the given tokenId at the given currentTime in seconds.
renew(string tokenId, int currentTime) renews the unexpired token with the given tokenId at the given currentTime in seconds.
If there are no unexpired tokens with the given tokenId, the request is ignored, and nothing happens.
countUnexpiredTokens(int currentTime) returns the number of unexpired tokens at the given currentTime.
Note that if a token expires at time t, and another action happens on time t (renew or countUnexpiredTokens), the expiration takes place before the other actions.
*/

class AuthenticationManager {
public:
  AuthenticationManager(int timeToLive) {
    this->duration = timeToLive;
  }

  void generate(string tokenId, int currentTime) {
    if (tokendb.find(tokenId) == tokendb.end())
      tokendb[tokenId] = {currentTime, currentTime + duration};
  }

  void renew(string tokenId, int currentTime) {
    if (tokendb.find(tokenId) != tokendb.end()) {
      int expireTime = tokendb[tokenId].second;
      if (currentTime < expireTime) {
        tokendb[tokenId].first = currentTime;
        tokendb[tokenId].second = currentTime + duration;
      } else {
        // expires
        tokendb.erase(tokenId);
      }
    }
  }

  int countUnexpiredTokens(int currentTime) {
    int cnt = 0;
    for (auto it = tokendb.begin(); it != tokendb.end(); it++) {
      if (currentTime < it->second.second) {
        cnt++;
      }
    }
    return cnt;
  }
private:
  unordered_map<string, pair<int, int>> tokendb;
  int duration;
};


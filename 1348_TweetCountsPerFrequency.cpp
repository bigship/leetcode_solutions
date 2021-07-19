// 1348. Tweet Counts Per Frequency
/*
 * A social media company is trying to monitor activity on their site by analyzing the number of tweets that occur in select periods of time.
 * These periods can be partitioned into smaller time chunks based on a certain frequency (every minute, hour, or day).

For example, the period [10, 10000] (in seconds) would be partitioned into the following time chunks with these frequencies:

Every minute (60-second chunks): [10,69], [70,129], [130,189], ..., [9970,10000]
Every hour (3600-second chunks): [10,3609], [3610,7209], [7210,10000]
Every day (86400-second chunks): [10,10000]
Notice that the last chunk may be shorter than the specified frequency's chunk size and will always end with the end time of the period (10000 in the above example).

Design and implement an API to help the company with their analysis.

Implement the TweetCounts class:

TweetCounts() - Initializes the TweetCounts object.
void recordTweet(String tweetName, int time) - Stores the tweetName at the recorded time (in seconds).
List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) -
Returns a list of integers representing the number of tweets with tweetName in each time chunk for the given period of time [startTime, endTime] (in seconds) and frequency freq.

freq is one of "minute", "hour", or "day" representing a frequency of every minute, hour, or day respectively.
*/

class TweetCounts {
public:
  TweetCounts() {  }

  void recordTweet(string tweetName, int time) {
    tweets_[tweetName][time]++;
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
    int interval = 60;   // default is minutes
    if (freq == "hour") {
      interval *= 60;
    } else if (freq == "day") {
      interval *= (24 * 60);
    }

    const auto& times = tweets_[tweetName];     // 取引用, 避免拷贝
    vector<int> ans((endTime - startTime) / interval + 1, 0);

    auto begin = times.lower_bound(startTime);
    auto end   = times.upper_bound(endTime);

    while (begin != end) {
      ans[(begin->first - startTime)/ interval] += begin->second;
      begin++;
    }
    return ans;
  }
private:
  std::unordered_map<string, std::map<int, int>> tweets_;
};

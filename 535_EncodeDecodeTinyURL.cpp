// 535. Encode and Decode TinyURL
/*
 * TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl
 * and it returns a short URL such as http://tinyurl.com/4e9iAk.
 * Design the encode and decode methods for the TinyURL service.
 * There is no restriction on how your encode/decode algorithm should work.
 * You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
 */

class Solution {
public:
    string encode(string longUrl) {
        if (full_tiny.find(longUrl) != full_tiny.end())
            return "http://tinyurl.com/" + full_tiny[longUrl];
        string sufix = getTinyUrl();
        full_tiny[longUrl] = sufix;
        tiny_full[sufix] = longUrl;
        return "http://tinyurl.com/" + sufix;
    }

    string decode(string shortUrl) {
        auto it = shortUrl.find_last_of('/');
        string sufix = shortUrl.substr(it+1, 6);
        return tiny_full[sufix];
    }
private:
    unordered_map<string, string> tiny_full;
    unordered_map<string, string> full_tiny;

    string getTinyUrl() {
        static string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, alpha.size() - 1);
        string ret = "";
        for (int i = 0; i < 6; ++i) {
            ret += alpha[distrib(gen)];
        }
        return ret;
    }
};

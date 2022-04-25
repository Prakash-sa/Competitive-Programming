//https://leetcode.com/problems/encode-and-decode-tinyurl/



class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        long_to_short[longUrl] = "http://tinyurl.com/" + to_string(hash_function(longUrl));
        short_to_long[long_to_short[longUrl]] = longUrl;
        return long_to_short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long[shortUrl];
    }
    
private:
    uint64_t hash_function(const string& str) {
        uint64_t hash = 0x811c9dc5;
        uint64_t prime = 0x1000193;

        for(int i = 0; i < str.size(); ++i) {
            uint8_t value = str[i];
            hash = hash ^ value;
            hash *= prime;
        }

        return hash;
    }
    
    unordered_map<string, string> long_to_short;
    unordered_map<string, string> short_to_long;
};

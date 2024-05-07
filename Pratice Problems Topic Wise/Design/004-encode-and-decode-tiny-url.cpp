// https://leetcode.com/problems/encode-and-decode-tinyurl/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, string> mpp;
    long n = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string base = "http://tinyurl.com/" + to_string(n);
        mpp[base]   = longUrl;
        n ++;
        return base;    // encoded url
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
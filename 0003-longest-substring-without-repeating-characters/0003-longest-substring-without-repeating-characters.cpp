class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

       vector<int> hash(256, -1);

        int l = 0, r = 0;

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            maxLen = max(maxLen, r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

/*
class Solution {
public:

// using Map

    unordered_map<char, int> mp;
    int maxLen = 0;

    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int l = 0;
        int r = 0;
        while (r < n) {
            if(mp.find(s[r]) != mp.end()){
               if(mp[s[r]]>=l){
                l=mp[s[r]]+1;
               }
            }
            maxLen = max(maxLen , r-l+1);
            mp[s[r]]=r;
           r++;
        }
        return maxLen;
    }
};
*/

/*
class Solution {
public:

// Brute Force

    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            int hash[256] = {0};
            for (int j = i; j < n; j++) {
                if (hash[s[j]] == 1)
                    break;
                maxlen = max(maxlen, j - i + 1);

                hash[s[j]]++;
            }
        }
        return maxlen;
    }
};

*/
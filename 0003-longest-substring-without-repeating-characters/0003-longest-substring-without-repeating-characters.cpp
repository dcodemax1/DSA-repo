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
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int l = 0, r = 0;
        int hash[26] = {0};
        int maxLen = 0;
        int maxi = 0;

        while (r < n) {
            hash[s[r] - 'A']++;
            maxi = max(maxi, hash[s[r] - 'A']);

            if (r - l + 1 - maxi > k) {
                hash[s[l] - 'A']--;

                l++;
            }
            if(r-l+1-maxi <=k){
                maxLen = max(maxLen , r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};

/*
class Solution {
public:
// Brute Force
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int hash[26] = {0};
            for (int j = i; j < n; j++) {
                hash[s[j] - 'A']++;

                maxi = max(maxi, hash[s[j] - 'A']);
                if (j - i + 1 - maxi <= k) {
                    maxLen = max(maxLen, j - i + 1);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }
};

*/
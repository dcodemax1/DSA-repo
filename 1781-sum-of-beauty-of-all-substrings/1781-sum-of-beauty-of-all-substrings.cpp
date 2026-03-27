class Solution {
public:
    int getMinCount(int freq[]) {
        int minCount = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                minCount = min(minCount, freq[i]);
            }
        }
        return minCount;
    }

    int getMaxCount(int freq[]) {
        int maxCount = INT_MIN;

        for (int i = 0; i < 26; i++) {
            maxCount = max(maxCount, freq[i]);
        }
        return maxCount;
    }

    int beautySum(string s) {
        int n = s.length();
        int beauty = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] ={0} ;
            for (int j = i; j < n; j++) {
                freq[s[j]-'a']++;

               beauty = getMaxCount(freq) - getMinCount(freq);
               sum += beauty;
            }
             
            
        }
        return sum;
    }
};
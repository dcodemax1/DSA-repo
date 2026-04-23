class Solution {
public:

// Optimal Approach 

    string minWindow(string s, string t) {
        int sIndex = -1;
        int minLen = INT_MAX;
        int cnt = 0;
        int n = s.length();
        int m = t.length();
        unordered_map<int,int> mp;
        int l = 0, r= 0;

        for(int i =0; i<m; i++){
            mp[t[i]]++;
        }

        while(r<n){
          if(mp[s[r]]>0){ cnt++;}
          mp[s[r]]--;

          while(cnt==m){
            if(r-l+1 < minLen){
                minLen = r-l+1;
                sIndex = l;
            }
           
            mp[s[l]]++;
            if(mp[s[l]]> 0){
                cnt--;
            }
             l++;
          }
          r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);

    }
};

/*
class Solution {
public:

// Brute Force 

    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int minLen = INT_MAX;
        int sIndex = -1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = 0; j < m; j++) {
                mp[t[j]]++;
            }
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (mp[s[j]] > 0)
                    cnt++;

                mp[s[j]]--;

                if (cnt == m) {
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        sIndex = i;
                    }
                    break;
                }
            }
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};
*/

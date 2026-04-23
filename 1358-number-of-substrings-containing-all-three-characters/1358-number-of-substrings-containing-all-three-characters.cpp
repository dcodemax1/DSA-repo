class Solution {
public:

// Optimal Approach

    int numberOfSubstrings(string s) {
        int n = s.length();
        int lastSeen[3] = {-1, -1, -1};
        int cnt = 0;
       
       for(int i = 0; i<n; i++){
         lastSeen[s[i]-'a'] = i;

         cnt+= 1+ min({lastSeen[0], lastSeen[1], lastSeen[2]});
       }

        return cnt;
    }
};

/*
class Solution {
public:
// Brute Force
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt =0;

        for(int i = 0; i<n; i++){
            int hash[3] = {0};
            for(int j = i; j<n; j++){
             hash[s[j]-'a'] = 1;

             if(hash[0] + hash[1]+hash[2] == 3){
                cnt+= (n-j);
                break;
             }
            }
        }
        return cnt;
    }
};
*/
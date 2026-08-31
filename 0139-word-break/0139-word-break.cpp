class Solution {
public:

    bool solve(int idx, string s , int n, int t[], unordered_set<string>& st){
        if(idx == n){
            return true;
        }

        if(t[idx] != -1){
            return t[idx];
        }

        if(st.find(s) != st.end()) return true;

        for(int i = 1; i<s.length(); i++){
           string temp = s.substr(idx, i);
           if(st.find(temp) != st.end() && solve(idx+i, s, n , t, st)){
            return t[idx] = true;
           }
        }
        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st;

        int t[301];

        memset(t, -1 , sizeof(t));

        for(auto &word : wordDict){
            st.insert(word);
        }

       return solve(0, s, n, t, st);

    }
};
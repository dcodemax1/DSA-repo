class Solution {
public:

    bool solve(int idx, string s, unordered_set<string>& st , int t[]){
        if(idx== s.length()){
            return true;
        }

        if(t[idx] != -1) return t[idx];

        if(st.find(s) != st.end()) return true;

        for(int l = 1; l<s.length(); l++){
                
                string temp = s.substr(idx, l);
               if(st.find(temp) != st.end() && solve(idx+l, s, st, t)){
                return t[idx]= true;
               }
        }

    return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st;
        int t[301];
        memset(t, -1, sizeof(t));

        for(auto & words : wordDict){
            st.insert(words);
        }
        
       return solve(0, s, st, t);
    }
};
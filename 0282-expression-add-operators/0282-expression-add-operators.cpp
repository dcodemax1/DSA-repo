class Solution {
public:
    void solve(string s, int target, int idx, string path, vector<string>& ans,
               long  eval, long residual) {
        if (idx == s.length()) {
            if (eval == target) {
                ans.push_back(path);
                 
            }
            return;
           
        }

        string currStr;
        long num = 0;

        for (int j = idx;j < s.length(); j++) {

            if (j > idx && s[idx] == '0')
                return;

            currStr += s[j];
            num = num * 10 + (s[j] - '0');

            if (idx == 0) {
                solve(s, target, j + 1, path + currStr, ans, num, num);
            } else {
                solve(s, target, j + 1, path + "+" + currStr, ans, eval+num, num);
                solve(s, target, j + 1, path + "-" + currStr, ans, eval-num,-num);
                solve(s, target, j + 1, path + "*" + currStr, ans,
                      (eval - residual + residual * num),  residual*num);
            }
        }
    }

    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        solve(s, target, 0, "", ans, 0, 0); return ans;
    }
};
class Solution {
public:
    void solve(int idx, string s, int target, int n, string path,
               vector<string>& ans, int eval, int resi) {

        if (idx == n) {
            if (eval == target) {
                ans.push_back(path);
            }
            return;
        }

        string currStr;
        long num = 0;

        for (int j = idx; j < n; j++) {
            if (j > idx && s[idx] == '0')
                return;

            currStr += s[j];
            num = num * 10 + (s[j] - '0');

            if (idx == 0) {
                solve(j + 1, s, target, n, path + currStr, ans, num, num);
            } else {
                solve(j + 1, s, target, n, path + "+" + currStr, ans,
                      eval + num, num);

                solve(j + 1, s, target, n, path + "-" + currStr, ans,
                      eval - num, -num);

                solve(j + 1, s, target, n, path + "*" + currStr, ans,
                      (eval - resi) + (resi * num), resi * num);
            }
        }
    }

    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        int n = s.length();

        solve(0, s, target, n, "", ans, 0, 0);
        return ans;
    }
};
/* class Solution {
public:
    string expand(string s, int left, int right, int n, string& ans) {

        while (left >= 0 && right < n) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }

        if (ans.size() < right - left-1) {
            ans = s.substr(left + 1, right - left - 1);
        }
        return ans;
    }

    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            expand(s, i, i, n, ans);
            expand(s, i, i + 1, n, ans);
        }

        return ans;
    }
};

*/

class Solution {
public:
    bool solve(string& s, int i, int j, int t[][1001]) {

        if (i >= j) {
            return 1;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j])
            return t[i][j] = solve(s, i +1, j - 1, t);

        else
            return t[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int maxlen = 0;
        int sp = 0;
        int n = s.length();

        int t[1001][1001];
        memset(t, -1, sizeof(t));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j, t)) {
                    if (j - i + 1 > maxlen) {
                        maxlen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};
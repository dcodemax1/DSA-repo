class Solution {
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
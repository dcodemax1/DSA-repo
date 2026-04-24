class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int min = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                min++;
                max++;
            } else if (s[i] == ')') {
                min--;
                max--;
            } else {
                min--;
                max++;
            }

            if(min<0) min = 0;
            if(max <0) return false;
        }
        return min == 0;
    }
};

// We can do using DP using [ind][cnt] array , because it is changing. TC
// O(N^2).

/*
class Solution {
public:
    // Brute Force

    bool func(string& s, int ind, int cnt) {
        int n = s.length();

        if(cnt <0) return false;

        if (ind == n)
            return cnt == 0;

        if (s[ind] == '(')
            return func(s, ind + 1, cnt + 1);
        if (s[ind] == ')')
            return func(s, ind + 1, cnt - 1);

        return func(s, ind + 1, cnt + 1) || func(s, ind + 1, cnt - 1) ||
               func(s, ind + 1, cnt);
    }

    bool checkValidString(string s) { return func(s, 0, 0); }
};
*/
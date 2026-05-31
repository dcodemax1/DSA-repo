class Solution {
public:

// Better Approach 

    int expand(int start, int end, string s) {
        int count = 0;

        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            count++;
            start--;
            end++;
            
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();

        int count = 0;

        for (int i = 0; i < n; i++) {
            count += expand(i, i, s);
            count += expand(i, i + 1, s);
        }

        return count;
    }
};
/*
class Solution {
public:

// Brute Force

    int checkpalindrome(int start, int end, string s, int n) {
        if (start >= end) {
            return 1;
        }

        if (s[start] != s[end]) {
            return 0;
        }
        return checkpalindrome(start + 1, end - 1, s, n);
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count =0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (checkpalindrome(i, j, s, n)) {
                    count++;
                }
            }
        }
        return count;
    }
};

*/
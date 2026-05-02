class Solution {
public:
    bool alphanum(char ch) {
        if (ch >= '0' && ch <= '9' || tolower(ch) >= 'a' && tolower(ch <= 'z')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;

        while (start < end) {
            if (!alphanum(s[start])) {
                start++;
                continue;
            } else if (!alphanum(s[end])) {
                end--;
                continue;
            }

            else{
                if (tolower(s[start]) != tolower(s[end])) return false;
            }

            start++;
            end--;
        }
        return true;
    }
};
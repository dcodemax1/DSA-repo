class Solution {
public:

// O(n) Better approach 

    int countPalindromicSubsequence(string s) {

        unordered_set<char> letters;
        int result = 0;
        int n = s.length();

        for (char ch : s) {
            letters.insert(ch);
        }

        for (auto letter : letters) {

            int left_idx = -1;
            int right_idx = -1;

            for (int i = 0; i < n; i++) {

                if (s[i] == letter) {
                    if (left_idx == -1) {
                        left_idx = i;
                    } else
                        right_idx = i;
                }
            }
            unordered_set<char> st;

            for (int middle = left_idx + 1; middle <= right_idx - 1; middle++) {
                st.insert(s[middle]);
            }

            result += st.size();
        }

        return result;
    }
};
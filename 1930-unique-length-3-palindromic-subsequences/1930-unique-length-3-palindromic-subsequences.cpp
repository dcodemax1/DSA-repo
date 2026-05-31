class Solution {
public:

// O(n) 2nd Better Approach with pre-computation 

    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> indices(26, {-1, -1});
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (indices[idx].first == -1) {
                indices[idx].first = i;
            }
            indices[idx].second = i;
        }

        int result = 0;
        
        for (int i = 0; i < 26; i++) {
            int left_idx = indices[i].first;
            int right_idx = indices[i].second;

            if (left_idx == -1)
                continue;
           
            unordered_set<char> st;

            for (int middle = left_idx + 1; middle <= right_idx - 1; middle++) {
                st.insert(s[middle]);
            }

            result += st.size();
        }

        return result;
    }
};

/*
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

*/
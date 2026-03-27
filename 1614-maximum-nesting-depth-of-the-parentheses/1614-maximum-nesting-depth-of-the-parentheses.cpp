class Solution {
public:
    int maxDepth(string s) {
        int openBrackets = 0;
        int result = 0;

        for (auto ch : s) {
            if (ch == '(') {
                openBrackets++;
                result = max(result, openBrackets);
            } else if (ch == ')') {
                openBrackets--;
            }
        }
        return result;
    }
};
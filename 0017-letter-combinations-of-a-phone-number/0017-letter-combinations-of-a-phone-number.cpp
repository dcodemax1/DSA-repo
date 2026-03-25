class Solution {
public:

    void solve(int ind, string digits, string path, int n, unordered_map<char, string>& mp, vector<string>& ans){
        if(ind==n){
            ans.push_back(path);
            return;
        }

        char ch = digits[ind];
        string str= mp[ch];

        for(int i = 0; i<str.length(); i++){
            path.push_back(str[i]);
            solve(ind+1, digits, path, n, mp, ans);
            path.pop_back();

        }

    }

    vector<string> letterCombinations(string digits) {

        if(digits.length()==0){
            return {};
        }
        unordered_map<char, string> mp;

        mp['2']= "abc";
        mp['3']= "def";
        mp['4']= "ghi";
        mp['5']= "jkl";
        mp['6']= "mno";
        mp['7']= "pqrs";
        mp['8']= "tuv";
        mp['9']= "wxyz";

        vector<string> ans;
        string path = "";
        int n = digits.length();

        solve(0, digits,path, n, mp, ans);
        return ans;
    }
};
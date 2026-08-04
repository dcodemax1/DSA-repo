class Solution {
public:

// Optimal Approach 

    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for(int i = 0; i<s.length(); i++){
            if(s[i]==')') count--;
            if(count !=0) ans.push_back(s[i]);
            if(s[i]=='(') count++;
            
            
        }
        return ans;
    }
};


/*
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";

        for(auto ch : s){
            if(ch == '('){
                if(!st.empty()){
                    ans+=ch;
                }
                st.push(ch);
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};

*/
class Solution {
public:

    int help(string s, int i, int n,int sign, long long result)
    {

        if(i >=n ||!isdigit(s[i])){
            return sign*result;
        }

            result = result*10+(s[i]-'0');


            if(sign*result >= INT_MAX) return INT_MAX;
            if(sign*result <= INT_MIN) return INT_MIN;
        
        return help(s, i+1, n, sign, result);
    }
    int myAtoi(string s) {
        long long result = 0;
        int n = s.size();
        int i = 0; 

        while(i < n && s[i] == ' ')
        {
            i++;
        }
        
        int sign = 1;

        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }else if(s[i] == '+')
        {
            sign = 1;
            i++;
        }
       
       return help(s, i, n, sign, 0);     
    }
};
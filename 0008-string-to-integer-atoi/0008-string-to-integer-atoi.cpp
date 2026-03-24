class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        if(i == n ) return 0;

        while(i<n && s[i]==' ') {i++;}

        int sign = 1;

        if(s[i]== '-'){
          sign = -1;
          i++;
        }
        else if(s[i]== '+'){
           
            i++;
        }

        long ans = 0;
        int MAX = INT_MAX;
        int MIN = INT_MIN;

        while(i<n && isdigit(s[i])){
            int digit = s[i]-'0';
            ans = ans*10+digit;

           if(sign == 1 && ans > MAX ) return MAX;
           if(sign == -1 && -ans < MIN ) return MIN;

           i++;
        }

        return (int)(sign * ans);
    }
};
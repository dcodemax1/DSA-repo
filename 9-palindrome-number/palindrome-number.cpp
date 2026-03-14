class Solution {
public:
    bool isPalindrome(int x) {
        if(x <0 ) return false;

        int dup = x;
        int revNum =0;

        while(x>0){
       int lastdigit = x%10;
       if(revNum > INT_MAX/10 || revNum < INT_MIN/10) return false;
       revNum = revNum*10+lastdigit;
       x/=10;

        }
        if(dup == revNum) return true;
        else return false;
        
    }
};
class Solution {
public:
// Recustive
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n<=0) return false;
       return n%3 == 0 && isPowerOfThree(n/3);
    }
};


/*
// Brute Force 
    bool isPowerOfThree(int n) {
        if(n<=0) return false;

        while(n%3 == 0){
            n/=3;
        }
        return n==1;
    }
*/
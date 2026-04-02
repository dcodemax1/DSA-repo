class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*  Optimal 
        if(n <= 0)
          return false;

           return ((n & n - 1) == 0);

           */
        if (n == 1)
            return true;
        if (n <= 0)
            return false;

        return n % 2 == 0 && isPowerOfTwo(n / 2);
    }
};

/* Iterative Approach
if(n<=0) return false;

         while(n%2 == 0){
            n/=2;
         }
         return n==1;

         */
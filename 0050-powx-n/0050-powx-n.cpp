class Solution {
public:
    double myPow(double x, int n1) {

        long long n = n1;
        double ans = 1.0;

        if(x== 0) return 0.0;
        if(n1==0) return 1.0;
        if(x==1) return 1.0;
        if(x== -1 && n1%2 == 0) return 1.0;
        if(x== -1 && n1%2== 1) return -1.0;

        if(n < 0){
            x = 1/x;
            n = -n;
        }

        while(n > 0){
            if(n%2==1){
                n= n-1;
                ans*=x;
            }
            else {
                n/=2;
                x*=x;
            }
           
        }
        return ans;
    }
};
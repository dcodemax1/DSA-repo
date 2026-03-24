class Solution {
public:

    const int M = 1e9+7;

    int  findPower ( long long a , long long b){
        long long ans = 1;

        while(b >0){
            if(b%2 == 1){
               b-=1;
            ans = (ans*a)%M;
            }
            else {
                b/=2;
                a  = (a*a)%M;
            }
           
        }
        return ans ;
    }
    int countGoodNumbers(long long n) {

        return ((long long )findPower(5,(n+1)/2) * findPower(4,(n/2)))%M;
        
    }
};
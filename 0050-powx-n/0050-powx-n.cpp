class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if (x == 0)
            return 0.0;
        if (n == 0)
            return 1.0;
        if (x == 1)
            return 1.0;
        if (x == 1 && n % 2 == 0)
            return 1.0;
        if (x == 1 && n % 2 == 1)
            return -1.0;

        long long n1 = n;

        if (n1 < 0) {
            x = 1 / x;
            n1 = -n1;
        }

        while (n1 > 0) {
            if (n1 % 2 == 1) {
                ans *= x;
                n1 -= 1;
            } else if (n1 % 2 == 0) {
                x *= x;
                n1 /= 2;
            }
        }
        return ans;
    }
};
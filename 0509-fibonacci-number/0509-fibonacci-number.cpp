class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;

        int slast = 0;
        int last = 1;
        int curr;

        for (int i = 2; i <= n; i++) {
           curr = slast + last;

            slast = last;
            last = curr;
        }
        return curr;
    }
};
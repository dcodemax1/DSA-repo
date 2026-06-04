class Solution {
public:
    // TC = O(n*n*log(max of gcd))

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int oper = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                count++;
        }

        if (count > 0)
            return n - count;

        for (int i = 0; i < n ; i++) {
            int GD = nums[i];

            for (int j = i +1 ; j < n; j++) {
                GD = gcd(GD, nums[j]);

                if (GD == 1) {
                    oper = min(oper, j - i);
                    break;
                }
            }
        }
        if (oper == INT_MAX)
            return -1;
        return oper + n - 1;
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums, int n, int start, int k, int currSum,
                      int subsetSum, vector<int>& visited) {

        if (k == 0)
            return true;
        if (currSum > subsetSum)
            return false;

        if (currSum == subsetSum) {
            return canPartition(nums, n, 0, k - 1, 0, subsetSum, visited);
        }

        for (int i = start; i < n; i++) {
            if (visited[i])
                continue;

            visited[i] = true;
            if (canPartition(nums, n, i+1, k, currSum+nums[i] , subsetSum, visited)) return true;
                

            visited[i] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;

        for (auto val : nums) {
            total += val;
        }

        if (n < k)
            return false;

        if (total % k != 0)
            return false;
        int subsetSum = total / k;

        vector<int> visited(n, 0);
        return canPartition(nums, n,0, k, 0, subsetSum, visited);
    }
};
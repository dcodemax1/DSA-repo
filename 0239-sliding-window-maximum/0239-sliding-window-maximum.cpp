class Solution {
public:
// Optimal Approach
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ls;

        for(int i =0; i<n; i++){
            if(!dq.empty() && dq.front() < i-k+1){
                dq.front();
            }
            
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
         
         dq.push_back(i);

         if(i>=k-1){
            ls.push_back(nums[dq.front()]);
         }
        }
        return ls;
    }
};

/*
class Solution {
public:
// Brute Force 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        vector<int> ls;
        for (int i = 0; i <= n - k; i++) {
            maxi = nums[i];
            for (int j = i; j <= i + k - 1; j++) {
                maxi = max(maxi, nums[j]);
            }
            ls.push_back(maxi);
        }
        return ls;
    }
};

*/
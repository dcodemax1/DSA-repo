class Solution {
public:

// Better 2nd Approach 
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i<n; i++){
            pq.push(nums[i]);

            if(pq.size() > k){
                pq.pop();
            }
        }
     return pq.top();

    }
};

/*
// Better Approach

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }

        for (int i = 1; i < k; i++) {
            pq.pop();
        }

        return pq.top();
    }
};
*/

/*
// Brute Force

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k - 1];
    }
};

*/

class Solution {
public:

    int first(vector<int>& nums, int target){
        int low =0, high  = nums.size()-1; 
        int ans = -1;

        while(low<= high){
            int mid = low+(high-low)/2;

            if(nums[mid]== target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }

     int last(vector<int>& nums, int target){
        int low =0, high  = nums.size()-1; 
        int ans = -1;

        while(low<= high){
            int mid = low+(high-low)/2;

            if(nums[mid]== target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int firsttt = first(nums, target);
        if(firsttt == -1) return {-1,-1};
        int lasttt = last(nums, target);

        return {firsttt,lasttt};
    }
        
        
    
};
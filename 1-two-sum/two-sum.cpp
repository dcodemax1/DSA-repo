class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i = 0; i<nums.size(); i++){
            int rem = target- nums[i];

           if( mp.find(rem)!= mp.end()){
            return {mp[rem], i};
           }
           mp[nums[i]]=i;

        }
        return{-1,-1};
    }
};
class Solution {
public:
    using ll=long long;
    vector<ll>minOperations(vector<int>&nums,vector<int>&queries){
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<ll>pref(n);
        pref[0]=nums[0];

        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }

        vector<ll>ans;

        for(int q:queries){

            int idx=lower_bound(nums.begin(),nums.end(),q)-nums.begin();

            ll left=(ll) q*idx-(idx>0 ? pref[idx-1] : 0);
            ll right=(pref[n-1]-(idx>0 ? pref[idx-1] : 0)) - (ll) q*(n-idx);

            ans.push_back(left + right);

        }

        return ans;
    }
};
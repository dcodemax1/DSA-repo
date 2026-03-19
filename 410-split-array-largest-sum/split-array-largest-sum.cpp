class Solution {
public:

    int canValid(vector<int>& arr, int k){
    int subarray =1;
    int subarraySum = 0;
    int n = arr.size();

    for(int i =0; i<n; i++){
        if(subarraySum+arr[i]<=k){
            subarraySum+=arr[i];
        }
        else{
            subarray++;
            subarraySum= arr[i];
        }

   
    }
    return subarray;
}

    int splitArray(vector<int>& arr, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);

   while(low<= high){
    int mid = low+(high-low)/2;

    if(canValid(arr, mid)>k){
        low = mid+1;
    }
    else{
        high= mid-1;
    }
   }
   return low;
        
    }
};
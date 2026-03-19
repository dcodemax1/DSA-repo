class Solution {
public:

bool binaryserach(vector<int>& arr, int m, int target){
    int low = 0, high = m-1;

    while(low<= high){
        int mid = low+(high -low)/2;

        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid]< target){
         low = mid+1;
        }
        else {
            high = mid -1;
        }
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n= arr.size();
        int m = arr[0].size();

        for(int i = 0; i<n; i++){

            if(arr[i][0]<= target && target <= arr[i][m-1]){
                return binaryserach(arr[i],m, target);
            }
        }
        return false;
    }
};
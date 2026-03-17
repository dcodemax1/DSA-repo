class Solution {
public:

int merge(vector<int>& arr , int low, int mid, int high ){
  int left = low, right = mid+1;

  vector<int> temp;

  int cnt =0;

  while(left<=mid && right <= high){
    if(arr[left] <= arr[right]){
      temp.push_back(arr[left]);
      left++;
    }
    else{
      temp.push_back(arr[right]);
      cnt+= (mid-left+1);
      right++;
    }
  }

  while(left <=mid){
    temp.push_back(arr[left]);
    left++;
  }

  while(right <= high){
    temp.push_back(arr[right]);
    right++;
  }
for(int i = low; i<=high; i++){
  arr[i]= temp[i-low];
}

  return cnt;
}

int coutPairs(vector<int>& arr , int low,int mid, int high){
    int cnt = 0;
    int right = mid+1;
    for(int i = low; i<=mid; i++){
        while(right<=high && arr[i]> 2LL* arr[right]) right++;
        cnt+=(right- (mid+1));
    }
    return cnt;
}

int mergeSort(vector<int>& arr , int low, int high){
  int cnt = 0;
  if(low >= high ) return 0;
  int mid = low+(high-low)/2;

 cnt+= mergeSort(arr, low, mid);
 cnt+= mergeSort(arr, mid+1,high);
 cnt+= coutPairs(arr, low, mid, high);
  merge(arr, low, mid, high);
 return cnt;
}
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n-1);

    }
};
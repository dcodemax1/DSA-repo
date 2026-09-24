class Solution {
public:

    bool possible(vector<int>& bloomDay, int m, int k,int n, int day){
        
        int cnt =0;
        int no_of_bouquets = 0;

        for(int i = 0; i<n; i++){
            if(bloomDay[i]<= day){
                cnt++;
            }
            else {
                no_of_bouquets+= cnt/k;
                cnt = 0;
            }

        }
        no_of_bouquets += cnt/k;
        if(no_of_bouquets >=m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long totalFlowers = m*1LL*k*1LL;
        if(totalFlowers > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

       while(low<= high){
        int mid= low+(high - low)/2;

        if(possible(bloomDay, m, k, n, mid)== true){
            
            high = mid-1;
        }
        else {
            low = mid+1;
        }
       }
       return low;
       
    }
};
class Solution {
public:

    long long  findHours (vector<int>& piles, int hour){
        long long  totalHours =0;

        for(auto x : piles ){
            totalHours += (x+hour-1)/hour;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        long long reqtime = 0;

        while(low<= high){

            int mid = low+(high - low)/2;
            reqtime = findHours(piles, mid);

            if(reqtime <= h){
                high = mid-1;
            }
            else {
                low = mid+1;
            }

        }
        return low;
    }
};
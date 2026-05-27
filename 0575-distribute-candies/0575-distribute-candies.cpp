class Solution {
public:

// Better Approach 

    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());

        int n = candyType.size();
        int i = 0;
        int j = 1;
        int count = 1;

        while (j < n) {
            if (candyType[i] == candyType[j]) {
                j++;
            } else {
                count++;
                i = j;
                j++;
            }
        }
        if (count > n / 2) {
            return n / 2;
        }

        return count;
    }
};

/*
// Brute Force

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        int n = candyType.size();
        set<int> s;

        for(auto x : candyType){
            s.insert(x);
        }

        return min(n/2, (int)s.size());
    }
};

*/
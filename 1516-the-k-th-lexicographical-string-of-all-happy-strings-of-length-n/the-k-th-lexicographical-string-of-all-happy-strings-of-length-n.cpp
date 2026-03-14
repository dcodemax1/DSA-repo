class Solution {
public:
    string getHappyString(int n, int k) {

        int total = 3 * (1 << (n-1));

        if(k > total) return "";

        string res = "";
        vector<char> chars = {'a','b','c'};

        for(int i=0;i<n;i++){

            int block = 1 << (n-i-1);

            for(char c : chars){

                if(!res.empty() && res.back()==c)
                    continue;

                if(k > block)
                    k -= block;
                else{
                    res.push_back(c);
                    break;
                }
            }
        }

        return res;
    }
};
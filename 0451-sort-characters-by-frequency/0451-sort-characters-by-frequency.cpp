class Solution {
public:
    typedef pair<char, int> p;
    string frequencySort(string s) {
        vector<p> vec(123);

        for (char& ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq + 1};
        }

        auto comp = [&](p& p1, p& p2) { return p1.second > p2.second; };

        sort(vec.begin(), vec.end(), comp);

        string result = "";
        for (int i = 0; i < 123; i++) {

            int freq = vec[i].second;
            char ch = vec[i].first;

            string temp = string(freq, ch);
            result += temp;
        }
        return result;
    }
};
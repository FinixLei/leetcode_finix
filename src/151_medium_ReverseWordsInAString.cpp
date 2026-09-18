class Solution {
public:
    string reverseWords(string s) {
        const int size = s.size();
        if (size <= 0) return s;

        vector<pair<int, int>> words_range;
        int start=-1;
        int i = 0;
        for (; i<size; i++) {
            if (s[i] != ' ') {
                if (start == -1) start = i;
            }
            else {  // s[i] == ' '
                if (start == -1) continue;
                else {
                    words_range.push_back(make_pair(start, i));
                    start = -1;
                }
            }
        }
        if (start != -1) {
            words_range.push_back(make_pair(start, i));
        }
        
        string result = "";
        const int wr_size = words_range.size();
        for (int i=wr_size-1; i>=0; i--) {
            int beg = words_range[i].first;
            int end = words_range[i].second;
            for (int j=beg; j<end; j++) result.push_back(s[j]);
            result.push_back(' ');
        }
        const int rsize = result.size();
        if (rsize > 0 && result[rsize-1] == ' ') result.pop_back();
        return result;
    }
};
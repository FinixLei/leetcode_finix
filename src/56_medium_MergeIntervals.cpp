class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int size = intervals.size();
        if (size <= 1) return intervals;

        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        
        vector<vector<int>> result;
        int p1 = 0, p2 = 1;
        int p1_left  = intervals[p1][0];
        int p1_right = intervals[p1][1];

        while (true) {
            if (p1_right < intervals[p2][0]) {  // cannot merge
                result.push_back({p1_left, p1_right});
                p1 = p2;
                p1_left  = intervals[p1][0];
                p1_right = intervals[p1][1];
                p2 ++;
                if (p2 >= size) {
                    result.push_back({p1_left, p1_right});
                    break;
                }
            } 
            else { // p1_right >= p2_left, so mergable
                p1_right = max(p1_right, intervals[p2][1]);
                if (p2 == size-1) {
                    result.push_back({p1_left, p1_right});
                    break;
                }
                else {
                    p2 ++;
                }
            }
        }
        return result;
    }
};
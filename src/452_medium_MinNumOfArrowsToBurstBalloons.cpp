class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {        
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        const int size = points.size();
        vector<vector<int>> overlap = {points[0]};

        for (int i=1; i<size; i++) {
            int oidx = overlap.size() - 1;
            if (overlap[oidx][1] >= points[i][0]) {
                overlap[oidx][0] = max(overlap[oidx][0], points[i][0]);
                overlap[oidx][1] = min(overlap[oidx][1], points[i][1]);
            } 
            else {
                overlap.push_back(points[i]);
            }
        }
        return overlap.size();
    }
};
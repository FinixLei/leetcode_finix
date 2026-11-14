class Solution {
private:
    void search(int k, int n, int start, vector<int>& res, vector<vector<int>>& final_res) {
        if (k == 1) {
            if (start <=n && n <= 9) {
                res.push_back(n);
                final_res.push_back(res);
                res.pop_back();
                return;
            }
            return;
        }
        for (int i=start; i<9; i++) { 
            res.push_back(i);
            search(k-1, n-i, i+1, res, final_res);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> final_res;
        vector<int> res;
        search(k, n, 1, res, final_res);
        return final_res;
    }
};

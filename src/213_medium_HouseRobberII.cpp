class Solution {
private:
    int rob_range(vector<int>& nums, int begin, int end) {
        const int size = nums.size();
        if (begin > end || begin<0 || end<0 || begin>=size || end >=size) {
            throw runtime_error("Wrong parameter begin and/or end");
        }
        if (begin == end) return nums[begin];
        if (begin+1 == end) return max(nums[begin], nums[end]);

        vector<int> dp(end-begin+1, 0);
        dp[0] = nums[begin];
        dp[1] = max(nums[begin], nums[begin+1]);
        for(int i=2; i<end-begin+1; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[begin+i]);
        }
        return dp[end-begin];
    }
public:
    int rob(vector<int>& nums) {
        const int size = nums.size();
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        int res1 = rob_range(nums, 0, size-2);
        int res2 = rob_range(nums, 1, size-1);
        return max(res1, res2);
    }
};

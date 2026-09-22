class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int size = nums.size();
        int i=0, j=0;
        int wsum = nums[0];
        int minCount = size + 1;

        while (true) {
            if (wsum >= target) {
                if (i == j) return 1;
                if (j-i+1 < minCount) minCount = j-i+1;
                wsum -= nums[i++];
            }
            else {
                j ++;
                if (j >= size) break;
                wsum += nums[j];
            }
        }

        return minCount == size+1 ? 0 : minCount;
    }
};
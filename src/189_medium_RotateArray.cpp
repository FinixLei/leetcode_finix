class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int size = nums.size();
        if (size <= 1) return;
        k = k % size;

        vector<int> tmp(k, 0);
        for (int i=size-k, j=0; i<size; i++, j++) {
            tmp[j] = nums[i];
        }

        for (int i=size-1; i>=k; i--) {
            nums[i] = nums[i-k];
        }
        copy(tmp.begin(), tmp.end(), nums.begin());
    }
};
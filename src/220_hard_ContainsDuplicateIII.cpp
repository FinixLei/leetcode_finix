class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;
        unordered_map<long long, long long> bucket;
        long long w = (long long)valueDiff + 1;
        for (int i = 0; i < nums.size(); ++i) {
            long long x = nums[i];
            long long id = getID(x, w);
            // 同桶存在(之前有元素在桶里了，和当前元素nums[i]满足条件)
            if (bucket.count(id)) return true;
            // 检查左边桶
            if (bucket.count(id - 1) && x - bucket[id - 1] <= valueDiff) return true;
            // 检查右边桶
            if (bucket.count(id + 1) && bucket[id + 1] - x <= valueDiff) return true;
            bucket[id] = x;
            // 滑动窗口，移除超出k范围的元素
            if (i >= indexDiff) {
                bucket.erase(getID(nums[i - indexDiff], w));
            }
        }
        return false;
    }
    // 处理负数的桶编号
    long long getID(long long x, long long w) {
        return x >= 0 ? x / w : (x + 1) / w - 1;
    }
};


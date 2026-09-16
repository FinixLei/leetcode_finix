class Solution {
public:
int majorityElement(vector<int>& nums) {
    const int size = nums.size();
    int candidate = 0, count = 0;
    for (int n : nums) {
        if (count == 0) {
            candidate = n;
        }
        if (candidate == n) count ++;
        else count --;
    }
    return candidate;
}
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> vec;
        int start = 0, end = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) end ++;
            else {
                stringstream ss;
                if (end > start) ss << nums[start] << "->" << nums[end];
                else ss << nums[end];
                vec.push_back(ss.str());
                start = end = i;
            }
        }
        stringstream ss;
        if (start == end) ss << nums[end];
        else ss << nums[start] << "->" << nums[end];
        vec.push_back(ss.str());
        return vec;
    }
};

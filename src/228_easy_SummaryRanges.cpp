class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        const int size = nums.size();
        stringstream ss;

        int start = -1;
        for (int i=0; i<size; i++) {
            if (start < 0) {
                start = i;
                if (i == size-1) {
                    ss.str("");
                    ss.clear();
                    ss << nums[i];
                    vec.push_back(ss.str());
                    break;
                } else {
                    if (long(nums[i+1]) - long(nums[i]) != 1) {
                        ss.str("");
                        ss.clear();
                        ss << nums[i];
                        vec.push_back(ss.str());
                        start = -1;
                    }
                }
            } else {
                if (i == size-1 || long(nums[i+1]) - long(nums[i]) != 1) {
                    ss.str("");
                    ss.clear();
                    ss << nums[start] << "->" << nums[i];
                    vec.push_back(ss.str());
                    start = -1;
                }
            }
        }
        return vec;
    }
};
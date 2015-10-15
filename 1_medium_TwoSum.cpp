/*
    Given an array of integers, find two numbers such that they add up to a specific target number.

    The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

    You may assume that each input would have exactly one solution.

    Input: numbers={2, 7, 11, 15}, target=9
    Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        struct DATA {
            int value;
            int ori_index;
        };
        
        const int size = nums.size();
        DATA struct_nums[size];
        
        int i = 0;
        for (auto it=nums.begin(); it!=nums.end(); it++) {
            struct_nums[i].value = *it;
            struct_nums[i].ori_index = i + 1;
            i++;
        }
        
        sort(&struct_nums[0], &struct_nums[0] + size, [](DATA d1, DATA d2){return d1.value < d2.value;});
        
        vector<int> result;
        for (int i=0; i<size-1; i++) 
            for (int j=i+1; j<size; j++) {
                if (struct_nums[i].value + struct_nums[j].value == target) {
                    int min_index = min(struct_nums[i].ori_index, struct_nums[j].ori_index);
                    int max_index = max(struct_nums[i].ori_index, struct_nums[j].ori_index);
                    result.push_back(min_index);
                    result.push_back(max_index);
                } 
                else if (struct_nums[i].value + struct_nums[j].value > target) {
                    break;
                }
            }
        
        return result;
    }
};

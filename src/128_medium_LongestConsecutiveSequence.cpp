/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return nums.size();
        
        unordered_map<int, vector<int>> mymap;
        vector<bool> visited(nums.size(), false);
        int finalResult = -1;
        
        for (int i=0; i<nums.size(); i++) {
            if (mymap.count(nums[i]) > 0) {
                mymap[nums[i]].push_back(i);
            }
            else {
                mymap[nums[i]] = {i};
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            
            int tmpResult = 1;
            int val = nums[i];
            while (true) {
                val++;
                if (mymap.find(val) != mymap.end()) {
                    tmpResult ++;
                    
                    vector<int> ids = mymap[val];
                    for (auto id : ids) {
                        visited[id] = true;
                    }
                }
                else {
                    break;
                }
            }
            
            val = nums[i];
            while (true) {
                val--;
                if (mymap.find(val) != mymap.end()) {
                    tmpResult ++;
                    
                    vector<int> ids = mymap[val];
                    for (auto id : ids) {
                        visited[id] = true;
                    }
                }
                else {
                    break;
                }
            }
            
            finalResult = tmpResult > finalResult ? tmpResult : finalResult;
        }
        
        return finalResult;
    }
};

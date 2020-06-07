/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
*/

#include <vector>
#include <iostream>
using namespace std;

int jump(vector<int>& nums)
{
    if (nums.size() == 1) return 0;
    
    unsigned int target_index = nums.size()-1;
    
    unsigned int min_pos = 1;
    unsigned int max_pos = nums[0];
    unsigned int next_min_pos = -1;
    unsigned int next_max_pos = 0;
    unsigned int temp_pos = 0;
    int count = 1;
    
    while (true) 
    {
        next_min_pos = max_pos + 1;
        next_max_pos = 0;
        if (target_index <= max_pos) return count;
        
        for (int i=min_pos; i<=max_pos; i++)
        {
            temp_pos = i + nums[i];

            if (temp_pos >= target_index) {
                return ++count;
            }
            
            if (temp_pos > next_max_pos) next_max_pos = temp_pos; 
        }

        count += 1;
        min_pos = next_min_pos;
        max_pos = next_max_pos;
    }
    
    return count; 
}


int main()
{
    int result = 0;
    
    vector<int> vec1{2,3,1,1,4};
    result = jump(vec1);
    cout << "result = " << result << endl;
    
    vector<int> vec2{4, 7, 5, 3, 2, 1, 4, 2, 1, 1, 1, 0};
    result = jump(vec2);
    cout << "result = " << result << endl;  // 4
    
    vector<int> vec3{0};
    result = jump(vec3);
    cout << "result = " << result << endl;
    
    vector<int> vec4{1, 2};
    result = jump(vec4);
    cout << "result = " << result << endl;
    
    vector<int> vec5{1, 1, 1, 1};
    result = jump(vec5);
    cout << "result = " << result << endl;  // 3
    
    
    vector<int> vec6{1,9,7,9,5,1,5,7,3,6,4,5,9,1,3,4,2,6,9,5};
    result = jump(vec6);
    cout << "result = " << result << endl;  // 4
    
    return 0;
}

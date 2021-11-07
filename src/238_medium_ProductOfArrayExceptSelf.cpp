/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] 
is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not 
count as extra space for the purpose of space complexity analysis.)
*/

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print_vector(const vector<T>& vec) {
    for (auto i:vec) cout << i << " ";
    cout << endl;
}

vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> pre(nums.size());
    int p = 1;
    for (int i=0; i<nums.size(); i++) {
        pre[i] = p;
        p = p * nums[i];
    }
    
    vector<int> post(nums.size());
    p = 1;
    for (int i=nums.size()-1; i>=0; i--) {
        post[i] = p;
        p = p * nums[i];
    }
    
    for (int i=0; i<nums.size(); i++) {
        pre[i] = pre[i] * post[i];
    }
    return pre;
}

vector<int> productExceptSelf_way2(vector<int>& nums) {
    vector<int> result(nums.size());
    long all = 1;
    for (auto i : nums) {
        all *= i;
    }
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] != 0) result[i] = all / nums[i];
        else {
            result[i] = 1;
            for (int j=0; j<nums.size(); j++) {
                if (j!=i) result[i] *= nums[j];
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    print_vector(result);
    return 0;
}

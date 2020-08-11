/*
    Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

    Note:

    The solution set must not contain duplicate quadruplets.

    Example:

    Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

    A solution set is:
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
void printvec(vector<T> vec) {
    for (auto i : vec) { cout << i << " "; }
    cout << endl;
}

template <typename T>
void printvec2d(vector<vector<T>>& vec2d) {
    for (auto vec : vec2d) {
        for (auto i : vec) { cout << i << " "; }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (j == i) {
                j ++;
                continue;
            }
            
            int t=j+1, k=n-1;
            while (t < k) {
                if (t == i || t == j) {
                    t ++; 
                    continue;
                }
                if (k == i || k == j) {
                    k --;
                    continue;
                }
                
                int sum = nums[i]+nums[j]+nums[t]+nums[k];
                
                if (sum == target) {
                    vector<int> item {nums[i], nums[j], nums[t], nums[k]};
                    sort(item.begin(), item.end());
                    result.push_back(item);
                    t++;
                    continue;
                }
                else if (sum < target) {
                    t ++;
                    while (t < k && nums[t] == nums[t-1]) t++;
                }
                else if (sum > target) {
                    k --;
                    while (t < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
    }
    
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    return result; 
}

int main()
{
    vector<int> nums;
    int target = 0;
    vector<vector<int>> result;
    
    nums = {1, 0, -1, 0, -2, 2};
    printvec(nums);
    result = fourSum(nums, target);
    printvec2d(result);
    
    nums = {-3,-2,-1,0,0,1,2,3};
    printvec(nums);
    result = fourSum(nums, target);
    printvec2d(result);

    return 0;
}

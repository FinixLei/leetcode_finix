/**
  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
  Return the sum of the three integers. You may assume that each input would have exactly one solution.
  For example, given array S = {-1 2 1 -4}, and target = 1.
  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int threeSumClosest_way1(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    
    int dist = 99999;
    int sum = -1;
    int size = nums.size();
    
    for (int i=0; i<size-2; ++i) {
        for (int j=i+1; j<size-1; ++j) {
            for (int k=j+1; k<size; ++k) {
                int tmp_sum = nums[i] + nums[j] + nums[k];
                int tmp_dist = tmp_sum - target; 
                
                if (tmp_dist > 0) {
                    if (tmp_dist < dist) {
                        dist = tmp_dist;
                        sum = tmp_sum;
                    }
                    else
                        break;
                }
                else if (tmp_dist < 0) {
                    if (-tmp_dist < dist) {
                        dist = - tmp_dist;
                        sum = tmp_sum;
                    }
                }
                else { // tmp_dist = 0
                    return target;
                }
            }
        }
    }
    
    return sum;
}

int threeSumClosest_way2(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    
    int distance = 9999;
    // int size = nums.size();
    // 
    // int start = 0;
    // int end = size - 1;
    // int third = 1;
    // 
    // for (int i=0; i<size-2; ++i) {
    //     for (int j=i+1; j<size-1; ++j) {
    //         for (int k=j+1; k<size; ++k) {
    //             int tmp = nums[i] + nums[j] + nums[k] - target; 
    //             tmp = tmp > 0 ? tmp : -tmp; 
    //             if (tmp < distance) {
    //                 distance = tmp;
    //             }
    //         }
    //     }
    // }
    
    return distance;
}

int main() 
{
    vector<int> vec = {10, 20, 30, 13, 15, 17, 22, 58};
    // vector<int> vec = {0, 0, 0};
    int target = 1000;
    
    int result = threeSumClosest_way1(vec, target);
    cout << "result = " << result << endl;
    
    return 0;
}
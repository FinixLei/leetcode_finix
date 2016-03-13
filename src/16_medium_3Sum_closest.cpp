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

int threeSumClosest_way1(vector<int>& nums, int target) {  // my own way, pass, 286ms
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

int threeSumClosest_way2(vector<int>& nums, int target) { // reference to haochen, pass, 12ms
    sort(nums.begin(), nums.end());
    
    int dist = 2147483647;
    int sum = -1;
    int size = nums.size();
    
    for (int i=0; i<size-2; ++i) {
        int low = i + 1;
        int high = size - 1;
        int a = nums[i];
        
        while (low < high) {
            int b = nums[low];
            int c = nums[high];
            
            int tmp_sum = a + b + c;
            int tmp_dist = abs(target - tmp_sum);
            
            if (tmp_dist == 0) {
                return target;
            }
            else {
                if (tmp_dist < dist) {
                    dist = tmp_dist;
                    sum = tmp_sum;
                }
                
                if (tmp_sum - target > 0)
                    --high;
                else
                    ++low;
            }
        }
    }
    
    return sum;
}

int main() 
{
    vector<int> vec = {1,2,4,8,16,32,64,128};
    // vector<int> vec = {0, 0, 0};
    int target = 82;
    
    int result = threeSumClosest_way2(vec, target);
    cout << "result = " << result << endl;
    
    return 0;
}
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/


#include <iostream>
#include <vector>
using namespace std;


int trap(vector<int>& h) 
{
    int left = 0, right = h.size()-1;
    int sum = 0;
    int current_max = 0;
    int lower = 0;
    
    while (left < right) {
      if (h[left] < h[right]) {
          lower = h[left++];
      }
      else {
          lower = h[right--];
      }
      current_max = max(current_max, lower);
      sum += current_max - lower; 
    }
    return sum; 
}


int main()
{
    // int array[] = {5, 2, 1, 2, 1, 5};  // 14
    // int array[] = {0,1,0,2,1,0,1,3,2,1,2,1};  // 6
    // int array[] = {4,2,3};  // 1
    // int array[] = {4,2,0,3,2,4,3,4};  // 10
    // int array[] = {4,4,4,7,1,0};  // 0
    int array[] = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};  // 83
    
    vector<int> vec(array, array+sizeof(array)/sizeof(int));
    cout << trap(vec) << endl;
    return 0;
}

// Way-2. 动态规划法

class Solution {
public:
    int trap(vector<int>& height) {
        const int size = height.size();
        if (size == 0) return 0;

        vector<int> left_most(size, -1);
        vector<int> right_most(size, -1);

        left_most[0] = height[0];
        for (int i=1; i<size; i++) {
            left_most[i] = max(left_most[i-1], height[i]);
        }

        right_most[size-1] = height[size-1];
        for (int i=size-2; i>=0; i--) {
            right_most[i] = max(right_most[i+1], height[i]);
        }

        int water = 0;
        for (int i=0; i<size; i++) {
            water += (min(left_most[i], right_most[i]) - height[i]);
        }
        return water;
    }
};
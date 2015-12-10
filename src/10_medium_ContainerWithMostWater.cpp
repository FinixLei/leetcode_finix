/*
    Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

    Note: You may not slant the container.
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_num = -1;
    
    while (left < right) {
        int area = (right - left) * min(height[left], height[right]);
        max_num = max_num < area ? area : max_num;
        
        if (height[left] < height[right]) {
            do {
                left ++;
            } while (left < right && height[left-1] >= height[left]);
        }
        else {
            do {
                right --;
            } while (left < right && height[right+1] >= height[right]);
        }
    }
    
    return max_num;
}

int main() {
    // vector<int> height = {10,14,10,4,10,2,6,1,6,12};
    // vector<int> height = {1, 1};
    vector<int> height = {5,2,12,1,5,3,4,11,9,4};
    
    int result = maxArea(height);
    std::cout << "The result is " << result << std::endl;
    
    return 0;
}
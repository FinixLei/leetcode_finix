/**
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> threeSum_way1(vector<int>& nums) {  // way 1 will time out 
    vector<vector<int>> result; 
    sort(nums.begin(), nums.end());
    
    set<int> set_nums;
    for (auto i : nums) {
        set_nums.insert(i);
    }
    
    set<vector<int>> set_result;
    
    int size = nums.size();
    for (int i=0; i<size-2; ++i) 
        for (int j=i+1; j<size-1; ++j) {
            int target = 0 - nums[i] - nums[j];
            if (target < nums[j]) {
                continue;
            }
            if (set_nums.find(target) != set_nums.end()) {
                vector<int> temp = {nums[i], nums[j], target};
                set_result.insert(temp);
            }
        }
                
    for (auto it = set_result.begin(); it != set_result.end(); it ++) {
        result.push_back(*it);
    }
    return result;
}

vector<vector<int>> threeSum_way2(vector<int>& num) {
    vector< vector<int> > result;

    //sort the array, this is the key
    sort(num.begin(), num.end());

    int n = num.size();

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        int a = num[i];
        int low = i+1;
        int high = n-1;
        while ( low < high ) {
            int b = num[low];
            int c = num[high];
            if (a+b+c == 0) {
                //got the soultion
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                // Continue search for all triplet combinations summing to zero.
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++; 
                while(high>0 && num[high]==num[high-1]) high--; 
                low++;
                high--;
            } else if (a+b+c > 0) {
                //skip the duplication
                while(high>0 && num[high]==num[high-1]) high--;
                high--;
            } else{
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                low++;
            } 
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, -4, 0, 2, 1, -1};
    
    vector<vector<int>> result = threeSum_way2(nums);
    for (auto array : result) {
        for (auto i : array) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
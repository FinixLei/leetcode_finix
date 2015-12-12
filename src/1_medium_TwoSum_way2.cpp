#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    std::map<int, int> cache;
    
    for (int i=0; i<nums.size(); ++i) {
        cache[nums[i]] = i;
    }
    
    for (int i=0; i<nums.size(); ++i) {
        int need = target - nums[i];
        if (cache.count(need) > 0 && cache[need] != i) {
            vector<int> result{i+1, cache[need]+1};
            return result;
        }
    }
    
    vector<int> result{-1, -1};
    return result;
}

int main () {
    vector<int> array = {3, 2, 4};
    int target = 6;
    
    vector<int> result = twoSum(array, target);
    std::cout << "Result is: " << result[0] << ", " << result[1] << std::endl;
    
    return 0;
}
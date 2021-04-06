#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void print_vec(vector<int>& vec)
{
    for (auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;
}


void sortColors(vector<int>& nums) 
{
    unordered_map<int, int> mymap;
    for (int v : nums) {
        if (mymap.find(v) == mymap.end()) {
            mymap.insert(std::make_pair(v, 1));
        }
        else {
            mymap[v] += 1;
        }
    }
    
    vector<int> tmp;
    tmp.reserve(nums.size());
    
    for (int i=0; i<3; ++i) {
        if (mymap.find(i) == mymap.end()) continue; 
        
        int count = mymap[i];
        for (int j=0; j<count; j++) {
            tmp.push_back(i);
        }
    }
    
    nums = tmp; 
}

int main()
{
    vector<int> nums{2,0,2,1,1,0}; 
    sortColors(nums);
    print_vec(nums);
    
    return 0;
}
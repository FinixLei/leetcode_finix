/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


void print_vec(vector<string>& vec) {
    for (auto s : vec) {
        cout << s << " ";
    }
    cout << endl;
}

void print_vec2d(vector<vector<string>>& vec2d) {
    for (auto v : vec2d) {
        print_vec(v);
    }
    cout << endl;
}

vector<vector<string>> groupAnagrams_old(vector<string>& strs) {
    map<string, vector<string>> mymap;
    
    for (int i=0; i<strs.size(); i++) {
        vector<int> nums;  // convert this string to numbers and store them 
        for (auto ch : strs[i]) {
            nums.push_back(char(ch) - 'a');
        }
        sort(nums.begin(), nums.end());
        
        string key = "";
        for(auto n : nums) {
            char tc[4] = {0,0,0,0};
            sprintf(tc, "_%d", n);
            key.append(tc);
        }
        
        auto iter = mymap.find(key);
        if (iter == mymap.end()) {
            vector<string> tmpvec{strs[i]}; 
            mymap.insert(make_pair(key, tmpvec));  // mymap[key] = tmpvec;
        }
        else {
            mymap[key].push_back(strs[i]);
        }
    }
    
    vector<vector<string>> result;
    for (auto mi : mymap) {
        result.push_back(mi.second);
    }
    return result;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result; 
    unordered_map<string, vector<string>> myhash;
    
    for (int i=0; i<strs.size(); i++) {
        string tmpstr = strs[i];
        sort(tmpstr.begin(), tmpstr.end());  // sort a string 
        myhash[tmpstr].push_back(strs[i]);
    }
    for (auto item : myhash) {
        result.push_back(item.second);
    }
    return result;
}

int main()
{
    vector<string> vec{"eat", "tea", "tan", "ate", "nat", "bat"}; 
    print_vec(vec);
    
    vector<vector<string>> result = groupAnagrams(vec);
    print_vec2d(result);
    
    return 0;
}
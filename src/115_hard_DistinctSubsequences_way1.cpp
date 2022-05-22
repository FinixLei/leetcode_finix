/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:
    Input: s = "rabbbit", t = "rabbit"
    Output: 3
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;


void printVec(vector<int>& vec) 
{
    for (auto i : vec) cout << i << " ";
    cout << endl;
}

void printVec2D(vector<vector<int>>& vec2D)
{
    for (auto vec : vec2D) {
        for (auto i : vec) cout << i << " ";
        cout << endl;
    }
    cout << endl;
}

// -1 means no found 
int findFirstLarger(vector<int>& array, int val)
{
    int beg = 0;
    int end = array.size() - 1;
    
    if (array[beg] > val) return beg;
    if (array[end] <= val) return -1;
    
    int mid = beg + (end-beg)/2;   // [0,1,2]->1, [0,1]->0
    
    while (mid < end) {
        if (array[mid] > val) {
            if (array[mid-1] <= val) 
                return mid;
            else {  // array[mid-1] > val
                end = mid - 1; 
                mid = beg + (end-beg)/2;
            }
        }
        else { // array[mid] <= val 
            beg = mid; 
            mid = beg + (end-beg)/2;
            if (mid == beg) mid += 1;
        }
    }
    return mid; 
}

void countNumber(vector<vector<int>>& vec2D, int currNum, int& result, int currLayer)
{
    int layers = vec2D.size();
    if (currLayer >= layers) return;
    
    if (currLayer == layers-1) {
        int size = vec2D[currLayer].size();
        for (int i=0; i<size; i++) {
            if (currNum < vec2D[currLayer][i]) {
                result += (size - i); 
                break;
            }
        }
        return; 
    }
    
    int firstLargerPos = findFirstLarger(vec2D[currLayer], currNum);
    if (firstLargerPos < 0) return; 

    for (int j=firstLargerPos; j<vec2D[currLayer].size(); j++) {
        countNumber(vec2D, vec2D[currLayer][j], result, currLayer+1);
    }
    
}

int numDistinct(const string& s, const string& t) 
{
    int size1 = s.size();
    int size2 = t.size();
    if (size1 == 0 || size2 == 0) return 0;
    
    vector<vector<int>> vec2D; 
    vec2D.reserve(size2);
    
    unordered_map<char, vector<int>> cache;
    
    for (int i=0; i<size2; i++) {
        if (cache.find(t[i]) != cache.end()) {
            vec2D.push_back(cache[t[i]]);
            continue;
        }
        
        vector<int> tmp; 
        for (int j=0; j<size1; j++) {
            if (s[j] == t[i]) {
                tmp.push_back(j);
            }
        }
        if (tmp.size() == 0) return 0;
        
        cache[t[i]] = tmp;
        vec2D.push_back(tmp);
    }
    
    // printVec2D(vec2D);

    int result = 0;
    countNumber(vec2D, -1, result, 0);
    
    return result;
}

int main()
{
    string s = "rabbbit", t = "rabbit";
    int result = numDistinct(s, t);
    cout << "result = " << result << endl;
    cout << "---------------------------------------------\n";
    
    s = "babgbag";
    t = "bag";
    result = numDistinct(s, t);
    cout << "result = " << result << endl;
    cout << "---------------------------------------------\n";
    
    s = "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc";
    t = "bcddceeeebecbc";
    result = numDistinct(s, t);
    cout << "result = " << result << endl;
    cout << "---------------------------------------------\n";
    
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    t = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    result = numDistinct(s, t);
    cout << "result = " << result << endl;
    
    return 0;
}

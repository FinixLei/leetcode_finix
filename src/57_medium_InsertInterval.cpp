/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]
    
Example 2:
    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
    
Example 3:
    Input: intervals = [], newInterval = [5,7]
    Output: [[5,7]]
    
Example 4:
    Input: intervals = [[1,5]], newInterval = [2,3]
    Output: [[1,5]]
    
Example 5:
    Input: intervals = [[1,5]], newInterval = [2,7]
    Output: [[1,7]]
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


template<typename T>
void print_vv(const vector<vector<T>> vv)
{
    for (auto vec : vv) {
        for (auto v : vec) { cout << v << " "; }
        cout << endl;
    }
}

template<typename T>
void print_vector(const vector<T> vec)
{
    for (auto v : vec) { cout << v << " "; }
    cout << endl;
}

void print_vec_pair(const vector<pair<int, int>> vec) 
{
    for (auto v : vec) {
        cout << v.first << ", " << v.second << endl;
    }
}

struct myCompare {
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first;
    }
};

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    vector<vector<int>> result;
    
    if ( intervals.size() == 0) {
        result.push_back(newInterval);
        return result;
    }
    
    vector<pair<int, int>> middle;
    
    for (auto vec : intervals){
        int a = vec[0] < vec[1] ? vec[0] : vec[1];
        int b = vec[0] < vec[1] ? vec[1] : vec[0];
        middle.push_back(make_pair(a, b));
    }
    
    sort(middle.begin(), middle.end(), [](pair<int, int> p1, pair<int, int> p2) { return p1.first < p2.first; });
    // sort(middle.begin(), middle.end(), myCompare());
    
    int new_a = newInterval[0] < newInterval[1] ? newInterval[0] : newInterval[1];
    int new_b = newInterval[0] < newInterval[1] ? newInterval[1] : newInterval[0];
    
    bool new_a_done = false, new_b_done = false;
    int curr_a = -1, curr_b = -1;
    
    for (int i=0; i < middle.size(); i++) 
    {
        int a = middle[i].first, b = middle[i].second;
        
        if (new_b_done)  // new interval has been merged, push the rest intervals 
        {
            result.push_back({a, b});
            continue;
        }
        
        if (!new_a_done)  // new_a_done == false, means not touch new interval yet 
        {
            // Two cases where current interval has nothing to do with new interval 
            if (new_b < a)
            {
                result.push_back({new_a, new_b});
                new_a_done = new_b_done = true;
                result.push_back({a, b});
                continue;
            }
            if (b < new_a) 
            {
                result.push_back({a, b});
                continue;
            }
            
            // Now, current interval must intersect with new interval 
            // 2 possibilities for new_a 
            curr_a = (new_a <= a ? new_a : a);
            new_a_done = true; 
            
            // 2 possibilities for new_b 
            if (new_b <= b) 
            {
                curr_b = b; 
                new_b_done = true;
                result.push_back({curr_a, curr_b});
            }
            else { }  // new_b > b , do nothing, will check in next interval or outside the while loop 
        }
        else // new_a_done == true && new_b_done == false 
        { 
            if (new_b < a) 
            {
                curr_b = new_b;
                new_b_done = true;
                result.push_back({curr_a, curr_b});
                result.push_back({a, b});
            }
            else if (new_b >= a && new_b <= b) 
            {
                curr_b = b; 
                new_b_done = true;
                result.push_back({curr_a, curr_b});
            }
            else {} // new_b > b , do nothing 
        }
    }
    
    if (!new_a_done) 
    {
        result.push_back({new_a, new_b});
    }
    else if (new_a_done && !new_b_done)
    {
        curr_b = new_b; 
        result.push_back({curr_a, curr_b});
    }
    
    return result;
}


int main()
{
    vector<vector<int>> intervals, result;
    vector<int> newInterval;
    
    // intervals = {{1, 3}, {6, 9}};
    intervals = {{9, 6}, {3, 1}};
    newInterval = {2, 5};
    result = insert(intervals, newInterval);
    print_vv(result);  // {1,5}, {6,9}
    cout << "----------------\n";
    
    intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    newInterval = {4, 8};
    result = insert(intervals, newInterval);
    print_vv(result);  // {1,2}, {3,10}, {12,16}
    cout << "----------------\n";
    
    intervals = {{1,5}};
    newInterval = {2,3};
    result = insert(intervals, newInterval);
    print_vv(result);  // {1,5}
    cout << "----------------\n";
    
    intervals = {{1,5}};
    newInterval = {0,0};
    result = insert(intervals, newInterval);
    print_vv(result);  // {0,0}, {1,5}
    cout << "----------------\n";
    
    return 0;
}

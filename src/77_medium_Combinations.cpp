/*
    Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
    You may return the answer in any order.
    
    Example 1:

    Input: n = 4, k = 2
    Output:
    [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
    ]
*/


#include <iostream>
#include <vector>
using namespace std;


void print_2Dvec(vector<vector<int>>& vec2d)
{
    for (auto vec : vec2d) {
        for (auto v : vec) cout << v << " ";
        cout << endl;
    }
    cout << endl;
}

void list_all(const vector<int>& line, vector<vector<int>>& all_results, vector<int>& one_result, int start, int k) 
{
    if (k == 0) {
        all_results.push_back(one_result);
        return;
    }

    int end = line.size()-k;
    for (int i=start; i<=end; i++) {
        one_result.push_back(line[i]);
        list_all(line, all_results, one_result, i+1, k-1);
        one_result.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) 
{
    vector<vector<int>> all_results; 
    vector<int> line; 
    for(int i=1; i<=n; i++) line.push_back(i);

    vector<int> one_result;
    one_result.reserve(k);

    list_all(line, all_results, one_result, 0, k);

    return all_results;
}


int main()
{
    auto vec2d = combine(4, 2);
    print_2Dvec(vec2d);
    
    return 0;
}

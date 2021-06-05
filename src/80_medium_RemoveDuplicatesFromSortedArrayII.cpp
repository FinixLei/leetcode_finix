#include <iostream>
#include <vector>
using namespace std;


int removeDuplicates(vector<int>& nums) 
{
    int beg = 0;
    int end = nums.size()-1;
    int pos = beg;
    
    while (pos < end) {
        if (nums[pos] == nums[pos+1]) {
            pos ++;
        }
        else {
            if (pos > beg) {
                beg += 2;
                int src = ++pos;
                int dst = beg; 
                if (src > dst) {
                    while (src <= end) nums[dst++] = nums[src++];
                    end = dst - 1;
                }
                pos = beg; 
            }
            else { // pos == beg 
                beg ++;
                pos ++;
            }
        }
    }
    
    if (pos == end && pos > beg && nums[beg] == nums[pos]) {
        end = beg + 1;
    }
    
    return end + 1; 
}


int main()
{
    {
        vector<int> vec = {1, 1, 1, 2, 2, 3};
        int len = removeDuplicates(vec);
        for (int i=0; i<len; i++) {
            cout << vec[i] << " ";
        }
        cout << "\n-------------------\n";
    }
    
    {
        vector<int> vec = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        int len = removeDuplicates(vec);
        for (int i=0; i<len; i++) {
            cout << vec[i] << " ";
        }
        cout << "\n-------------------\n";
    }
    
    {
        vector<int> vec = {1, 1, 1};
        int len = removeDuplicates(vec);
        for (int i=0; i<len; i++) {
            cout << vec[i] << " ";
        }
        cout << "\n-------------------\n";
    }
    
    {
        vector<int> vec = {0,0,0,0,0,1,2,2,3,3,4,4};
        int len = removeDuplicates(vec);
        for (int i=0; i<len; i++) {
            cout << vec[i] << " ";
        }
        cout << "\n-------------------\n";
    }
    
    return 0;
}

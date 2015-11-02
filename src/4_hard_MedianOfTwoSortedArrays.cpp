/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#include <vector>
#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int size = size1 + size2;
    
    vector<int> result_array;
    
    for (int i=0, j=0; i<size1 || j<size2; ) {
        if (i >= size1) {
            result_array.push_back(nums2[j++]);
            continue;
        }
        if (j >= size2) {
            result_array.push_back(nums1[i++]);
            continue;
        }
        
        if (nums1[i] <= nums2[j]) {
            result_array.push_back(nums1[i++]);
        }
        else {
            result_array.push_back(nums2[j++]);
        }
    }
    
    if (size % 2 == 1) {
        return result_array[(size-1)/2];
    }
    else {
        
        return (result_array[size/2 - 1] + result_array[size/2])/2.0; 
    }
}


int main()
{
    vector<int> array1;
    vector<int> array2;
    
    array1.push_back(10); 
    array1.push_back(20); 
    array1.push_back(30); 
    
    array2.push_back(5); 
    array2.push_back(15); 
    // array2.push_back(25); 
    
    double result = findMedianSortedArrays(array1, array2);
    cout << "result = " << result << endl;
    
    return 0;
}
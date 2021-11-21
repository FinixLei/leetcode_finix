/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#include <vector>
#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    bool odd = (m+n) % 2;
    pair<int, int> targetIndexes;
    if (odd) {
        targetIndexes = {(m+n-1)/2, (m+n-1)/2};
    }
    else {
        targetIndexes = {(m+n-1)/2, (m+n)/2};
    }
    
    int count=0, tmp=0;
    int i=0, j=0, v1=0, v2=0;
    
    while (i<m || j<n) {
        if (i >= m) {
            tmp = nums2[j++];
        }
        else if (j >= n) {
            tmp = nums1[i++];
        }
        else {  // both nums1 and nums2 are not empty 
            tmp = min(nums1[i], nums2[j]);
            if (nums1[i] < nums2[j]) i++;
            else j++;
        }
        
        if (count == targetIndexes.first) v1 = tmp;
        if (count == targetIndexes.second) {
            v2 = tmp;
            break;
        }
        count ++;
    }
    return (v1+v2)*1.0/2; 
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
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
    
    bool bEven = (size % 2 == 0);
    int target_num = bEven ? (size/2-1) : (size-1)/2; 
    target_num ++;
    
    int count = 0;
    int currNum = 0;
    int n1 = -1;
    int n2 = -1;
    
    for (int i=0, j=0; i<size1 || j<size2; ) {
        if (i >= size1) {
            currNum = nums2[j++]; 
        }
        else if (j >= size2) {
            currNum = nums1[i++];
        }
        else if (nums1[i] <= nums2[j]) {
            currNum = nums1[i++];
        }
        else {
            currNum = nums2[j++];
        }
        
        count ++;
        
        if (!bEven) {
            if (count == target_num) return currNum;
        }
        else {
            if (count == target_num) {
                n1 = currNum;
            }
            else if (count == target_num + 1) {
                n2 = currNum;
                break;
            }
        }
    }
    return (n1+n2)*1.0/2;
}

int main()
{
    vector<int> array1{10, 20, 30};
    vector<int> array2{5, 15, 25}
    
    double result = findMedianSortedArrays(array1, array2);
    cout << "result = " << result << endl;
    
    return 0;
}
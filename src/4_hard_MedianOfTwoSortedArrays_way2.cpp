#include <vector>
#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int size = size1 + size2;
    
    vector<int> pos_array; 
    bool isOdd = (size % 2 == 1) ? true : false;
    int pos = 0;
    double rv = -1;
    
    if (isOdd) {
        for (int i=0, j=0; i<size1 || j<size2; ) {
            if (i >= size1) {
                if (pos == (size-1)/2) {
                    rv = nums2[j];
                    break;
                }
                
                j++;
                pos++;
                continue;
            }
            if (j >= size2) {
                if (pos == (size-1)/2) {
                    rv = nums1[i];
                    break;
                }
                
                i++;
                pos++;
                continue;
            }
            
            if (nums1[i] <= nums2[j]) {
                if (pos == (size-1)/2) {
                    rv = nums1[i];
                    break;
                }
                
                i++;
                pos++;
            }
            else {
                if (pos == (size-1)/2) {
                    rv = nums2[j];
                    break;
                }
                
                j++;
                pos++;
            }
        }
    }
    else {  // not isOdd
        int first_num = -1;
        int second_num = -1;
        
        for (int i=0, j=0; i<size1 || j<size2; ) {
            if (i >= size1) {
                if (pos == size/2 - 1) first_num = nums2[j];
                if (pos == size/2) {
                    second_num = nums2[j];
                    break;
                }
                
                j++;
                pos++;
                continue;
            }
            if (j >= size2) {
                if (pos == size/2 - 1) first_num = nums1[i];
                if (pos == size/2) {
                    second_num = nums1[i];
                    break;
                }
                
                i++;
                pos++;
                continue;
            }
            
            if (nums1[i] <= nums2[j]) {
                if (pos == size/2 - 1) first_num = nums1[i];
                if (pos == size/2) {
                    second_num = nums1[i];
                    break;
                }
                
                i++;
                pos++;
            }
            else {
                if (pos == size/2 - 1) first_num = nums2[j];
                if (pos == size/2) {
                    second_num = nums2[j];
                    break;
                }
                
                j++;
                pos++;
            }
        }
        rv = (first_num + second_num) / 2.0;
    }
    
    return rv;
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
    array2.push_back(25); 
    
    double result = findMedianSortedArrays(array1, array2);
    cout << "result = " << result << endl;
    
    return 0;
}
/*
    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
    
    Example 1:
        Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
        Output: 6
    Explanation: The maximal rectangle is shown in the above picture.
*/


#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

int largestRectangleArea(vector<int>& heights) 
{
    heights.push_back(INT_MIN);
    
    int result = 0;
    stack<int> st;
    
    int h=0, w=0;
    int top_id = 0;

    for (int i=0; i<heights.size(); ++i)
    {
        // 单调递减栈，因为出栈的那一刻，左边（即栈内）和右边（即压栈）的元素都比此元素小
        // 此时，方便计算此出栈元素的能够横扫的最大范围
        while ( !st.empty() && heights[st.top()] > heights[i] ) {
            top_id = st.top();
            st.pop();
            
            h = heights[top_id];
            
            // w = ( st.empty() ? i : (i-st.top()-1) ); // 以下9行可缩为此1行
            if (st.empty()) {
                // 当栈为空时，代表刚刚出栈的元素是自最初始以来至当前压栈元素之前的最小元素
                // 因此，当前压栈元素的下标i，代表了刚出栈元素能横扫自0至i-1的所有的格子。
                w = i;
            }
            else {
                // 刚刚出栈的那个元素能横扫的矩形区域
                w = i - st.top() - 1;
            }
            result = max(result, w*h);
        }
        st.push(i);
    }
    
    return result;
}

int maximalRectangle(vector<vector<char>>& matrix) 
{
   if (matrix.size() == 0) return 0;
    
    int maxRowNum = matrix.size() - 1;
    int maxColNum = matrix[0].size() - 1;
    
    int result = 0;
    
    // 将每一列看作一个柱子，然后用单调栈来解决。
    // 第1次将第1行的每一列看作一个柱子；
    // 第2次将前2行的每一列看作一个柱子；
    // 第3次将前3行的每一列看作一个柱子；
    // 依此类推，每一次都用单调栈做一次取结果
    
    for (int endRow=0; endRow<=maxRowNum; endRow ++) {
         vector<int> histogram(maxColNum+1, 0);
         
         for (int col=0; col<=maxColNum; col++) {
            int height = 0;
            
            for (int end=endRow; end >=0; end--) {
                if (matrix[end][col] == '1') height ++;
                else break;
            }
            
            histogram[col] = height;
         }
         
         int tmpResult = largestRectangleArea(histogram);
         result = max(tmpResult, result);
    }
    
    return result;
}

int main()
{
    vector<vector<char>> matrix {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'}, 
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    int result = maximalRectangle(matrix);
    cout << "result = " << result << endl;
    
    matrix = {
        {'1', '0', '1', '1', '1'},
        {'0', '1', '0', '1', '0'},
        {'1', '1', '0', '1', '1'},
        {'1', '1', '0', '1', '1'},
        {'0', '1', '1', '1', '1'}
    };
    
    result = maximalRectangle(matrix);
    cout << "result = " << result << endl;
    
    return 0;
}

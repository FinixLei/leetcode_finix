/*
    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
    return the area of the largest rectangle in the histogram.

    Example-1 
        Input: heights = [2,1,5,6,2,3]
        Output: 10
        Explanation: The above is a histogram where width of each bar is 1.
        The largest rectangle is shown in the red area, which has an area = 10 units.

*/


#include <iostream>
#include <vector>
using namespace std;


template <typename T>
void print_vec(vector<T>& vec)
{
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

// 普通解法， 大约 200+ms on LeetCode
int largestRectangleArea_1(vector<int>& heights) 
{
    int maxValue = 0;
    int size = heights.size();
    
    int i = 1;
    for (i=1; i<size; ++i) {
        if (heights[i] != heights[0]) break;
    }
    if (i == size) {
        return heights[0] * size;
    }
    
    for (i=0; i<size; ++i) {
        int count = 1;
        int p1 = i-1, p2 = i+1;
        
        while (p1 >= 0 && heights[p1] >= heights[i]) {
            ++ count;
            -- p1;
        }
        
        while (p2 < size && heights[p2] >= heights[i]) {
            ++ count; 
            ++p2;
        }
        
        if (count * heights[i] > maxValue) maxValue = count * heights[i];
    }
    
    return maxValue;
}


// 单调栈解法，大约 100+ ms on LeetCode
int largestRectangleArea_2(vector<int>& heights) 
{
    int result = 0;
    stack<int> st;
    
    int h=0, w=0;
    int top_id = 0;

    for (int i=0; i<heights.size(); ++i)
    {
        // 单调递减栈，因为出栈的那一刻，左边（即栈内）和右边（即压栈）的元素都比此元素小
        // 此时，方便计算此出栈元素的能够横扫的最大范围
        // 因为每个元素都会出栈，所以每个元素的横扫最大范围都能被求出，于是就能知道最大矩形面积
        while ( !st.empty() && heights[st.top()] > heights[i] ) {
            top_id = st.top();
            st.pop();
            
            h = heights[top_id];
            
            // 接下来，就是出栈
            // 因为在出栈的这一刻，左右的元素都比此元素小，
            // 所以，出栈的时候的目标就是： 计算这个出栈元素能横扫的最大范围!
            // 这个时候，分栈空和栈不空这两种情况
            // 栈不空，是普通情况，此时最新的栈顶的元素，就是此刚出栈元素的左边的离它最近的元素；
            // 而右边的离它最近的元素就是目前的压栈元素，
            // 因此，刚出栈元素的横扫范围就是 i-s.top()-1
            // 而对于栈空的情况，见如下注释
            
            if (st.empty()) {
                // 当栈为空时，代表刚刚出栈的那最后一个元素是自最初始以来至当前压栈元素之前的最小的元素
                // 因此，当前的i，代表了该元素能横扫自0至i-1的所有的格子。
                // 将来，若有更小的元素压栈，则该元素在出栈的时候，也依然能横扫自0至压栈元素前一个位置的所有格子
                w = i;
            }
            else {
                // 刚刚出栈的那个元素能横扫的矩形区域
                // 注意，这里不一定是 i - top_id - 1
                w = i - st.top() - 1;
            }
            result = max(result, w*h);
        }
        st.push(i);
    }
    
    return result;
}


int main()
{
    vector<int> vec; 
    int result = 0;
    
    vec = {2, 1, 5, 6, 2, 3};
    result = largestRectangleArea_1(vec);
    print_vec(vec);
    cout << "result = " << result << endl;
    
    result = largestRectangleArea_2(vec);
    print_vec(vec);
    cout << "result = " << result << endl;

    return 0;
}
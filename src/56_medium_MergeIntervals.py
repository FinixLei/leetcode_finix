#!/usr/bin/python3

'''
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
'''

def merge(intervals):
    if (len(intervals) == 0):
        return list()
    
    # key is first item, value is the largest second item 
    beg2end = dict()
    
    for item in intervals:
        if beg2end.get(item[0]) is None:
            beg2end[item[0]] = item[1]
        else:
            if beg2end[item[0]] < item[1]:
                beg2end[item[0]] = item[1]
    
    keys = sorted(beg2end.keys())
    
    result = list()
    index = 0
    curr_beg, curr_end = keys[0], beg2end[keys[0]]
    while index < len(keys):
        if (index == len(keys)-1):
            result.append([keys[-1], beg2end[keys[-1]]])
            break 
    
        b2 = keys[index+1]
        e2 = beg2end[b2] 
    
        # print("%s, %s, %s, %s" % (curr_beg, curr_end, b2, e2))
    
        if curr_beg <= b2 and curr_end >= e2: # do merge 
            if (index == len(keys)-2):  # have merged the last item, so, break 
                result.append([curr_beg, curr_end])
                break
        elif curr_beg <= b2 and curr_end >= b2: # do merge 
            curr_end = e2 
            if (index == len(keys)-2):  # have merged the last item, so, break 
                result.append([curr_beg, curr_end])
                break
        else: # cannot merge 
            result.append([curr_beg, curr_end])
            curr_beg = b2 
            curr_end = e2 
    
        index += 1
    
    return result 
    
    
result = merge([[1,3],[2,6],[8,10],[15,18]])
for item in result:
    print(item)
print("---------------------------")

result = merge([[1,4],[4,5]])
for item in result:
    print(item)
print("---------------------------")

result = merge([[1,4],[2, 3]])
for item in result:
    print(item)
print("---------------------------")

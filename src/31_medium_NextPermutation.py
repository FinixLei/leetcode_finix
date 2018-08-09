# coding=utf-8

"""
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
"""

mylist = [1,2,4,6,3,1]
mylist = [2, 1, 3]
mylist = [1, 2]
mylist = [1, 1]
mylist = [3, 2, 1]



def func(nums):
    size = len(nums)
    if size <= 1:
        return
    if size == 2:
        if nums[0] < nums[1]:
            nums[0], nums[1] = nums[1], nums[0]
        return
        
    # Step 1. 从后往前，先找出第1个不符合降序的数字m
    descend = True
    i = size-1
    while i >= 1:
        if nums[i-1] >= nums[i]:
            i -= 1
            continue
        else:
            i -= 1
            descend = False
            break
            
    if descend:
        new_nums = nums[::-1]
        j = 0
        while j < size:
            nums[j] = new_nums[j]
            j += 1
        return
    
    t = nums[i]
    index = i
    
    # Step 2. 从降序序列中，找出第一个大于m的数字n，并与m交换
    i = size - 1
    while i > index:
        if nums[i] > t:
            break
        i -= 1
            
    nums[index] = nums[i]
    nums[i] = t
    
    # Step 3. 把现在的数字n的位置后的数组（即原来的降序数组）按从小到大排序即可
    part_nums = sorted(nums[index+1:])
    i = index+1
    while i < size:
        nums[i] = part_nums[i-index-1]
        i += 1
    

func(mylist)

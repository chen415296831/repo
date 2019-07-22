def quickSort(arr):
    less = []
    pivotList = []
    more = []

    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        for i in arr:
            if i < pivot:
                less.append(i)
            elif i > pivot:
                more.append(i)
            else:
                pivotList.append(i)
        less = quickSort(less)
        more = quickSort(more)
        return less + pivotList + more

#快排的稳定性
#假设有数组[1, 3, 3, 5, 3, 7, 9]
#假设第五个元素是中轴点，前面两个可能3会被排在后面

nums = [1, 6, 8, 13, 43, 2, 95, 23, 68, 103]
print(nums)
sortedNums = quickSort(nums)
print(sortedNums)

> 思路很简单，细节是魔鬼
> https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/

1. 不等号是否应该带等号
2. mid 是否应该加一等等
3. 如何防止计算mid时溢出

# 二分查找框架
```c
int binarySearch(int* nums, int len, int target)
{
    int left  = 0;
    int right = len - 1;
    int mid   = 0;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            right = mid - 1;  // left，本次比较之前的一个元素
        else if(nums[mid] < target)
            left = mid + 1;
    }

    return -1;
}
```

# 左侧边界
比如说给你有序数组 nums = [1,2,2,2,3]，target = 2，此算法返回的索引是 2，没错。但是如果我想得到 target 的左侧边界，即索引 1，或者我想得到 target 的右侧边界，即索引 3
```c
int left_binary_search(int* nums, int len, int target)
{
    int left  = 0;
    int right = len;
    int mid   = 0;

    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
            right = mid;
        else if(nums[mid] > target)
            right = mid;
        else if(nums[mid] < target)
            left = mid + 1;
    }

    if(left == len)
        return -1;

    return nums[left] == target ? left : -1;
}
```

# 右侧边界
```c
int right_binary_search(int* nums, int len, int target)
{
    int left  = 0;
    int right = len;
    int mid   = 0;

    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid;
        else if(nums[mid] < target)
            left = mid + 1;
    }

    if(left == 0)
        return -1;

    return nums[left - 1] == target ? left - 1 : -1;
}
```
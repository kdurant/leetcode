#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 冒泡排序
 * 时间复杂度 O(n^2)
 * 冒泡排序算法的运作如下：（从后往前）
    1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。数值小的放在前面
    2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
    3. 针对所有的元素重复以上的步骤，除了最后一个。
    4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
 * @param data 
 * @param len 
 */
void bubble_sort(int *data, int len)
{
    int temp;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief [选择排序](http://blog.csdn.net/sysukehan/article/details/52661681)
 * 时间复杂度 O(n^2)
    1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始（末尾）位置；
    2. 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的起始（末尾）尾。
    3. 以此类推，直到所有元素均排序完毕。
 * @param data 
 * @param len 
 */
void select_sort(int *data, int len)
{
    int min;
    int temp;
    for (int i = 0; i < len; i++)
    {
        min = i;
        for (int j = i; j < len; j++)
        {
            if (data[min] > data[j])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = data[min];
            data[min] = data[i];
            data[i] = temp;
        }
    }
}

/**
 * @brief [插入排序（Insertion Sort）](https://www.cnblogs.com/shihaokiss/p/5449011.html)
 * 时间复杂度 O(n^2)
 * @param data 
 * @param len 
 */
void insert_sort(int *data, int len)
{
    int temp;
    for(size_t i = 1; i < len; i++)
    {
        for(size_t j = i; j > 0; j--)
        { 
            if(data[j] < data[j-1] )  // 后一个元素小于前一个元素
            {
                temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
            }
        }
        
    }
}

/**
 * @brief 归并排序
 * 
 * @param data 
 * @param first 
 * @param last 
 */

void merge(int *data, int low, int mid, int high)
{
    int i, k;
    int *tmp = malloc((high-low+1)*sizeof(int));
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    for (k = 0; left_low <= left_high && right_low <= right_high; k++)
    {
        if(data[left_low] <= data[right_low])
        {
            tmp[k] = data[left_low++];
        }
        else
        {
            tmp[k] = data[right_low++];
        }  
    }

    if(left_low <= left_high)
    {
        for (size_t i = left_low; i <= left_high; i++)
        {
            tmp[k++] = data[i];
        }
    } 

    if(right_low <= right_high)
    {
        for (size_t i = right_low; i <= right_high; i++)
        {
            tmp[k++] = data[i];
        }
    } 
    for (size_t i = 0; i < high-low+1; i++)
    {
        data[low+i] = tmp[i];
    }
    free(tmp);
    return; 
}

void merge_sort(int *data, unsigned int first, unsigned int last)
{
    int mid = 0;
    if(first < last)
    {
        mid = (first + last) / 2;
        merge_sort(data, first, mid);
        merge_sort(data, mid + 1, last);
        merge(data, first, mid, last);
    }
}


int main()
{
    // int a[] = {900, 2, 3, -58, 34, 76, 32, 43, 56, -70, 35, -234, 532, 543, 2500};
    int a[] = {900, 2, 3, -58};

    merge_sort(a, 0, sizeof(a)/4-1);
    for (size_t i = 0; i < sizeof(a)/4; i++)
    {
        printf("%d\t", a[i]);
    }
    
}
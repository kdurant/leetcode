[选择排序](http://blog.csdn.net/sysukehan/article/details/52661681)分为三种，直接选择排序、树形选择排序（锦标赛排序）、堆排序（大根堆、小根堆）。直接选择排序和堆排序是不稳定排序，树形选择排序是稳定排序。

# 直接选择排序

1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始（末尾）位置；
2. 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的起始（末尾）尾。
3. 以此类推，直到所有元素均排序完毕。

![](http://img.blog.csdn.net/20130929150444921?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGFuX3hpYW95YW5n/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

```c
#include <stdio.h>

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

int a[7] = { 40, 9, 20, 3, 5, 33, 4 };
int main(void)
{
    select_sort(a, 7);

    for (int i = 0; i < 7; i++)
        printf("%d\n", a[i]);
    return 0;
}
```

# 树形选择排序（Tree Selection Sort），又称锦标赛排序（Tournament Sort）

# 堆排序


# 步骤
1. 找出待排序的数组中最大和最小的元素
2. 开辟额外空间，数组C
3. 统计带排序数组中每个值为i的元素出现的次数，存入数组C的第i项
4. 反向填充目标数组
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void counting_sort(int* ini_arr, int* sorted_arr, int n)
{
    int min_value = ini_arr[0];
    int max_value = ini_arr[0];
    int idx       = 0;
    for(int i = 0; i < n; i++)
    {
        if(ini_arr[i] > max_value)
            max_value = ini_arr[i];

        if(ini_arr[i] < min_value)
            min_value = ini_arr[i];
    }

    int range = max_value - min_value + 1;

    int* count_arr = (int*)calloc(range, sizeof(int));

    for(int i = 0; i < n; i++)  // 统计每个元素出现的次数
    {
        count_arr[ini_arr[i] - min_value]++;
    }

    for(int i = 0; i < range; i++)
    {
        while(count_arr[i]--)
            sorted_arr[idx++] = i + min_value;
    }

    free(count_arr);
}
int main(void)
{
    int ini_arr[4] = {9, 9, 1, 5};
    int sorted_arr[4];
    counting_sort(ini_arr, sorted_arr, sizeof(ini_arr) / 4);

    for(int i = 0; i < sizeof(ini_arr) / 4; i++)
    {
        printf("%d\t", sorted_arr[i]);
    }

    return 0;
}

```
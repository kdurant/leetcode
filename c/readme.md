# 文件命名规则
1. `!`开头的表示本地运行正常，但leetcode上报告内存错误之类问题的情况
2. `_`表示已经完成一种解法，但有优化空间或者其他算法需要完成的情况
3. `@`表示尝试解决但没有成功

# 更详细的堆栈检查
`clang -O1 -g -fsanitize=address -fno-omit-frame-pointer ./c/test.c`

# qsort
```c
void qsort(void * base, size_t nmemb, size_t size, int (*compare)(const void*, vonst void*));
```
函数qsort对一个包含nmemb个对象的数组进行排序
* base -- 指向要排序的数组的第一个元素的指针。
* nitems -- 由 base 指向的数组中元素的个数。
* size -- 数组中每个元素的大小，以字节为单位。

根据compare所指向的比较函数将数组内容排列成升序。函数的桉树分别指向两个数组元素的指针。
* 第一个元素小于第二个元素，返回小于零的整数
* 第一个元素等于第二个元素，返回等零的整数
* 第一个元素大于第二个元素，返回大于零的整数

```c
/*
将形参要强制类型转换为数组元素的类型
*/
int compare(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if(arg1 < arg2)
        return -1;
    if(arg1 > arg2)
        return 1;
    return 0;
}


int values[] = { 88, 56, 100, 2, 25 };
qsort(values, 5, sizeof(int), compare);
```

# 二维数组的参数传递
## leetcode上通用函数原型
```c
/**
 * @brief 
 *
 * @param array                 二维数组指针
 * @param row                   输入二维数组的行数
 * @param col                   输入二维数组的列数
 * @param returnSize            返回二维数组的行数
 * @param returnColumnSizes     返回二维数组的列数
 *
 * @return 
 */
int** func(int** array, int row, int* col, int* returnSize, int** returnColumnSizes)
{
}
```

## array类型构建
/*
 * 调用函数前的准备工作
 * array 是二维数组 array[M][N], 可以看做M个一维数组（元素数量为N）
 * 可看成指针数组type *array[N];
 *
```c
int A[3][3] = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};

int *p[3];
p[0] = A[0]; 
p[1] = A[1];
p[2] = A[2];
int **q = p;
```

## row类型
二维数组的行数, int

## col类型
将二维数组行的元素个数，放到一个数组里，然后传递数组名
```c
int col[3] = {3, 3, 3};
```
# 文件命名规则
1. `!`开头的表示本地运行正常，但leetcode上报告内存错误之类问题的情况
2. `_`表示已经完成一种解法，但有优化空间或者其他算法需要完成的情况
3. `@`表示尝试解决但没有成功

# 更详细的堆栈检查
`clang -O1 -g -fsanitize=address -fno-omit-frame-pointer xx.c`

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
int compare(const void *a , const void *b)
{
    return *(int *)a - *(int *)b;
}

int values[] = { 88, 56, 100, 2, 25 };
qsort(values, 5, sizeof(int), compare);
```
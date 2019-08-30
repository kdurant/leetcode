# 1. 指针基础
## 声明
```c
int* p;    // p是一个指向整数的指针变量
char* c;   // c是一个指向字符的指针变量
other_type *p;
```
指针声明和普通变量声明本质上没有任何区别.
`int i`, 在内存中开辟连续4个字节空间，用于存放数据
`int* p`, 也会在内存中开辟连续4个字节空间，p中存放的数据内存地址

## 如何阅读
```c
const int* pci;
```
采用倒读法
1. const int* `pci`, pci是个变量
2. const int`* pci`, pci是个指针变量
3. const `int* pci`, pci是个指向整型数据的指针变量
4. `const int* pci`, pci是个指向整型常量的指针变量

## 间接引用操作符(\*)，取地址运算符(&)
地址操作符会&会返回操作数的地址
间接引用操作符（*）返回指针变量指向的值，一般称解引指针
```c
int a = 3;
```
`&a`运算结果运算结果是一个指针, 指针的类型是`int *`

对于指针变量来说，变量里存放的是内存地址，要取出这个地址里的数据就需要对指针进行解引用。**指针类型**只是决定了我们如何解释本次从内存里的数据

例如：
address | 0x1000 | 0x1001 | 0x1002 | 0x1003 
------- | ------ | ------ | ------ |-------
data    | 0x31   | 0x32   | 0x33   | 0x34  

```c
int *p = (int *)0x1000;
char *c = (char *)0x1000;
```
`*p`时从0x1000连续取4个字节(指针所指向数据类型)数据组成一个int数据，赋值给*p

`*c`时只从0x1000取1个字节数据作为char数据，赋值给*c

# 2. 数组 指针区别

## sizeof值不同
```c
#include <stdio.h>

int main(void)
{
    char buf[10] = "study";
    char *pstr = "study";

    printf("%d\n", sizeof(buf));
    printf("%d\n", sizeof(pstr));
}
```
sizeof(数组名)得到的是数组所有元素的字节数
sizeof(指针名)得到的是指针本身所占内存的大小(32位系统是4字节，64位系统是8字节)

## 增量运算符
* 可以对指针进行增量操作
* 不可以对数据名进行增量操作
```c
char buf[10] = "study";
char *pstr = "study";

printf("%c\n", *pstr++);    // 正确
printf("%c\n", *buf++);     // 不正确
// buf是数组名，是数组的地址，是常量，不可作为左值。
```

# 二级指针
```c
int var;
int *p1 = &var;    // *p1 的值是 var的内容
int ** p2 = &p1;   // *p2 的值是 p1的地址, 所以 **p2的值是var的内容

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct Node* LinkList;

Node var;       // struct Node var

// LinkList test = &var;
// test里存放的是Node类型的地址, 修改test的内容,即可修改test指向的结点
// (*test)才是
LinkList test;  //struct Node* test

// LinkList *l = &test;
// l里存放的是test(指针)变量的地址
// *l取出test(指针)变量保存的内容, var变量的地址 
LinkList *l;    // struct Node* * l; 
```


# 3. 二维数组

## 定义
```c
char zippo[3][20] = {
    "abcdef",       // zippo[0] 相当于一个 char p[20]的数组
    "nimenhao",     // zippo[1]
    "hello world"   // zippo[2]
};
```
`[]`的结合方向为从左到右，zippo[3]说明这是一个数组.
zippo[3][20]说明数组里的每个元素是20个char长度的数组.

> zippo 是二维数组首地址
> zippo[0]的类型是 int [20]
> zippo[1]的类型是 int [20]

## 数组空间
二维数组占用的空间为：`row * column * sizeof(char)`

## 二维数组的遍历
```c
for (int i = 0; i < 3; i++)
{
    printf("%s\n", zippo[i]);
}
```

## 二维数组作为函数参数
二维数组的每个元素是一个一维数组，所以指向二维数组的指针应该是`数组指针`
```c
char (*p)[20] = zippo;  //
void show_array(char (*p)[20], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", p[i]);
    }
}
```
> \* 和 p 构成一个指针的定义，指针名是 p， char 修饰的是数组的内容
> 即数组里的每个元素。数组在这里并没有名字，是个匿名数组

## 动态分配二维数组
1. 使用二级指针
先分配“外层”数组，然后再为每一行分配内层，分配的内存可能连续，也可能不连续
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ** twoArray;
    int row = 2;
    int col = 4;

    twoArray = (int **)malloc(sizeof(int *) * row);
    for (size_t i = 0; i < row; i++)
    {
        twoArray[i] = (int *)malloc(sizeof(int) * col);
    }
    
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%p\t", &twoArray[i][j]);
        }
        printf("\n");        
    }
    return 0;
}
```

2. 使用数组指针，分配的内存是连续的
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int row = 2;
    int col = 4;
    int (* twoArray)[2] = (int (*)[2])malloc(sizeof(int)*col*row);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%p\t", &twoArray[i][j]);
        }
        printf("\n");        
    }
    
    return 0;
}
```


# 4. 指针数组
类比`整型数组`, 数组里存放的是整型元素; 指针数组里的元素是**指针**. 
## 定义
```c
char *str[3] = {
    "aaaaaa", 
    "cccccc", 
    "ddddddddd"
};
```
`[]`的优先级大于`*`，str先与`[]`结合，说明这是一个数组，数组里的元素str[0], str[1], str[2]都是指向`char *`的指针。对于单个元素可以将声明简化为：
```c
char * str0;
char * str1;
char * str2;
```

## 指针数组的遍历
```c
for (int i = 0; i < 3; i++)
{
    printf("%s\n", str[i]);
    printf("%s\n", *(str+i));
}
```
## 指针数组作为函数参数
```c
void show_array(char **p, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", p[i]);
    }
}
```
> *p里存放的是字符串（char *）的首地址


![pic](https://images0.cnblogs.com/blog/256716/201310/22201218-19ddd896ae6a45e1b61c7e3ee59b4662.jpg)

# 5. 数组指针
数组指针也称指向一维数组的指针，亦称行指针。`指针指向的是数组`(类比整型指针)
```c
int arr[2][3] = {
    {3, 6, 9},
    {2, 4, 8}
};
int (*p)[3];    // p是一个指向整型元素组成的数组的指针
```
()优先级大于[]，所以先看*p，说明是指针。再与[]结合，说明指针指向的内容为一维数组（数组的的长度为3）
执行p+1时，p要跨过整个一维数据的长度

> p 的类型是 int (*)[3]
> *p的类型是 int [3]
> 类比 int a[3]中, a的类型是 int [3], a是数组名, 且指向数组的首地址
> 所以, *p也指向匿名数组的首地址, *(p+1)指向第二行数组的首地址
> 所以, 可以用 *(p+0) + 1指向匿名数组的具体元素的地址
> 所以, *(*(p+0)+1)


# 6. void指针

## 基本概念
void的意思就是“无类型”，void指针则为“无类型指针”，void指针可以指向任何类型的数据。
所以void指针一般被称为通用指针或者泛指针,或者叫做万能指针

## 定义形式
```c
void *p;
```

## 赋值
1. 可以将任意类型的指针传递给 void *
```c
void test(void *data, size_t n)
{
    memset(data, 0x00, n);
}
```
可以将任何类型的指针传递给test函数而不需要cast。

2. void指针赋值给其他类型指针需要强制类型转换 

## 指针运算
* 在ANSI C标准中，不允许对void指针进行一些算术运算如p++或p+=1等，因为既然void是无类型，那么每次算术运算我们就不知道该操作几个字节
* 在GNU中则允许，因为在缺省情况下，GNU 认为void *和char *一样，既然是确定的，当然可以进行一些算术操作


# 7. 空指针
在C语言中，如果一个指针不指向任何数据，我们就称之为空指针，用NULL表示。例如：
```c
int *p = NULL;
```
> NULL 是一个宏定义，在stdio.h被定义为：
```c
#define NULL ((void *)0)
```


# 8. 函数指针
## 定义
```c
// 方法 1， p_func可以指向 void function_name(int, int, float)类型的函数
void (*p_func)(int, int, float)


/* 方法2 */
typedef void (*tp_func)(int, int, float);       //只是定义了函数指针类型
tp_func p_func = NULL;
```

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sum(int a, int b);

typedef int(*fun_tp)(int a, int b); 

int main()
{
    int (*fun_p)(int a, int b);     // 声明函数指针
    fun_tp tp;

    fun_p = sum;
    tp = sum;
    printf("%d\n", fun_p(3, 2));
    printf("%d\n", tp(3, 2));
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}
```
# 9. 回调函数
回调函数就是一个通过函数指针调用的函数。如果你把`函数的指针（地址）作为参数`传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int(*fun_tp)(int a, int b);

int process_typedef(int a, int b, fun_tp func);
int process_default(int a, int b, int (*func)(int, int));

int sum(int a, int b);
int sub(int a, int b);

int main()
{
    int result;
    result = process_typedef(3, 2, sum);
    printf("%d\n", result); 
    result = process_default(2, 3, sub);
    printf("%d\n", result);
    return 0;
}

int process_typedef(int a, int b, fun_tp func)
{
    return func(a, b);
}

int process_default(int a, int b, int(*func)(int, int))
{
    return func(a, b);
}

int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}
```
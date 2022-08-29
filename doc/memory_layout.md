# 普通程序内存空间布局

一个典型的C程序存储分区包含以下几类：
1. Text段
2. 已初始化数据段
3. 未初始化数据段
4. 栈
5. 堆

![memory](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

## 1. Text段(size 命令中的 text)

Text段通常也称为代码段，由可执行指令构成，是程序在目标文件或内存中的一部分，Text段通常放在栈或堆的下面，以防止堆栈溢出篡改其数据。

通常情况下，Text段是可共享的，对于需要频繁调用的程序，其在内存中只需要一份拷贝即可，如文本编辑器、C编译器、Shell等，因此text段通常设为只读以防止程序的突发性的修改。

```c
int test(int i, int j)
{
    return i + j;
}
```

```bash
wj@wj:~/tmp$ gcc -c main.c && size  main.o
   text    data     bss     dec     hex filename
    112       0       0     112      70 main.o
```
- 函数里的char *字符串也存放在text段中
```c
char* test()
{
    char* str = "hello, world";
    return str;
}
```
```bash
wj@wj:~/tmp$ gcc -c main.c && size  main.o
   text    data     bss     dec     hex filename
    126       0       0     126      7e main.o
```

## 2. 已初始化数据段(size 命令中的 data)

已初始化数据段，通常简单称作数据段，数据段占据程序虚拟地址空间的一部分，内部包括
- 初始化为非0的全局变量
- 静态变量（程序负责初始化这些变量）。需注意的是，数据段不是只读的，在运行时变量值是可以变动的。
- 只读字符串

数据段还可以更细的分为初始化只读区以及初始化可读写区。

举例：全局字符串 char s[] = “hello world”，全局变量 int debug=1，静态变量 static int i = 10 存储在初始化可读写区；另一种情况下，const char* string = “hello world”，字符串“hello world”存储在初始化只读区，string指针则存在初始化可读写区。

```c
int    m = 1;
double d = 3.1415;
int    test(int i, int j)
{
    return i + j;
}
```
```bash
wj@wj:~/tmp$ gcc -c main.c && size  main.o
   text    data     bss     dec     hex filename
    112      16       0     128      80 main.o
```
int占用4个字节，double占用8个字节，因为内存对其的原因，实际占用了16个字节

## 3. 未初始化数据段(size 命令中的 bss)

未初始化数据段，通常称作“bss”段，名字来源于古老的汇编操作符命名 “block started by symbol”，段内的数据在程序开始执行之前被内核初始化为0值，通常开始于已初始化数据段的末尾处。段内包含初始化为0的全局变量/静态变量以及源码中未显示进行初始化的变量。

举例：变量 static int i;  全局变量 int j;  包含在BBS段中。

## 4. 栈

栈与堆是相互毗邻的，并且生长方向相反；当栈指针触及到堆指针位置，意味着栈空间已经被耗尽（如今地址空间越来越大，及虚拟内存技术发展，栈与堆可能放置在内存的任何地方，但生长方向依然还是相向的）。

## 5. 堆

堆通常用作动态内存分配，堆空间起始于BSS段的末尾，并向高地址处生长，堆空间通常由malloc, realloc 及 free管理，这些接口可能再使用brk/sbrk系统调用来调整大小，在一个进程中，堆空间被进程内所有的共享库及动态加载模块所共享。

# 进程内存布局
和普通程序相比

![process-memory](https://img-blog.csdn.net/20130612184703765)

# [c++对象内存布局](https://www.cnblogs.com/QG-whz/p/4909359.html)
## 概述
在C++中，有两种数据成员（class data members）：
- static 
- nonstatic

以及三种类成员函数（class member functions）:
- static
- nonstatic
- virtual:
![](https://images2015.cnblogs.com/blog/610439/201510/610439-20151025195300333-1476474890.png)

## 基类对象模型
1. nonstatic 数据成员被置于每一个类对象中
2. static数据成员被置于类对象之外
3. static与nonstatic函数也都放在类对象之外
4. 虚函数
   - 每个**类**生成一个表格，称为虚表（virtual table，简称vtbl）。虚表中存放着一堆指针，这些指针指向该类每一个虚函数。虚表中的函数地址将按声明时的顺序排列，不过当子类有多个重载函数时例外，后面会讨论。
   - 每个**类对象**都拥有一个虚表指针(vptr)，由编译器为其生成。

## 单继承

# 查看程序段的大小
- size
- objdump
- nm
- readelf
```bash
size filename

```
# const和普通变量
```c
const int x = 3;
int const y = 4;
```
无论const在什么位置，定义的变量都不可修改

# const和指针变量
```c
const int *p1;
int const *p2;
int *const p3;
```
根据`const`和`*`位置，可以划分为两种情况
- `const`在`*`左边，表示指针指向的数据是只读的，不能通过`*p1 = x`去修改，但指针可以重新指向其他变量
  ```c
    int a = 3;
    int b = 4;
    int d = 6;
    const int *p1 = &a;
    int const *p2 = &b;

    *p1 = 1; // error: assignment of read-only location '*p1'
    *p2 = 2; // error
    p1 = &d;    
    p2 = &d;
  ```
- `const`在`*`右边，表示指针本身是只读的，
```c
    int c = 5;
    int d = 6;

    int *const p3 = &c;

    *p3 = 1;
    p3 = &d; // error: assignment of read-only variable 'p3'
```
# 类
## 构造函数
###  default关键字
声明了构造函数后，编译器就不会再创建默认构造函数。如果这时还需要使用默认的构造函数，可以有两种办法
```cpp
// 1. 显示声明默认的构造函数
Box() {} // Default constructor
// 2. 使用default关键字
Box() = default; // Defaulted default constructor
```

## 构造函数的初始化列表
可以使类的初始化更加简洁
```cpp
#include <iostream>
using namespace std;
class Student{
private:
    char *m_name;
    int m_age;
    float m_score;
public:
    Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score)
    {}
    void show();
};
```

## C++对象内存布局
[内存布局](../memory_layout.md#c对象内存布局)

## 静态成员变量
static成员变量，不占用类实例的内存空间
1. 静态成员变量不能在类内进行初始化， 可以在类外初始化，或者添加const属性
```cpp
class TestStaticMember
{
public:
    static  int m_nValue{1};  // error: ISO C++ forbids in-class initialization of non-const static member ‘TestStaticMember::m_nValue’
    static const int m_nValue{1};
};
int TestStaticMember::m_nValue = 1;
```
2. static 成员变量不占用对象的内存，而是在所有对象之外开辟内存，即使不创建对象也可以访问
3. 静态成员变量既可以通过对象名访问，也可以通过类名访问

## 静态成员函数
1. 普通成员函数可以访问所有成员（包括成员变量和成员函数），静态成员函数只能访问静态成员。

# 三五法则
三五法则规定了什么时候需要拷贝构造函数、拷贝赋值函数、析构函数等

## 什么时候需要析构函数
最常见的是，当类成员里有指针成员

## 什么时候需要拷贝构造函数
如果类的设计者不写复制构造函数，编译器就会自动生成复制构造函数

当类里有指针成员时，两个对象的指针变量同时指向同一块内存，指向同一块内存的后果很有可能是在两个对象中的析构函数中先后被释放两次。
所以需要额外的拷贝控制函数去控制相应资源的拷贝。

## 什么时候需要拷贝赋值函数
和上面类似

# 基类和派生类的构造函数
的构造函数不能被继承。因为即使继承了，它的名字和派生类的名字也不一样，不能成为派生类的构造函数，当然更不能成为普通的成员函数。

在设计派生类时，对`继承过来有 private 属性的成员变量的初始化工作也要由派生类的构造函数`完成，它们在派生类中无法访问，更不能使用派生类的构造函数来初始化。

解决这个问题的思路是：在派生类的构造函数中调用基类的构造函数。
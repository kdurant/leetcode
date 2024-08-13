- 静态类型：对象在声明时采用的类型，在编译期已经确定
- 动态类型：通常是指一个指针或者引用目前所指对象的类型，是在运行期决定的
- 静态绑定：绑定的是静态类型，所对应的函数或属性依赖于对象的静态类型，发生编译期
- 动态绑定：绑定的是动态类型，所对应的函数或者属性依赖于对象的动态类型，发生在运行期
  
从上面的定义可以看出，非虚函数一般都是静态绑定，而虚函数都是动态绑定。

使用基类的的引用或者指针调用虚成员函数时，会发生动态绑定

```cpp
#include <vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;
class A
{
public:
    void func()
    {
        cout << "A::func()" << endl;
    }
    virtual void vfunc()
    {
        cout << "virtual A::func()" << endl;
    }
};

class B : public A
{
public:
    void func()
    {
        cout << "B::func()" << endl;
    }

    virtual void vfunc()
    {
        cout << "virtual B::func()" << endl;
    }
};

class C : public A
{
public:
    void func()
    {
        cout << "C::func()" << endl;
    }

    virtual void vfunc()
    {
        cout << "virtual C::func()" << endl;
    }
};

int main(void)
{
    // pc的静态类型是C*, 动态类型也是C*
    C *pc = new C();
    // pc的静态类型是B*, 动态类型也是B*
    B *pb = new B();
    // pa的静态类型是A*, 动态类型是C*
    A *pa = pc;

    pa->func();
    pb->func();
    pc->func();

    pa->vfunc();
    pb->vfunc();
    pc->vfunc();

    return 0;
}
```
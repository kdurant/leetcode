# std::function
函数模板std::function是一个通用的多态函数包装器。

# std::bind
bind可以根据当前已有的可调用对象，构造出一个新的可调用对象，有了bind，我们可以实现“动态生成新的函数”的功能。简而言之，就是可以通过bind函数修改原函数并生成一个可以被调用的对象，类似于函数的重载，但是我们又不需要去重新写一个函数，用bind函数就可以实现。


## 绑定普通函数
```cpp
#include <iostream>
#include <functional>
#include <string>

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n'
              << "n3 = " << n3 << '\n'
              << "n4 = " << n4 << '\n'
              << "n5 = " << n5 << '\n';
}

int main(void)
{
    auto f1 = std::bind(f, std::placeholders::_1, 2, 3, 4, 5);
    f1(1);

    auto f2 = std::bind(f, std::placeholders::_2, 2, 3, 4, std::placeholders::_1);
    f2(1, 5);

    return 0;
}
```

## 绑定类的成员函数
注意类成员函数有个隐藏的this指针

## 绑定到类的数据成员

# std::mem_fn
函数模板std::mem_fn为成员函数的指针生成包装器对象
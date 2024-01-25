构造函数在定义类的新实例时被调用，在创建新对象时初始化新对象，确保新对象的成员变量包含有效的值。
# 默认构造

# 拷贝构造

# 移动构造

# 赋值操作符

# 移动赋值操作符

# 委托构造函数

```cpp
#include <iostream>
using namespace std;

class Demo
{
private:
    int* num;

public:
    // 对象不存在，且没用别的对象来初始化，就是调用了构造函数
    //  Demo d;
    Demo()
        : num(new int(0))
    {
        cout << "enter default construct!" << endl;
    }
    Demo(int n)
        : num(new int(n))
    {
        cout << "enter default construct!" << endl;
    }

    // 拷贝构造函数，对象不存在，且用别的对象来初始化
    // Demo d();
    // Demo e(d);
    Demo(const Demo& cpy)
        : num(new int(*cpy.num))
    {
        cout << "enter copy construct!" << endl;
        ;
    }

    // 赋值构造函数，对象存在，用别的对象来给它赋值
    // Demo d;
    // Demo f;
    // f = d;
    Demo& operator=(const Demo& assign)
    {
        cout << "enter assign construct!" << endl;
        this->num = new int(*assign.num);
        return *this;
    };

    // 移动构造函数，利用即将删除的内存空间里的数据，提升程序性能
    // -fno-elide-constructors
    //
    Demo(Demo&& mov)
        : num(mov.num)
    {
        mov.num = nullptr;
        cout << "enter move construct!" << endl;
    }

    ~Demo()
    {
        delete num;
        cout << "leave destruct!" << endl;
    }

    // 类内声明，类外定义，非成员函数，但可以直接访问类私有变量
    // friend void func(Demo & data);
};

Demo getDemo()
{
    return Demo();
}

int main(void)
{
    Demo d = getDemo();

    return 0;
}
```
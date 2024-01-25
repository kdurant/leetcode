在C++中，函数对象（Function Object）是可调用对象的一种类型。可调用对象是指能够像函数一样被调用的对象，包括函数指针、函数、Lambda 表达式和函数对象。
它是实现operator()重载的任何类型,此运算符被称为调用运算符,当调用此操 作符时,其表现形式如同普通函数调用一般,因此取名叫`函数对象`。

本质上是一个类对象,它可以像函数一样被调用,可以作为参数传递给其他函数,也可以作为函数的返回值。

```cpp
class Add {
    int operator()(int a, int b) {
        return a + b;
    }
};

Add add;
int result = add(3, 4);  // 结果是7
```

# 函数对象和函数指针区别

# std::function
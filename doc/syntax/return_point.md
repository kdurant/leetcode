函数返回值是指针时，不能返回函数内部局部变量的地址，因为函数内部的局部变量在函数运行结束后生存期结束。
```c
int *func(int i)
{
    int r = i*2;
    return &r;
}
```

https://blog.csdn.net/modi000/article/details/103398721

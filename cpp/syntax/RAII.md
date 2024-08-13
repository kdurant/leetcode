# 作用
智能指针就是程序员管理动态分配的内存的，它会帮助我们自动释放new出来的内存，从而避免内存泄漏！

# 内存泄露的例子
```cpp
#include <iostream>
#include <string>
#include <memory>

using namespace std;


// 动态分配内存，没有释放就return
void memoryLeak1() {
	string *str = new string("动态分配内存！");
	return;
}

// 动态分配内存，虽然有些释放内存的代码，但是被半路截胡return了
int memoryLeak2() {
	string *str = new string("内存泄露！");

	// ...此处省略一万行代码

	// 发生某些异常，需要结束函数
	if (1) {
		return -1;
	}
	/
	// 另外，使用try、catch结束函数，也会造成内存泄漏！
	/

	delete str;	// 虽然写了释放内存的代码，但是遭到函数中段返回，使得指针没有得到释放
	return 1;
}


int main(void) {

	memoryLeak1();

	memoryLeak2();

	return 0;
} 
```


# std::shared_ptr
采用引用计数的智能指针。 如果你想要将一个原始指针分配给多个所有者（例如，从容器返回了指针副本又想保留原始指针时），请使用该指针。

直至所有 shared_ptr 所有者超出了范围或放弃所有权，才会删除原始指针。

```cpp
//1
auto sp1 = make_shared<int>(100);
//2
shared_ptr<int> sp1 = make_shared<int>(100);
//3
shared_ptr<int> sp1(new int(100));
//err
shared_ptr<int> p = new int(1);
```

# std::unique_ptr
它持有对对象的独有权——两个unique_ptr不能指向一个对象，即 unique_ptr 不共享它所管理的对象。

# std::weak_ptr




[c++智能指针介绍与使用](https://juejin.cn/post/7137133849430982693)
# AddressSanitizer: 
AddressSanitizer（ASan）是一个快速的内存错误检测工具。它非常快，只拖慢程序两倍左右。它包括一个编译器instrumentation模块和一个提供malloc()/free()替代项的运行时库。从gcc 4.8开始，AddressSanitizer成为gcc的一部分。

# 使用
在编译时加入选项`-fsanitize=address`，然后运行程序即可

# 

## heap-buffer-overflow 堆缓存访问溢出
访问的位置超出堆上数组array的边界，会产生这个问题
```c
bool rotateString(char* A, char* B)
{
    int   len = strlen(A);
    if((strlen(A) == 0) && (strlen(B) == 0))
        return true;
    int   i = 0;
    char* s = calloc(len, sizeof(char));

    // nihao
    while(i < len)
    {
        strncpy_s(s, len + 1, A + i, len - i);  //
        strncpy_s(s + len - i, len + 1, A, i);
        i++;
        if(strcmp(s, B) == 0)
            return true;
    }
    return false;
}

int main(void)
{
    char A[] = "abcde";
    char B[] = "cdeab";
    printf("%d\n", rotateString(A, B));
    return 0;
}
```
给s分配内存的时候，少分配了'\0'的空间，`strcmp`的时候会出现这个问题

```cpp
int main(int argc, char** argv)
{
    int* array = new int[100];
    int  res   = array[100];
    // delete[] array;
    return res;
}
```

## stack buffer overflow 栈缓存访问溢出
```cpp
int main(int argc, char** argv)
{
    int array[100];
    return array[100];
}
```

## global buffer overflow 全局缓冲访问溢出
```cpp
int array[100];

int main (int argc, char** argv)
{
    return array[100];
}
```


## heap-use-after-free
```cpp
int main(int argc, char** argv)
{
    int* array = new int[100];
    delete[] array;
    return array[1];
}
```

# LeakSanitizer: 
检测内存的LeakSanitizer是集成在AddressSanitizer中的一个相对独立的工具，它工作在检查过程的最后阶段。
## detected memory leaks
```c
#include <stdlib.h>
void* p;

int main()
{
    p = malloc(7);
    p = 0;
    return 0;
}

```

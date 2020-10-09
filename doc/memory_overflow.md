AddressSanitizer: 
# heap-buffer-overflow 堆缓存访问溢出
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

# stack buffer overflow 栈缓存访问溢出

# global buffer overflow 全局缓冲访问溢出

LeakSanitizer: 
# detected memory leaks
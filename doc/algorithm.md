# search_n
```cpp
//在 [first, last] 中查找 count 个 val 第一次连续出现的位置
search_n( ForwardIt first, ForwardIt last, Size count, const T& value );

//在 [first, last] 中查找第一个序列，该序列和 count 个 val 满足 pred 匹配规则
ForwardIterator search_n ( ForwardIterator first, ForwardIterator last, Size count, const T& val, BinaryPredicate pred );
```


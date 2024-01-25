# find
# find_if
# find_if_not
# find_end
# find_first_of
# adjacent_find
# count
# count_if
# mismatch
# equal
# is_permutation
# search

# search_n
```cpp
//在 [first, last]区间 中查找 count 个 val 第一次连续出现的位置
search_n( ForwardIt first, ForwardIt last, Size count, const T& value );

//在 [first, last] 中查找第一个序列，该序列和 count 个 val 满足 pred 匹配规则
ForwardIterator search_n ( ForwardIterator first, ForwardIterator last, Size count, const T& val, BinaryPredicate pred );
```


# accumulate
```cpp
// 计算 [first, last) 区间内的元素的累加值，并加上 init(初始值)
T accumulate (InputIterator first, InputIterator last, T init);

// 还可以接受一个自定义运算作为第四个参数
T accumulate( InputIt first, InputIt last, T init,  BinaryOperation op );
```


https://zhuanlan.zhihu.com/p/92074597

# 功能
该工具可以检测下列与内存相关的问题 :
- 未释放内存的使用
- 对释放后内存的读/写
- 对已分配内存块尾部的读/写
- 内存泄露
- 不匹配的使用malloc/new/new[] 和 free/delete/delete[]
- 重复释放内存

# 使用
`valgrind --tool=memcheck ./a.out`


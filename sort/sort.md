# 稳定排序
待排序的记录序列中可能存在两个或两个以上关键字相等的记录。排序前的序列中`Ri`领先于`Rj`（即i<j）.若在排序后的序列中`Ri`仍然领先于`Rj`，则称所用的方法是稳定的。


![sort](http://img.blog.csdn.net/20160909164911303?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

[常用排序算法总结(一)](https://www.cnblogs.com/eniac12/p/5329396.html)


# 插入排序
时间复杂度: O(N^2)
空间复杂度:
[插入排序（Insertion Sort）](https://www.cnblogs.com/shihaokiss/p/5449011.html)的算法描述是一种简单直观的排序算法。

工作原理:
1. 从第一个元素开始，该元素可以认为已经被排序
2. 取出下一个元素，在已经排序的元素序列中`从后向前`扫描
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
5. 将新元素插入到该位置中
6. 重复步骤2

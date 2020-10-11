# 基本术语
## 树
树是由 n(n>=0) 个有限节点组成一个具有层次关系的集合

## 根节点
树的首结点叫根结点

## 兄弟节点
两个具有相同父节点的节点称为兄弟节点(sibling) 

## 子树
一个节点的子节点以及子节点的后代称为该节点的子树 (subtree)

## 树的高度
从`下往上`数，高度是`叶子结点`（树得末端）到`树的根节点`（其深度为1）的长度

## 树的深度
从`上往下`数，从`根节点`到`该节点`的最长简单路径边的条数

> 注意：这里边的条数是规定根节点的深度和叶子节点的高度是0；
![](https://pic4.zhimg.com/80/v2-0e8c24776a03380a4db561d47f68847c_hd.jpg)

(https://henleylee.github.io/posts/2019/f30c2ae3.html)

# 二叉树
二叉树是数据结构中一种重要的数据结构，也是树表家族最为`基础的结构`。
## 定义
二叉树(Binary Tree)是一个有根树，并且每个节点最多只有2棵子树(即二叉树中不存在度大于2的结点)，并且二叉树的子树有左右之分，其次序不能任意颠倒。
![binary tree](https://henleylee.github.io/medias/study/data_structure_binary_tree.png)
1. 二叉树的第n层`最多有`$2^{n-1}$个节点  
2. 深度为i的二叉树`最多有`$2^{i-1}$个节点
3. 具有 n 个结点的完全二叉树的深度为$log2(n+1)$;

# 满二叉树（Full Binary Tree）
除最后一层无任何子节点外，每一层上的所有结点都有两个子结点。也可以这样理解，除叶子结点外的所有结点均有两个子结点。节点数达到最大值，所有叶子结点必须在同一层上。
![](https://upload-images.jianshu.io/upload_images/1630488-d87b70e0df31dc74.png?imageMogr2/auto-orient/strip|imageView2/2/w/534/format/webp)

# 完全二叉树
如果二叉树中除去最后一层节点为满二叉树，且最后一层的结点依次从左到右分布，则此二叉树被称为完全二叉树

> 满二叉树一定是完全二叉树，完全二叉树不一定满二叉树。

# 二叉搜索树(Binary Search Tree)
二叉搜索树是一种特殊的二叉树，也可以称为`二叉排序树`，`二叉查找树`。除了具有二叉树的基本性质外，它还具备：

1. 树中每个节点最多有两个子树，通常称为左子树和右子树
2. 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值
3. 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值
4. 它的左右子树仍然是一棵二叉搜索树 (recursive)
![](https://upload-images.jianshu.io/upload_images/1630488-60da433cfb7b6a03.png?imageMogr2/auto-orient/strip|imageView2/2/w/444/format/webp)

## [遍历方式](https://juejin.im/post/5bf20e10e51d4503a53fd940)
1. 前序遍历：当到达某个节点时，先输出该节点，再访问左子节点，最后访问右子节点。
   ![](https://user-gold-cdn.xitu.io/2018/11/19/1672986e90745927?imageslim)
2. 中序遍历：当到达某个节点时，先访问左子节点，再输出该节点，最后访问右子节点。
   ![](https://upload-images.jianshu.io/upload_images/1940317-51cb2fc5f97df92d.gif?imageMogr2/auto-orient/strip|imageView2/2/w/951/format/webp)
3. 后序遍历：当到达某个节点时，先访问左子节点，再访问右子节点，最后输出该节点。
   ![](https://upload-images.jianshu.io/upload_images/1940317-37d0ee8c681d55fe.gif?imageMogr2/auto-orient/strip|imageView2/2/w/951/format/webp)

4. 广度优先
   层序，横向访问
   ![](https://charlesliuyx.github.io/2018/10/22/%E3%80%90%E7%9B%B4%E8%A7%82%E7%AE%97%E6%B3%95%E3%80%91%E6%A0%91%E7%9A%84%E5%9F%BA%E6%9C%AC%E6%93%8D%E4%BD%9C/Breadth-First.png)
5. 深度优先
   纵向，探底到叶子节点
   ![](https://charlesliuyx.github.io/2018/10/22/%E3%80%90%E7%9B%B4%E8%A7%82%E7%AE%97%E6%B3%95%E3%80%91%E6%A0%91%E7%9A%84%E5%9F%BA%E6%9C%AC%E6%93%8D%E4%BD%9C/Deep-First.png)


# 平衡二叉树（Self-Balancing Binary Search Tree）
平衡二叉树也叫自平衡二叉搜索树，所以其本质也是一颗`二叉搜索树`，不过为了限制左右子树的高度差，避免出现倾斜树等偏向于线性结构演化的情况，所以对二叉搜索树中每个节点的左右子树作了限制，左右子树的高度差称之为平衡因子，树中每个节点的平衡因子绝对值不大于 ，此时二叉搜索树称之为平衡二叉树。

`自平衡`是指，在对平衡二叉树执行插入或删除节点操作后，可能会导致树中某个节点的平衡因子绝对值超过 1，即平衡二叉树变得“不平衡”，为了恢复该节点左右子树的平衡，此时需要对节点执行旋转操作。

# 2-3 树

# 红黑树

- 二叉树: 每个节点最多有两个子树的树结构
    
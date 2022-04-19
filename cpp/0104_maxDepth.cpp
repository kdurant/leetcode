/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    /**
     * @brief 二叉树的最大深度(https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)
     * Max depth = max(l, r)+1;
     * @param root
     *
     * @return
     */
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(void)
{
    TreeNode *root = new TreeNode(100);
    root->left     = new TreeNode(50);
    root->right    = new TreeNode(150);

    root->left->left  = new TreeNode(25);
    root->left->right = new TreeNode(75);

    root->right->left  = new TreeNode(125);
    root->right->right = new TreeNode(175);

    Solution s;
    cout << "The max depth of tree is: " << s.maxDepth(root) << endl;
    return 0;
}


/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

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
    void inorder(TreeNode *root, vector<int> &res)
    {
        if(!root)
            return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    // 递归方式实现中序遍历
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);

        return res;
    }

    // 迭代方式实现中序遍历
    vector<int> inorderTraversal_1(TreeNode *root)
    {
        stack<TreeNode *> S;
        vector<int>       res;

        TreeNode *rt = root;
        while(rt || S.size())
        {
            // 先把根及其左节点压入栈中
            while(rt)
            {
                S.push(rt);
                rt = rt->left;
            }
            rt = S.top();
            S.pop();
            res.push_back(rt->val);
            // 取出根的右节点重复上面步骤
            rt = rt->right;
        }
        return res;
    }
};

int main(void)
{
    TreeNode *root = new TreeNode(100);

    root->left  = new TreeNode(50);
    root->right = new TreeNode(150);

    root->left->left  = new TreeNode(25);
    root->left->right = new TreeNode(75);

    root->right->left  = new TreeNode(125);
    root->right->right = new TreeNode(175);

    Solution s;
    // vector<int> ret = s.inorderTraversal(root);
    vector<int> ret = s.inorderTraversal_1(root);

    for(int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }

    return 0;
}


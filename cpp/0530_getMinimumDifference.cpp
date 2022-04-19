#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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

class TreeBinary
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
    /**
     * @brief 94.二叉树的中序遍历(https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)
     *
     * @param root
     * @return vector<int>
     */
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);

        return res;
    }

    /**
     * @brief 530. 二叉搜索树的最小绝对差(https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/)
     *
     * @param root
     * @return
     */
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> diff = inorderTraversal(root);

        int ret = diff[1] - diff[0];

        for(int i = 1; i < diff.size(); i++)
        {
            if(diff[i] - diff[i - 1] < ret)
                ret = diff[i] - diff[i - 1];
        }
        return ret;
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

    TreeBinary          s;
    vector<vector<int>> ret = s.levelOrder(root);

    for(int i = 0; i < ret.size(); i++)
    {
        for(int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "The max depth of tree is: " << s.maxDepth(root) << endl;
    return 0;
}

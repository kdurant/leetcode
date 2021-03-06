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
    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {
    }
};

class TreeBinary
{
public:
    /**
     * @brief 102. 二叉树的层序遍历(广度遍历BFS)(https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
     *
     * @param root
     *
     * @return
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;

        if(!root)
            return ret;

        queue<TreeNode *> q;
        q.push(root);

        while(q.empty() == false)
        {
            int currentLevelSize = q.size();

            ret.push_back(vector<int>());  // 每次放进去一个一维数组，存放本层的数据

            for(int i = 0; i < currentLevelSize; i++)
            {
                auto node = q.front();            // 获得存放的节点内容
                q.pop();                          // 从queue中弹出节点
                ret.back().push_back(node->val);  // 把node的值放到二维数组中
                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }
        return ret;
    }

    /**
     * @brief 104. 二叉树的最大深度(https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)
     * Max depth = max(l, r)+1;
     * 
     * @brief 中序遍历
     * @param root
     * @return
     */
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

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
     * @brief 110. 平衡二叉树(https://leetcode-cn.com/problems/balanced-binary-tree/)
     *
     * @param root
     * @return
     */
    int helper(TreeNode *root)
    {
        if(!root)
            return 0;

        int left  = helper(root->left);
        int right = helper(root->right);

        if(left == -1 || right == -1 || abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        return helper(root) != -1;
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

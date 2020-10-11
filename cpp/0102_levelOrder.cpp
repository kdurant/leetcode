/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <queue>
#include <vector>

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

    Solution            s;
    vector<vector<int>> ret = s.levelOrder(root);

    for(int i = 0; i < ret.size(); i++)
    {
        for(int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}


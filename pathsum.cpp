#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isleaf(TreeNode *root)
    {
        if(root->left || root->right)
        {
            return false;
        }
        return true;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }
        if (targetSum == root->val && isleaf(root))
        {
            return true;
        }
        else
        {
            if (hasPathSum(root->left, targetSum - root->val) ||
                hasPathSum(root->right, targetSum - root->val))
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}
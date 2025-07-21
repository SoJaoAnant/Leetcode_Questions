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
    int calc_left_height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return 1 + calc_left_height(root->left);
    }

    int calc_right_height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return 1 + calc_right_height(root->right);
    }

    int countNodes(TreeNode *root)
    {
        int left_height = calc_left_height(root);
        int right_height = calc_right_height(root);

        if (left_height == right_height)
        {
            return pow(2, left_height) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{

    return 0;
}
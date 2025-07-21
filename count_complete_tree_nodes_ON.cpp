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
    int countNodes(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int nodes = 1;
        nodes += countNodes(root->left);
        nodes += countNodes(root->right);

        return nodes;
    }
};

int main()
{

    return 0;
}
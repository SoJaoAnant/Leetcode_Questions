
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
    TreeNode *make_BST(vector<int> nums, int i, int j)
    {
        if (i > j)
            return NULL;
        
        int mid = (i + j) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = make_BST(nums, i, mid - 1);
        root->right = make_BST(nums, mid + 1, j);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return make_BST(nums, 0, nums.size() - 1);
    }
};

int main()
{
    return 0;
}
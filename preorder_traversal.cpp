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
    void postorder(TreeNode *r, vector<int> &p)
    {
        if (r != NULL)
        {
            p.push_back(r->val);
            postorder(r->left, p);
            postorder(r->right, p);
        }
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> post;
        postorder(root, post);

        cout << post.size() << endl;

        return post;
    }
};

int main()
{

    return 0;
}
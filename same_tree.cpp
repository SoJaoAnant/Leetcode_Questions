#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    bool chk(TreeNode *r1, TreeNode *r2)
    {
        if(r1 != r2){return false;}
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return chk(p, q);
    }
};

int main()
{
    return 0;
}
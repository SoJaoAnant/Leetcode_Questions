#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode * n = node->next;
        node->val = (node->next)->val;
        node->next = n->next;
    }
};

int main()
{

    return 0;
}
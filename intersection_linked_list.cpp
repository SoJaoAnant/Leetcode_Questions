#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *n = NULL;

        while (headA != NULL)
        {
            while (headB != NULL)
            {
                if (headA->val == headB->val)
                {
                    delete (n);
                    n = new ListNode(headA->val);
                }
                headB = headB->next;
            }
            headA = headA->next;
        }

        if (n == NULL)
        {
            cout << "null hai mc" << endl;
        }
        else
        {
            cout << n->val << endl;
        }

        return n;
    }
};

int main()
{
    return 0;
}
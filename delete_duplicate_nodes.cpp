#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        set<int> s;
        ListNode *n = head;
        while (n != NULL)
        {
            s.insert(n->val);
            n = n->next;
        }

        delete (n);
        ListNode *temphead = new ListNode(0);
        ListNode *tail = temphead;

        for (auto &it : s)
        {
            tail->next = new ListNode(it);
            tail = tail->next;
        }

        n = temphead->next;
        delete (temphead);

        return n;
    }
};

int main()
{

    return 0;
}
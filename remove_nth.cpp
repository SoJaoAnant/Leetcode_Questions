
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        struct ListNode *temp = head;
        struct ListNode *next = NULL;
        int len = 0;

        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        n = len - n;
        temp = head;

        if (n == 0)
        {
            cout << temp->val << endl;
            head->next = NULL;
        }
        else
        {
            n--;
            while (n--)
            {
                temp = temp->next;
            }
            next = temp->next;
            cout << temp->val << endl;
            cout << next->val << endl;
            next->next = temp->next;
            temp->next = NULL;
        }

        return head;
    }
};

int main()
{

    return 0;
}
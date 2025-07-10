#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        struct ListNode *rabbit = head;
        struct ListNode *turtle = head;

        while (rabbit != NULL)
        {
            turtle = turtle->next;
            rabbit = rabbit->next;
            if (rabbit == NULL)
            {
                return false;
            }
            else
            {
                rabbit = rabbit->next;
            }
            if (rabbit == turtle)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}
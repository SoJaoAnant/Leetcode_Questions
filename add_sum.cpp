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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *ans = head;
        int sum = 0, ten = 1, carry = 0;
        while ((l1 != NULL) && (l2 != NULL))
        {
            sum += (l1->val) + (l2->val) + carry;
            cout << sum << endl;
            cout << carry << endl;
            carry = sum / 10;
            if (carry == 0)
            {
                ListNode *node = new ListNode(sum);
                ans->next = node;
                ans = ans->next;
            }
            else
            {
                ListNode *node = new ListNode(sum % 10);
                ans->next = node;
                ans = ans->next;
            }

            sum = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *result = head->next;
        return result;
    }
};

int main()
{

    return 0;
}
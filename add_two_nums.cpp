#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temphead = new ListNode(0);
        ListNode *tail = temphead;
        ListNode *ans;
        int carry = 0;
        int sum = 0;
        cout << "start" << endl;
        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            if (l1 == NULL && l2 == NULL)
            {
                sum = carry;
            }
            else if (l2 == NULL)
            {
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else if (l1 == NULL)
            {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else
            {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            cout << sum << endl;
            if (sum >= 10)
            {
                cout << "doing if" << endl;
                carry = 1;
                sum = sum - 10;
            }
            else
            {
                cout << "doing else" << endl;
                carry = 0;
            }
            tail->next = new ListNode(sum);
            tail = tail->next;
        }
        cout << "end" << endl;
        ans = temphead->next;
        delete (temphead);
        return ans;
    }
};

int main()
{

    return 0;
}
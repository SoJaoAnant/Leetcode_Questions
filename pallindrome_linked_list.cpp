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
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp_head = new ListNode(head->val);
        ListNode *new_head = temp_head;
        ListNode *pointer = head->next;

        while (pointer != NULL)
        {
            temp_head->next = new ListNode(pointer->val);
            pointer = pointer->next;
            temp_head = temp_head->next;
        }

        delete (temp_head);

        ListNode *prev = NULL;
        ListNode *curr = new_head;
        ListNode *next = new_head->next;

        while (next != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }

        new_head = next;

        while (new_head != NULL)
        {
            cout << new_head->val << " ";
            new_head = new_head->next;
        }
        cout << endl;
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }

        return true;
    }
};

int main()
{

    return 0;
}
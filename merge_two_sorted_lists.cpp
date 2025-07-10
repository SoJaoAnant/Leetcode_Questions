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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        vector<int> elements;

        while (list1 != NULL)
        {
            elements.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            elements.push_back(list2->val);
            list2 = list2->next;
        }

        sort(elements.begin(), elements.end());

        for (auto &it : elements)
        {
            tail->next = new ListNode(it);
            tail = tail->next;
        }
        
        ListNode *result = head->next;
        delete (head);
        return result;
    }
};

int main()
{

    return 0;
}
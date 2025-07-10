#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print_(stack<char> s)
    {
        while (s.empty() == false)
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
    bool backspaceCompare(string s, string t)
    {
        stack<char> S;
        stack<char> T;
        int i = 0;
        while (i != s.length())
        {
            if ((s[i] == '#'))
            {
                if (S.empty())
                {
                }
                else
                {
                    S.pop();
                }
            }
            else
            {
                S.push(s[i]);
            }
            i++;
        }

        i = 0;
        while (i != t.length())
        {
            if ((t[i] == '#'))
            {
                if (T.empty())
                {
                }
                else
                {
                    T.pop();
                }
            }
            else
            {
                T.push(t[i]);
            }
            i++;
        }
        print_(S);
        print_(T);
        if (S != T)
        {
            return false;
        }
        return true;
    }
};
int main()
{

    return 0;
}
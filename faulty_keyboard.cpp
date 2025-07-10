#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverse_sub(string &s, int i, int j)
    {
        while (i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }

    string finalString(string s)
    {
        for (int i = 0; s[i]; i++)
        {
            if (s[i] == 'i')
            {
                s.erase(i, 1);
                reverse_sub(s, 0, i);
                i--;
            }
        }

        return s;
    }
};

int main()
{

    return 0;
}
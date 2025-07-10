#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        char c = s[0];
        int ans = 0;
        bool ans_ = false;

        for (int i = 1; s[i]; i++)
        {
            if (s[i] == c)
            {
                c = s[i];
                ans = i;
                ans_ = true;
            }
        }

        if (ans)
        {
            return ans;
        }
        return -1;
    }
};

int main()
{
    return 0;
}
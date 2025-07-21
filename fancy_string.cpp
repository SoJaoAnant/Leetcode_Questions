#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans = "";
        int count = 0;
        char curr;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == curr)
            {
                if (count < 2)
                {
                    ans += s[i];
                    count += 1;
                }
                else
                {
                    count = 0;
                    while (s[i + 1] == curr)
                    {
                        i += 1;
                    }
                }
            }
            else
            {
                curr = s[i];
                ans += s[i];
                count = 1;
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    string makeFancyString(string s) {
        int idx = 0;

        for(int i = 0; i < s.size(); i++){
            if(idx < 2 || s[idx - 1] != s[idx - 2] || s[idx - 1] != s[i])
                s[idx++] = s[i];
        }

        return s.substr(0, idx);
    }
};


int main()
{
    Solution obj;
    cout << obj.makeFancyString("leeettttcoddddee");

    return 0;
}
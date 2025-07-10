#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string add_chars(string s, int offset, int offset_2, int i)
    {
        string ans = "";
        if (i == 0)
        {
            while (i < s.length())
            {
                ans += s[i];
                i += offset;
            }
        }
        else
        {
            while (i < s.length())
            {
                ans += s[i];
                if (offset_2 != 0 && i+offset_2 < s.length())
                {
                    ans += s[i + offset_2];
                }
                i += offset;
            }
        }
        return ans;
    }

    string convert(string s, int numRows)
    {
        
        if(numRows == 1)
        {
            return s;
        }
        
        string ans = "";
        for (int i = 0; i < numRows; i++)
        {
            int offset = 2 * (numRows - 1);
            int offset_2 = 2 * (numRows - 1) - (i * 2);
            ans += add_chars(s, offset, offset_2, i);
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    string ans = obj.convert("PAYPALISHIRING", 3);
    for (char c : ans)
    {
        cout << c;
    }

    return 0;
}
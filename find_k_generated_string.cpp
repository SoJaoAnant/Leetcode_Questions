#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char next_char(char c)
    {
        if (c == 'z')
        {
            return 'a';
        }
        return c + 1;
    }

    char kthCharacter(int k)
    {
        string ans = "abbcbccdbccdcddebccdcddecddedeefbccdcddecddedeefcddedeefdeefeffgbccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfgghbccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfgghcddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfgghghhibccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfgghcddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfgghghhicddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfgghghhideefeffgeffgfggheffgfgghfgghghhieffgfgghfgghghhifgghghhighhihiij";
        string ans = "a";
        int i = 10;
        int j = 1;
        while (i--)
        {
            cout << j << " ";
            cout << ans << endl;
            for (char c : ans)
            {
                ans += next_char(c);
            }
            j += 1;
        }

        return ans[k - 1];
    }
};

int main()
{
    Solution obj;
    cout << obj.kthCharacter(5);

    return 0;
}
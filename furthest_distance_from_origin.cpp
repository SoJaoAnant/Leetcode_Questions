#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int lefts = 0;
        int rights = 0;
        int dashes = 0;

        for (char c : moves)
        {
            if (c == 'L')
            {
                lefts += 1;
            }
            else if (c == 'R')
            {
                rights += 1;
            }
            else
            {
                dashes += 1;
            }
        }

        if (lefts > rights)
        {
            return lefts + dashes - rights;
        }

        return rights + dashes - lefts;
    }
};

int main()
{

    return 0;
}
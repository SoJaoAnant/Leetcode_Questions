#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ugly;
        ugly.push_back(1);

        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; ++i)
        {
            int next_ugly = min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5});

            ugly[i] = next_ugly;

            if (next_ugly == ugly[i2] * 2)
                ++i2;
            if (next_ugly == ugly[i3] * 3)
                ++i3;
            if (next_ugly == ugly[i5] * 5)
                ++i5;
        }

        return ugly[n - 1];
    }
};

int main()
{

    return 0;
}
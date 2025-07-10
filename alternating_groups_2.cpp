#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int count = 0;
        int i = 0;
        int j = 0;
        int stop = colors.size() + (k - 1);
        int prev = colors[j];
        int size = 1;
        while (j != stop)
        {
            size = j - i + 1;
            if (size != k)
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
            cout << prev << " " << colors[j % colors.size()] << " " << size << endl;
            if (prev == colors[j % colors.size()])
            {
                i = j;
            }
            else if (prev != colors[j % colors.size()] && size == k)
            {
                count++;
            }
            prev = colors[j % colors.size()];
        }

        return count;
    }
};

int main()
{

    return 0;
}

/*
101010101010
0-2
101010101010
 1-3
101010101010
  2-4
101010101010
   3-5
101010101010
    4-6
101010101010
     5-7
101010101010
      6-8
101010101010
       7-9
101010101010
        8-10
101010101010
         9-11
101010101010
0         10-
101010101010






*/
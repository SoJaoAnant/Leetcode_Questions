#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print_(map<int, int> b)
    {
        for (auto &it : b)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
    bool lemonadeChange(vector<int> &bills)
    {
        map<int, int> billy;
        billy.insert(make_pair(5, 0));
        billy.insert(make_pair(10, 0));
        billy.insert(make_pair(20, 0));
        bool ans = true;
        for (auto &it : bills)
        {
            cout << 1 << endl;
            if (it == 5)
            {
                cout << 2 << endl;
                billy[it] += 1;
            }
            else if ((it == 10) && (billy[5] >= 1))
            {
                billy[10] += 1;
                cout << 3 << endl;
                billy[5] -= 1;
            }
            else if (it == 20)
            {
                billy[20] += 1;
                cout << 4 << endl;

                if (billy[5] >= 3)
                {
                    cout << 5 << endl;
                    billy[5] -= 3;
                }
                else if ((billy[5] >= 1) && (billy[10] >= 1))
                {
                    cout << 6 << endl;
                    billy[5] -= 2;
                    billy[10] -= 1;
                }
                else
                {
                    cout << 7 << endl;
                    ans = false;
                    break;
                }
            }
            else
            {
                print_(billy);
                cout << 8 << endl;
                ans = false;
                break;
            }
        }

        if (ans)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> bills = {5, 5, 5, 5, 10, 5, 10, 10, 10, 20};
    obj.lemonadeChange(bills);

    return 0;
}
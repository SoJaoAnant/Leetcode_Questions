#include <bits/stdc++.h>
using namespace std;

long long count_pos(vector<int> &b, int a, long mid)
{
    int low = 0;
    int high = b.size();

    while (low < high)
    {
        int m = (low + high) / 2;
        if ((long long)(a * b[m]) <= mid)
        {
            low = m + 1;
        }
        else
        {
            high = m;
        }
    }

    return low;
}

long long count_neg(vector<int> &b, int a, long mid)
{
    int low = 0;
    int high = b.size();

    while (low < high)
    {
        int m = (low + high) / 2;
        if ((long long)(a * b[m]) <= mid)
        {
            high = m;
        }
        else
        {
            low = m + 1;
        }
    }

    return b.size() - low;
}

long long count_prods(vector<int> &a, vector<int> &b, long long mid)
{
    long long count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= 0)
        {
            count += count_pos(b, a[i], mid);
        }
        else
        {
            count += count_neg(b, a[i], mid);
        }
    }
    return count;
}

int main()
{
    vector<int> a = {-2, -1, 0, 1, 2};
    vector<int> b = {-3, -1, 2, 4, 5};

    int mid = 3;
    cout << count_prods(a, b, mid) << endl;
    // cout << count_pos(a, 3, 4) << endl;
    // cout << count_neg(a, -3, 4) << endl;
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] * b[j] <= mid)
            {
                count++;
            }
            cout << a[i] * b[j] << " " << count << endl;
        }
    }

    return 0;
}
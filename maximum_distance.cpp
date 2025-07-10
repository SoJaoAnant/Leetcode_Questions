#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find_min(vector<vector<int>> &v, int r)
    {
        int min;
        if (r == 0)
        {
            min = v[1][0];
        }
        else
        {
            min = v[0][0];
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if ((min > v[i][j]) && (i != r))
                {
                    min = v[i][j];
                }
            }
        }

        return min;
    }

    int find_max(vector<vector<int>> &v, int &r)
    {
        int max = v[0][0];
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (max < v[i][j])
                {
                    max = v[i][j];
                    r = i;
                }
            }
        }

        return max;
    }

    int find_min_(vector<vector<int>> &v, int &r)
    {
        int min = v[0][0];
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (min > v[i][j])
                {
                    min = v[i][j];
                    r = i;
                }
            }
        }

        return min;
    }

    int find_max_(vector<vector<int>> &v, int r)
    {
        int max;
        if (r == 0)
        {
            max = v[1][0];
        }
        else
        {
            max = v[0][0];
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if ((max < v[i][j]) && (i != r))
                {
                    max = v[i][j];
                }
            }
        }

        return max;
    }

    int maxDistance(vector<vector<int>> &arrays)
    {
        int restrict;
        int max = find_max(arrays, restrict);
        int min = find_min(arrays, restrict);

        int min_ = find_min_(arrays, restrict);
        int max_ = find_max_(arrays, restrict);

        cout << min << " " << max;
        cout << min_ << " " << max_;

        if (max_ - min_ > max - min)
        {
            restrict = max_ - min_;
        }
        else
        {
            restrict = max - min;
        }

        return restrict;
    }
};

int main()
{

    return 0;
}